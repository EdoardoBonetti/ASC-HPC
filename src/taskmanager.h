#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <array>
#include <chrono>
#include <mutex>
#include <thread>
#include <functional>
#include <algorithm>

namespace ASC_HPC
{
  
  void StartWorkers(int num);
  void StopWorkers();
  
  void RunParallel (int num,
                    const std::function<void(int nr, int size)> & func);
  
}



#endif
