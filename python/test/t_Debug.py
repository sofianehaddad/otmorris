import openturns as ot
import otmorris
X = ot.LHSExperiment(ot.ComposedDistribution([ot.Uniform(0,1)]*4), 50, False, False).generate()
morris_experiment = otmorris.MorrisExperimentLHS(X, 10)
Y = morris_experiment.generate()
print(Y)
