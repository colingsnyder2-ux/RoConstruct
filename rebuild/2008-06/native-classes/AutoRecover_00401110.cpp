// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the target is unnamed (func_00401110), so it is defined as fn_00401110 with C linkage.
// INFERRED: in the vendor source this is G3D::MemoryManager::free(void*). It is a thiscall member
// that never uses `this`, which is why the code reads its only argument from [esp+4] and ends
// with ret 4. A __stdcall function with one argument produces the same code.
// INFERRED: the callee ??3@YAXPAX@Z is ::operator delete(void*).
#include <new>
#include <stddef.h>

extern "C" void __stdcall fn_00401110(void* ptr) {
    ::operator delete(ptr);
}
