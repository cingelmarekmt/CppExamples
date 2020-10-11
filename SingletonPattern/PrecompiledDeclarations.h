#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>
#include <thread>
#include <mutex>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))
