#!/usr/bin/env python

from __future__ import print_function
import openturns as ot
import otmorris

# Define model
model = ot.NumericalMathFunction(["x","y"], ["sin(2*_pi*x)+y"])

# Use Case 1 : starting from an LHS or optimized space filling LHS
# Initial LHS design
x = ot.LHSExperiment(ot.ComposedDistribution(2*[ot.Uniform(0,1)]), 5).generate()
# Number of trajectories
r = 4

# First generate designs
morris_experiment = otmorris.MorrisExperiment(x, r, ot.Interval(2))

# Generate sample of size (p+1)*r where p is input dimension
X = morris_experiment.generate()
# Evaluation of the model on the design: evaluation outside OT
Y = model(X)

# Use Case 2 : define a k-grid level (so delta = 1/(k-1))
k = 5
morris_experiment = otmorris.MorrisExperiment(k, r, ot.Interval(2))
X = morris_experiment.generate()
# Evaluation of the model on the design: evaluation outside OT
Y = model(X)

# Evaluation of Morris effects
morris = otmorris.Morris(X, Y)

# Get mean/sigma effects
mean_effects = morris.getMeanEffects()
sigma_effects = morris.getStandardDeviationEffects()
# Plot effects
fig = otmorris.plot(morris)

