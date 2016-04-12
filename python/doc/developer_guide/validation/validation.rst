Validation
==========

Morris Test case
----------------

The purpose here is to estimate the elementary effects on the Morris Use Case and compare issued results with litterature and other sensitivity tools.
As the Morris method is a screening, the validation relies on graphical observations.

1- Problem statement
````````````````````
The objective is to compute absolute mean and standard deviation of elementary effects, observed with r=10 trajectories.
From these values, graphical observations lets define several groups (at least 3):

 - A group with variables that have negligible effects on the output,
 - A group with variables that have linear effects on the output,
 - A group with variables that have significant and non linear (or with interactions) effects on the output.

We recall that with the Morris use case, all variables are independent and uniform in [0,1].
Also, some parameters of the model are supposed to be gaussian with parameters :math:`\mu=0, \sigma=1`.
We fix however these variables to be equal to 1e-3.


2- Analysis
```````````

a- Inputs
'''''''''

======== ======= ======= ====
Variable Min     Max     Step
======== ======= ======= ====
Q        10033.1 10364.6 100
E        2975    3024.99 15
C        3901.33 4097.74 60
======== ======= ======= ====

b- Results
''''''''''

===== ==== ==== =======
Q     E    C    Ep 
===== ==== ==== =======
10030 2975 3900 0.06035
10365 2995 4100 0.05456
===== ==== ==== =======


