#include <Eigen/Dense>
#include <vector>
#include "include/FFT.hpp"
#include "include/matplotlibcpp.h"

namespace plt = matplotlibcpp;


int main()
{
    double fm = 10e1;   // Continuous Time input signal's frequency.
    double fs = 10240;  // Sampling Frequency.
    double duration = 6*(1/fm); // sampling the input signal for 3 periods.
    int N = (int)(duration * fs);    // input sequence's length as a function of duration,
                                     // signal's period and sampling frequency.


    // duration correction such that the new length N is a power of 2.
    int log2N = (int)std::log2(N);
    int diff = N-std::pow(2, log2N);
    N = std::pow(2, log2N);
    double fraction = diff/(duration*fs);
    double cor_duration = duration-fraction*duration;

    // signal generation..
    Eigen::VectorXd x_n(N);     // Input Sequence.
    Eigen::VectorXd t(N);       // time vector.
    Eigen::VectorXd K(N);       // Index Vector K.
    Eigen::VectorXd f(N);       // Frequency Vector f.
    Eigen::VectorXcd X_K(N);    // Output N-point DFT in terms of index 'K'.
    Eigen::VectorXcd X_f(N);    // Output N-point DFT in terms of frequency 'f'.
    t.setLinSpaced(0, cor_duration);    // N floating point time samples over the period [0, duration].
    K.setLinSpaced(0, N-1);     // N interger samples over the period [0, N-1].
    f = K * fs/N;   //  Conversion from index to frequency.
    x_n = (2 * M_PI * fm * t).array().sin();  // sampling the continuous time signal x(t) = sin(2*pi*fm*t).
                                              // such that x[n] = x(t=nTs), n = [0, N-1] & Ts = 1/fs.  
    X_K = FFT(x_n);    // Output Sequence.
    X_f = X_K/N;       // Magnitude Correction.



    // Plotting using matplotlib

    Eigen::VectorXd mag = X_f.unaryExpr([](std::complex<double> c){return std::abs(c);}); // magnitude only.
    std::vector<double> f_std(f.data(), f.data()+f.size());     // convert Eigen vector to std vector
    std::vector<double> X_f_std(mag.data(), mag.data()+mag.size()); // convert Eigen vector to std vector

    std::vector<double> t_std(t.data(), t.data()+t.size());     // convert Eigen vector to std vector
    std::vector<double> x_n_std(x_n.data(), x_n.data()+x_n.size()); // convert Eigen vector to std vector

    // plotting results.

    //time domain
    plt::figure_size(1200, 800);
    plt::subplot(2,1,1);
    plt::plot(t_std, x_n_std);
    plt::grid(true);
    plt::title("x(t)");
    plt::xlabel("time(s)");
    plt::ylabel("Amplitude(V)");

    
    //frequency domain
    plt::subplot(2,1,2);
    plt::plot(f_std, X_f_std);
    plt::grid(true);
    plt::title("|X(f)|");
    plt::xlabel("frequency(Hz)");
    plt::ylabel("Magnitude");


    plt::tight_layout();
    plt::show();
    return 0;
}