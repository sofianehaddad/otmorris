Examples
========

This section illustrates how to use the module to evaluate the Morris screening effects.

The illustration is done with the `Morris` function example, with f: :math:`f:\Rset^{20} \rightarrow \Rset`. Each input variable is uniform with bounds 0 and 1.

Example 1: Generating trajectories from a regular grid
------------------------------------------------------

To define the trajectories, we suppose that the box :math:`[0,1]^{20}` is splitted into a p-level grid (p=5)
We set the number of trajectories input variables are randomly to 10.

.. literalinclude:: example.py
    :language: python

We illustrate here after sensitivity graph issued from such analysis:
