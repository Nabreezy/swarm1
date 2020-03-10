# Partical Swarm Optimization

[![N|Solid](https://cldup.com/dTxpPi9lDf.thumb.png)](https://nodesource.com/products/nsolid)

[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)

The goal of this Project was to implemetn the following Algorithm with C++ and solve as many optimization problems as possible using Benchmark Functions and figure out the 
results.

The following are the Benchmark functions that have been used 

![alt text](https://raw.githubusercontent.com/Nabreezy/swarm1/master/Benchmark%20Functions.PNG)


### The pseudo code of the procedure for the code is as follows
- For each particle
  - Initialize particle
  - END
- Do
  - For each particle
  - Calculate fitness value
  - If the fitness value is better than the best fitness value (pBest) in history
            set current value as the new pBest
  - End

- Choose the particle with the best fitness value of all the particles as the gBest
  - For each particle
  - Calculate particle velocity according equation (a)
  - Update particle position according equation (b)
  - End
- While maximum iterations or minimum error criteria is not attained


License
----

MIT


**Free Software, Hell Yeah!**

