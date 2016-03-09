// SWIG file

%{
#include "otmorris/Morris.hxx"
%}

%include Morris_doc.i

%include otmorris/Morris.hxx
namespace OTMORRIS { %extend Morris { Morris(const Morris & other) { return new OTMORRIS::Morris(other); } } }

%pythoncode %{

import openturns as ot
import numpy as np

class MorrisFunction(ot.OpenTURNSPythonFunction):
    """
    The non-monotonic function of Morris f: R^20 -> R

    Reference:
      M. D. Morris, 1991, Factorial sampling plans for preliminary
      computational experiments,Technometrics, 33, 161--174.

    Examples
    --------
    >>> ot.RandomGenerator.SetSeed(123)
    >>> b0 = ot.DistFunc.rNormal()
    >>> alpha = ot.DistFunc.rNormal(10)
    >>> beta =  ot.DistFunc.rNormal(6*14)
    >>> gamma =  ot.DistFunc.rNormal(20*14)
    >>> f = ot.NumericalMathFunction( MorrisFunction(alpha, beta, gamma, b0) )
    >>> input_sample = ot.ComposedDistribution([ot.Uniform(0,1)] * 20).getSample(20)
    >>> output_sample = f(input_sample)

    """
    def __init__(self, alpha = ot.NumericalPoint(10), beta = ot.NumericalPoint(14*6),\
                 gamma = ot.NumericalPoint(20*14), b0 = 0.0):
        ot.OpenTURNSPythonFunction.__init__(self, 20, 1)
        self.b0 = float(b0)
        # Check alpha dimension
        assert(len(np.array(alpha).reshape(-1)) == 10)
        self.b1 = np.concatenate((np.repeat(20,10), np.array(alpha).reshape(-1,)))
        # Check beta and gamma dimension
        assert(len(np.array(beta).reshape(-1)) == 6 * 14)
        assert(len(np.array(gamma).reshape(-1)) == 20 * 14)
        self.b2 = np.concatenate( (np.concatenate( (np.array([[-15]*6]*6), np.array(beta).reshape(6,14)), axis=1),
                                   np.array(gamma).reshape(14,20)))
        self.b3 = np.ndarray((20,)*3)
        self.b3.fill(0)
        self.b3[0 : 5, 0 : 5, 0 : 5] = - 10
        self.b4 = np.ndarray((20,) * 4)
        self.b4.fill(0)
        self.b4[0 : 4, 0 : 4, 0 : 4, 0 : 4] = 5

    def _exec(self, x):
        assert (len(x)==20)
        b1 = self.b1
        b2 = self.b2
        b3 = self.b3
        b4 = self.b4
        # X is a list, transform it into array
        X = np.array(x)
        w = 2.0 * (X - 0.5)
        w = w.reshape(20,)
        w[[2, 4, 6]] = 2.0 * (1.1 * X[[2, 4, 6]] / (X[[2, 4, 6]] + .1) - 0.5)
        y = 0.0
        y = np.dot(b1 , w)
        # Morris function
        for i in range(19):
            for j in range(i + 1, 20):
                y +=  b2[i, j] * w[i] * w[j]
        for i in range(18):
            for j in range(i + 1, 19):
                for k in range(j + 1, 20):
                    y += b3[i, j, k] * w[i] * w[j] * w[k]

        for i in range(17):
            for j in range(i + 1, 18):
                for k in range(j + 1, 20):
                    for l in range(k + 1, 20):
                        y += b4[i, j, k, l] * w[i] * w[j] * w[k] * w[l]

        return [y + self.b0]
%}
