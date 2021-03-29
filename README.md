# FFT-cpp

Fourier Analysis is one of the most important tools used in signal processing.
This work is merely an implementation of the Fast Fourier Transform Algorithm 
which is used to compute the Discrete Fourier Transform more efficiently.
Compared to the original DFT computation, the FFT Algorithm has a computational complexity
that is in the order of Nlog2(N). i.e.: O(Nlog2(N)).
Whilst the DFT is in the order of N^2. i.e.: O(N^2)

### Prerequisites

The following are the required dependencies:

```
1-std library
2-Eigen library
3-Matplotlibcpp(optional)
4-Python3(optional)(required for matplotlibcpp)
```

## Running the tests

compile the main.cpp file with FFT.cpp using:
```
g++ main.cpp src/FFT.cpp -I<path to python3.6m> -lpython3.6m
```
in my machine:
```
g++ main.cpp src/FFT.cpp -I/usr/include/python3.6m -lpython3.6m
```

## Built With

* [Eigen](http://eigen.tuxfamily.org) - For Linear Algebra.
* [matplotlibcpp](https://matplotlib-cpp.readthedocs.io/en/latest) - plotting and visualization.


## Acknowledgments

* [Professor Alan V. Oppenheim](https://en.wikipedia.org/wiki/Alan_V._Oppenheim) - Inspired By.
* Eigen docs
* Matplotlib

