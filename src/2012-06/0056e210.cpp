// from server: 100% by Xemicl
// roc 2012-06 0056e210  unit: RBX::Network::IdSerializer  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0056e210
//
// 0056e210  51                   push ecx
// 0056e211  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0056e215  8d0424               lea eax, [esp]
// 0056e218  50                   push eax
// 0056e219  51                   push ecx
// 0056e21a  c7442408c2000000     mov dword ptr [esp + 8], 0xc2
// 0056e222  e8b9dbffff           call 0x56bde0
// 0056e227  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0056e22b  83c408               add esp, 8
// 0056e22e  83790400             cmp dword ptr [ecx + 4], 0
// 0056e232  7409                 je 0x56e23d
// 0056e234  8d1424               lea edx, [esp]
// 0056e237  52                   push edx
// 0056e238  e823fbffff           call 0x56dd60
// 0056e23d  59                   pop ecx
// 0056e23e  c3                   ret 
// copied from an identical function in another client (function ?f@ns_ROCX00000f@@YAXPAUS@1@PAX@Z)

namespace ns_ROCX00000f {
struct S {
    int reserved;
    int enabled;
    void apply(int*);
};

extern void __cdecl helper(void*, int*);

void __cdecl f(S* object, void* source)
{
    int value = 194;
    helper(source, &value);
    if (object->enabled != 0)
        object->apply(&value);
}
}
