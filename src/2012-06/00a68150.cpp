// roc 2012-06 00a68150  unit: CXTShadowHook  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a68150
//
// 00a68150  e8ebffffff           call 0xa68140
// 00a68155  85c0                 test eax, eax
// 00a68157  7403                 je 0xa6815c
// 00a68159  33c0                 xor eax, eax
// 00a6815b  c3                   ret 
// 00a6815c  e8ef60f8ff           call 0x9ee250
// 00a68161  33c9                 xor ecx, ecx
// 00a68163  398844010000         cmp dword ptr [eax + 0x144], ecx
// 00a68169  0f94c1               sete cl
// 00a6816c  8bc1                 mov eax, ecx
// 00a6816e  c3                   ret 
// copied from an identical function in another client (function ?sub_7125a0@ns_ROCX00005d@@YAHXZ)

namespace ns_ROCX00005d {
extern "C" int __cdecl sub_712590();
extern "C" char *__cdecl sub_6978f0();

int sub_7125a0()
{
    if (sub_712590())
        return 0;
    char *p = sub_6978f0();
    return *(int *)(p + 0x144) == 0;
}
}
