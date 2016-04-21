#!/usr/bin/env python

from __future__ import print_function
import openturns as ot
import otmorris
from otmorris.functions import MorrisFunction

# Define model
ot.RandomGenerator.SetSeed(1)
alpha = ot.DistFunc.rNormal(10)
beta = ot.DistFunc.rNormal(84)
gamma = ot.DistFunc.rNormal(280)
b0 = ot.DistFunc.rNormal()

model = MorrisFunction(alpha, beta, gamma, b0)

# Number of trajectories
r = 5
# Define a k-grid level (so delta = 1/(k-1))
k = 5
morris_experiment = otmorris.MorrisExperiment([k] * 20, r)
X = morris_experiment.generate()
# Evaluation of the model on the design: evaluation outside OT
Y = model(X)

# Evaluation of Morris effects
morris = otmorris.Morris(X, Y)

print("Morris use case")
print("Number of trajectories = ", r)

# Get mean/sigma effects
mean_effects = morris.getMeanElementaryEffects()
mean_abs_effects = morris.getMeanAbsoluteElementaryEffects()
sigma_effects = morris.getStandardDeviationElementaryEffects()

print("Elementary effects")
print("Mean = ", mean_effects)
print("Abs mean = ", mean_abs_effects)
print("Sigma = ", sigma_effects)

