import openturns as ot
import otmorris
from otmorris.plot_sensitivity import PlotEE
# Number of trajectories
r = 10
# Define an LHS experiment of size 50
lhsSize = 50
bounds = ot.Interval(20)
lhsDesign = otmorris.MorrisExperimentLHS.GenerateLHS(bounds, lhsSize)
morris_experiment = otmorris.MorrisExperimentLHS(lhsDesign, r)

X = morris_experiment.generate()
f = ot.Function(otmorris.MorrisFunction())
Y = f(X)
# Evaluate Elementary effects (ee)
ee = otmorris.Morris(X, Y)
# Compute mu/sigma
mean = ee.getMeanAbsoluteElementaryEffects()
sigma = ee.getStandardDeviationElementaryEffects()
fig = PlotEE(ee, title="Elementary Effects using LHS")
fig.show()

