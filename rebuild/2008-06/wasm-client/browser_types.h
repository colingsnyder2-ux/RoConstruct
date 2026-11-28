#pragma once
#include <cstdint>

// Browser platform must provide real per-thread storage before linking.
using DWORD = uint32_t;
extern "C" void* TlsGetValue(DWORD index);
extern "C" int TlsSetValue(DWORD index, void* value);
