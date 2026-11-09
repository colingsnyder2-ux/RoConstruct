// roc 2012-06 0065ff90  unit: seg_00650000  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0065ff90
//
// 0065ff90  8b442408             mov eax, dword ptr [esp + 8]
// 0065ff94  50                   push eax
// 0065ff95  ff15c829b200         call dword ptr [0xb229c8]
// 0065ff9b  59                   pop ecx
// 0065ff9c  c3                   ret 
// copied from an identical function in another client (function ?f@ns_ROCX000012@@YAXPAX0@Z)

namespace ns_ROCX000012 {
extern "C" __declspec(dllimport) void free(void* ptr);

void f(void* a, void* b) {
    free(b);
}
}
