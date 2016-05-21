#ifndef HXX_HPP
#define HXX_HPP

#include <initializer_list>
#include <random>
#include <utility>
#include <vector>
using std::initializer_list;
using std::pair;
using std::ranlux48;
using std::uniform_real_distribution;
using std::vector;

void hxx_viterbi (vector<int>::const_iterator O_it,
                  vector<int>::const_iterator O_last,
                  initializer_list<double> A,
                  initializer_list<double> B,
                  initializer_list<double> Pi,
                  vector<int>& q_star);

void hxx_viterbi (vector<int>::const_iterator O_it,
                  vector<int>::const_iterator O_last,
                  const vector<double> A,
                  const vector<double> B,
                  const vector<double> Pi,
                  vector<int>& q_star);

class hxx_gen {
public:
    hxx_gen (initializer_list<double> A, initializer_list<double> B, initializer_list<double> Pi);
    pair<int, int> operator()();
private:
    vector<double> a;
    vector<double> b;
    vector<double> p;
    int N; // Number of states.
    int M; // Number of distinct observation symbols.
    int t;
    int q; // Hidden state at time t.
    ranlux48 reng;
    uniform_real_distribution<> urd;
};

double hxx_forward (vector<int>::const_iterator, vector<int>::const_iterator,
                    initializer_list<double> A, initializer_list<double> B, initializer_list<double> Pi);
#endif // HXX_HPP
