#pragma once
// 2008-06 provider selection: preserve donor support declarations under a
// distinct name, then expose the byte/layout-proved 2008 ContentProvider.
#define ContentProvider DonorContentProvider
#include "../../../../tools/rbxgs/Client/App/include/util/ContentProvider.h"
#undef ContentProvider
#include "util/NativeContentProvider.h"
