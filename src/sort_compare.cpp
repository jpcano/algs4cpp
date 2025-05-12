#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "sort_insertion.h"
#include "sort_selection.h"

double time(std::string alg, std::vector<double> a) {
  auto start = std::chrono::high_resolution_clock::now();
  if (alg == "Insertion") InsertionSort<double>::sort(a);
  if (alg == "Selection") SelectionSort<double>::sort(a);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  return duration.count() / 1e6;  // Convert to seconds
}

double timeRandomInput(std::string alg, int N, int T) {
  // Will be used to obtain a seed for the random number engine
  std::random_device rd;
  // Standard mersenne_twister_engine seeded with rd()
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0.0, 1.0);
  double total = 0.0;
  for (int i = 0; i < T; i++) {
    std::vector<double> a(N);
    for (int j = 0; j < N; j++) a[j] = dis(gen);
    /* SortBase<double>::show(a); */
    total += time(alg, a);
  }
  return total;
}

int main(int argc, char* argv[]) {
  if (argc != 5) {
    std::cerr << "Usage: " << argv[0] << " <algorithm 1> < algorithm 2 <N> <T>"
              << std::endl;
    return 1;
  }
  std::string alg1 = argv[1];
  std::string alg2 = argv[2];
  int N = std::stoi(argv[3]);
  int T = std::stoi(argv[4]);
  double t1 = timeRandomInput(alg1, N, T);
  double t2 = timeRandomInput(alg2, N, T);
  std::cout << "For " << N << " random doubles" << std::endl;
  std::cout << "  Time for " << alg1 << ": " << t1 << " seconds" << std::endl;
  std::cout << "  Time for " << alg2 << ": " << t2 << " seconds" << std::endl;
  std::cout << "  " << alg1 << " is " << t2 / t1 << " times faster than "
            << alg2 << std::endl;
  return 0;
}