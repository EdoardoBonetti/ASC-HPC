#include <iostream>
#include <sstream>


#include <simd.h>

using namespace ASC_HPC;
using std::cout, std::endl;

auto Func1 (SIMD<double> a, SIMD<double> b)
{
  return a+b;
}

auto Func2 (SIMD<double,4> a, SIMD<double,4> b)
{
  return a+3*b;
}

auto Func3 (SIMD<double,4> a, SIMD<double,4> b, SIMD<double,4> c)
{
  return FMA(a,b,c);
}

auto ForLoop(size_t n, SIMD<double, 4> *x, SIMD<double, 4> *y, SIMD<double, 4> *z)
{
  for (int i = 0; i < n; i++)
    z[i] = x[i] + y[i];
}

auto InnerProduct(size_t n, SIMD<double, 4> *x, SIMD<double, 4> *y)
{
  SIMD<double, 4> sum(0.);
  for (int i = 0; i < n; i++)
    sum = sum + x[i] * y[i];
  return sum;
}

int main()
{
  SIMD<double,4> a(1.,2.,3.,4.);
  SIMD<double,4> b(1.0);
  
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "a+b = " << a+b << endl;
}
