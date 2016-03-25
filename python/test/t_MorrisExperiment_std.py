#! /usr/bin/env python

from __future__ import print_function
import openturns as ot
import otmorris

ot.RandomGenerator.SetSeed(1)

# Use Case 1 : define a k-grid level (so delta = 1/(k-1))
r = 5
# Define experiments in [0,1]^2
morris_experiment = otmorris.MorrisExperiment([3, 3], r)
X = morris_experiment.generate()
print("Morris experiment generated from grid = ", X)

# Use Case 2 : starting from an LHS
lhsExperiment = ot.LHSExperiment(ot.ComposedDistribution(2*[ot.Uniform(0,1)]), 5).generate()
# Number of trajectories
r = 5

# First generate designs
morris_experiment = otmorris.MorrisExperiment(lhsExperiment, r)
X = morris_experiment.generate()
print("Morris experiment generated from LHS = ", X)

