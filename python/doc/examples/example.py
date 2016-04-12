import openturns as ot
import otmorris
from otmorris.functions import MorrisFunction
from otmorris.plot_sensitivity import PlotEE
# Number of trajectories
r = 10
# Define experiments in [0,1]^20
# p-levels
p = 5
morris_experiment = otmorris.MorrisExperiment([p] * 20, r)
X = morris_experiment.generate()
f = ot.NumericalMathFunction(MorrisFunction())
Y = f(X)
# Evaluate Elementary effects (ee)
ee = otmorris.Morris(X, Y)
# Compute mu/sigma
mean = ee.getMeanAbsoluteElementaryEffects()
sigma = ee.getSigmaElementaryEffects()
fig = Plot(EE)
fig.show()

