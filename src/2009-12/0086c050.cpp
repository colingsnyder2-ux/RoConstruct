// roc 2009-12 0086c050  unit: CXTPPropertyGridItemEnum  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086c050
//
// 0086c050  56                   push esi
// 0086c051  e8caffffff           call 0x86c020
// 0086c056  8bf0                 mov esi, eax
// 0086c058  8b460c               mov eax, dword ptr [esi + 0xc]
// 0086c05b  85c0                 test eax, eax
// 0086c05d  7413                 je 0x86c072
// 0086c05f  833e00               cmp dword ptr [esi], 0
// 0086c062  750e                 jne 0x86c072
// 0086c064  68d8fa9f00           push 0x9ffad8
// 0086c069  50                   push eax
// 0086c06a  ff1520b29800         call dword ptr [0x98b220]
// 0086c070  8906                 mov dword ptr [esi], eax
// 0086c072  8b36                 mov esi, dword ptr [esi]
// 0086c074  85f6                 test esi, esi
// 0086c076  741f                 je 0x86c097
// 0086c078  8b442418             mov eax, dword ptr [esp + 0x18]
// 0086c07c  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0086c080  8b542410             mov edx, dword ptr [esp + 0x10]
// 0086c084  50                   push eax
// 0086c085  8b442410             mov eax, dword ptr [esp + 0x10]
// 0086c089  51                   push ecx
// 0086c08a  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0086c08e  52                   push edx
// 0086c08f  50                   push eax
// 0086c090  51                   push ecx
// 0086c091  ffd6                 call esi
// 0086c093  5e                   pop esi
// 0086c094  c21400               ret 0x14
// 0086c097  b805400080           mov eax, 0x80004005
// 0086c09c  5e                   pop esi
// 0086c09d  c21400               ret 0x14
// copied from an identical function in another client (function ?step@Kernel@ns_ROCX000007@ns_ROCX0000d8@@QAEHHHHHH@Z)

namespace ns_ROCX000007 {
struct S_func_007611c0 {

    unsigned int f(int a1, int a2, int a3);
};
unsigned int S_func_007611c0::f(int a1, int a2, int a3)
{
    return 0x80004001u;
}
}
