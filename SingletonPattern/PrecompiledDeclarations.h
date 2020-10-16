#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>
#include <thread>
#include <mutex>
#include <chrono>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))
