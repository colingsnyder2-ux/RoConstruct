// roc 2012-06 0065ffa0  unit: seg_00650000  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0065ffa0
//
// 0065ffa0  8b442408             mov eax, dword ptr [esp + 8]
// 0065ffa4  50                   push eax
// 0065ffa5  ff15f829b200         call dword ptr [0xb229f8]
// 0065ffab  83c404               add esp, 4
// 0065ffae  c3                   ret 
// copied from an identical function in another client (function ?f@ns_ROCX000011@@YAPAXHI@Z)

namespace ns_ROCX000011 {
extern "C" void* (__cdecl *malloc_ptr)(unsigned int);

void* f(int unused, unsigned int size)
{
    return malloc_ptr(size);
}
}
