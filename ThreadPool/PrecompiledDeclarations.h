#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>

#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>

#include <functional>
#include <mutex>
#include <thread>
#include <future>

#include <chrono>
#include <numeric>
#include <algorithm>

#include <vector>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <windows.h>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))
