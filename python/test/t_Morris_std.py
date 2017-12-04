#!/usr/bin/env python

from __future__ import print_function
import openturns as ot
import otmorris

# Define model
ot.RandomGenerator.SetSeed(0)
# Number of trajectories
r = 5
# Define experiments in [0,1]^2
print("Use Case #1 : generate trajectories from regular grid")
levels = ot.Indices(2)
levels.fill(5,0)
morris_experiment = otmorris.MorrisExperimentGrid(levels, r)
sample1 = morris_experiment.generate()
print("Morris experiment generated from grid = ", sample1)

print("Use Case #2 : generate trajectories from initial lhs design")
size = 20
# Generate an LHS design
dist = ot.ComposedDistribution(2*[ot.Uniform(0,1)])
experiment = ot.LHSExperiment(dist, size, True, False)
lhsDesign = experiment.generate()
print( "Initial LHS design = ", lhsDesign)
# Generate designs
morris_experiment_lhs = otmorris.MorrisExperimentLHS(lhsDesign, r)
sample2 = morris_experiment.generate()
print("Morris experiment generated from LHS = ", sample2 )

# Define model
model = ot.SymbolicFunction(["x","y"], ["cos(x)*y + sin(y)*x + x*y -0.1"])

# Define Morris method with two designs
morrisEE1 = otmorris.Morris(sample1, model(sample1))
morrisEE2 = otmorris.Morris(sample2, model(sample2))
print( "Using level grid, E(|EE|)  = " , morrisEE1.getMeanAbsoluteElementaryEffects())
print( "                  V(|EE|)^{1/2} = ", morrisEE1.getStandardDeviationElementaryEffects())

print( "Using initial LHS, E(|EE|)  = ", morrisEE2.getMeanAbsoluteElementaryEffects())
print( "                   V(|EE|)^{1/2} = " , morrisEE2.getStandardDeviationElementaryEffects())
