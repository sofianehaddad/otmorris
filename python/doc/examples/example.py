import openturns as ot
import otmorris
from otmorris.plot_sensitivity import PlotEE
# Number of trajectories
r = 10
# Define experiments in [0,1]^20
# p-levels
p = 5
morris_experiment = otmorris.MorrisExperiment([p] * 20, r)
X = morris_experiment.generate()
f = ot.Function(otmorris.MorrisFunction())
Y = f(X)
# Evaluate Elementary effects (ee)
ee = otmorris.Morris(X, Y)
# Compute mu/sigma
mean = ee.getMeanAbsoluteElementaryEffects()
sigma = ee.getStandardDeviationElementaryEffects()
fig = PlotEE(ee)
fig.show()

