import openturns as ot
import otmorris
from otmorris.plot_sensitivity import PlotEE
# Number of trajectories
r = 10
# Define experiments in [0,1]^20
# p-levels
p = 5
dim = 20
morris_experiment = otmorris.MorrisExperimentGrid([p] * dim, r)
bounds = ot.Interval(dim) # [0,1]^d
X = morris_experiment.generate()
f = ot.Function(otmorris.MorrisFunction())
Y = f(X)
# Evaluate Elementary effects (ee)
ee = otmorris.Morris(X, Y, bounds)
# Compute mu/sigma
mean = ee.getMeanAbsoluteElementaryEffects()
sigma = ee.getStandardDeviationElementaryEffects()
fig = PlotEE(ee)
fig.show()
