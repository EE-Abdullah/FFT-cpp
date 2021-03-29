#include <Eigen/Dense>
#include <cmath>
#include "FFT.hpp"


int reverse(int b, int n)
{
    int k = 1;
    int A = b;
    int result = 0;
    int s = 0;
    int A_right = A;
    int A_left = A;
    while (n-k >= 0)
    {
        A_right = (int)(A >> n-k) & (int)(std::pow(2, n)-1) & (int)std::pow(2, s);
        A_left = (int)(A << n-k) & (int)(std::pow(2, n)-1) & (int)std::pow(2, n-1-s);
        result = result | A_left | A_right;
        s++;
        k += 2;
    }
    return result;
}


Eigen::VectorXcd order(Eigen::VectorXd& x_n)
{
    /*
    .................................
        FFT Order implementation.     
    .................................
    */

    int N = x_n.size();
    int n_bits = std::log2(N);
    Eigen::VectorXcd x_n_ord(N);
    int new_index = 0;
    for (int i=0; i<N; ++i)
    {
        new_index = reverse(i, n_bits);
        x_n_ord(i) = x_n(new_index);
    }
   return x_n_ord;
}


Eigen::VectorXcd computation(Eigen::VectorXcd&& x_seg_A, Eigen::VectorXcd&& x_seg_B, int N)
{
    /*
    .................................
        FFT Computation implementation.  
    .................................
    */
    int N_prev = x_seg_A.size();
    int N_next = N_prev * 2;
    int s = (int)std::log2(N_next);
    int W_length = std::pow(2, s-1);
    std::complex<double> W = std::polar(1.0, -2*M_PI/N);
    Eigen::VectorXcd W_K(W_length);
    int num_pairs = (int)(N/(std::pow(2, s)));
    W_K.setConstant(W);
    W_K = W_K.binaryExpr
    (
        Eigen::VectorXcd::LinSpaced(W_K.size(), 0, W_K.size()-1),
        [&]
        (
            std::complex<double> w_k,  std::complex<double> i
        )
            {
                return std::pow(w_k, num_pairs*i.real());
            }
    );
    Eigen::VectorXcd H_K = W_K.cwiseProduct(x_seg_B);
    Eigen::VectorXcd X_K(N_next);
    X_K.segment(0, W_length) = x_seg_A + H_K;
    X_K.segment(W_length, W_length) = x_seg_A - H_K;
   return X_K;
}


Eigen::VectorXcd segment(Eigen::VectorXcd& x_n_sort)
{
    /*
    .................................
        FFT Segmentation implementation.        Done.
    .................................
    */
    int N = x_n_sort.size();
    int total_stages = (int)std::log2(N);
    Eigen::VectorXcd X_K = x_n_sort;
    int num_pairs = 0;
    int index = 0;
    int input_chunk = 0;
    int output_chunk = 0;
    for (int s=1; s<=total_stages; ++s)  //  perform computation for each stage.
    {
        index = 0;
        input_chunk = (int)(std::pow(2, s-1));
        output_chunk = (int)(std::pow(2, s));
        num_pairs = (int)(N/(std::pow(2, s)));
        for (int i=1; i<=num_pairs; ++i)
        {
            X_K.segment(index, output_chunk) =
                computation
                (
                    X_K.segment(index, input_chunk),
                    X_K.segment(index+input_chunk, input_chunk),
                    N
                );
                index = index + output_chunk;
        }
    }
   return X_K;
}


Eigen::VectorXcd FFT(Eigen::VectorXd& x_n)
{
    /*
    .................................
        FFT Algorithm implementation.
    .................................
    */

    int N = x_n.size();

    Eigen::VectorXcd x_n_ord = order(x_n);
    Eigen::VectorXcd X_K = segment(x_n_ord);
   return X_K;
}
