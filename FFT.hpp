#include <Eigen/Dense>
#include <cmath>


#ifndef FFT_HPP
#define FFT_HPP


int reverse(int b, int n);
     /*
    .................................
        Input indices bit reversal implementation.
    .................................
    */


Eigen::VectorXcd sort(Eigen::VectorXd& x_n);
     /*
    .................................
        FFT sort implementation.               
    .................................
    */


Eigen::VectorXcd computation
(
    Eigen::VectorXcd&& x_seg_A,
    Eigen::VectorXcd&& x_seg_B, int N
);
    /*
    .................................
        N-point DFT Computation implementation.
    .................................
    */


Eigen::VectorXcd segment(Eigen::VectorXcd& x_n_sort);
    /*
    .................................
        FFT Segmentation implementation.
    .................................
    */


Eigen::VectorXcd FFT(Eigen::VectorXd& x_n);
    /*
    .................................
        FFT Algorithm implementation.
    .................................
    */


#endif