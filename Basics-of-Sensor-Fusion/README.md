# Course Assignments for Basics of Sensor Fusion

## Overview
This directory contains the assignments for ELEC-E8740 Basics of Sensor Fusion course offered at Aalto University, 2023.

## Assignments
- **HW1.pdf**: state-space model of a drone
- **HW2.pdf**: calculating the variance of a Gaussian distribution analytically using brute-force integration methods.
- **HW3.pdf**: computing least squares estimators for parameters in a linear model by minimizing a cost function, both directly and by transforming it into a matrix form for optimization
- **HW4.ipynb**: implementing the gradient descent algorithm to minimize a quadratic cost function, with a focus on empirically testing how different step sizes affect the speed of convergence
- **HW5.ipynb**: implementing the Gauss-Newton method with an exact line search on a predefined grid to minimize a non-linear cost function
- **HW6.ipynb**: solving differential equation analytically and numerically using Euler's method and Python’s odeint solver.
- **HW7.ipynb**: analyzing the motion of a 2D robot by implementing its dynamics using the Euler method to visually confirm the expected trajectory
- **HW8.ipynb**: solving a scalar differential equation by discretizing the model using zeroth-order-hold approximation, implementing the solution, and comparing it with the output from Python’s odeint solver to validate accuracy at the discretization points
- **HW9.ipynb**: simulating a 1D Gaussian random walk, applying a Kalman filter to process noisy measurements, and evaluating the performance of the Kalman filter against raw measurements using the root mean square error metric
- **HW10.ipynb**: simulating a 1D non-linear system, verifying the analytical derivatives with numerical finite differences, and implementing an Extended Kalman Filter to estimate the system's states from noisy measurements
