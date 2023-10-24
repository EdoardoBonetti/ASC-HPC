#include <iostream>
#include <sstream>


#include <taskmanager.h>
#include <timer.h>

using namespace ASC_HPC;
using std::cout, std::endl;


int main()
{
  timeline = std::make_unique<TimeLine>("demo.trace");

  StartWorkers(3);

  RunParallel(
      1000, [](int i, int size)
      {
        static Timer t("timer one");
        RegionTimer reg(t);
        cout << "I am task " << i << " out of " << size << endl; });

  RunParallel(6, [] (int i, int s)
  {
    RunParallel(6, [i] (int j, int s2)
    {
      std::stringstream str;
      str << "nested, i,j = " << i << "," << j << "\n";
      cout << str.str();
    });
  });



  
  RunParallel(100,  [] (int i, int size)
  {
    static Timer t("timer two", { 0, 0, 1});
    RegionTimer reg(t);
  });

  RunParallel(1000,  [] (int i, int size)
  {
    static Timer t("timer 3", { 1, 0, 0});
    RegionTimer reg(t);
  });

  RunParallel(100, [] (int i, int s)
  {
    static Timer t("timer 4", { 1, 1, 0});
    RegionTimer reg(t);    
    RunParallel(100, [i](size_t j, size_t s2)
    {
      ;
    });
  });


  
  StopWorkers();
}

