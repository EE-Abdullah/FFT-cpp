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
2-Eigen library(Added to repository)
3-Matplotlibcpp(optional)
4-Python3(optional)(required for matplotlibcpp)
```

## Sample Output

input signal is sin function of frequency of 100 Hz, sampling frequency is 10240 Hz.

the input signal has been sampled for 6 periods.

Both (time/frequency)-domain representations of the input signal is depicted in the figure below
![alt text](https://github.com/EE-Abdullah/FFT-cpp/blob/master/sample.png)
## Running the tests

### Using CMake
clone this repository then switch to it's root directory and run the following commands:

```
mkdir build && cd build
cmake ..
cmake --build .
./program
```
### Using GCC
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

