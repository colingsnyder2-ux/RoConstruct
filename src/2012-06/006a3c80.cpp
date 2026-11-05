// roc 2012-06 006a3c80  unit: RBX::VScriptContext::?$FactoryProduct  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006a3c80
//
// 006a3c80  56                   push esi
// 006a3c81  8b742408             mov esi, dword ptr [esp + 8]
// 006a3c85  57                   push edi
// 006a3c86  6a00                 push 0
// 006a3c88  6a02                 push 2
// 006a3c8a  56                   push esi
// 006a3c8b  e890fc1800           call 0x833920
// 006a3c90  8bf8                 mov edi, eax
// 006a3c92  a1d813de00           mov eax, dword ptr [0xde13d8]
// 006a3c97  50                   push eax
// 006a3c98  6a01                 push 1
// 006a3c9a  56                   push esi
// 006a3c9b  e870fb1800           call 0x833810
// 006a3ca0  56                   push esi
// 006a3ca1  57                   push edi
// 006a3ca2  50                   push eax
// 006a3ca3  e8386a1900           call 0x83a6e0
// 006a3ca8  83c424               add esp, 0x24
// 006a3cab  5f                   pop edi
// 006a3cac  33c0                 xor eax, eax
// 006a3cae  5e                   pop esi
// 006a3caf  c3                   ret 
// copied from an identical function in another client (function ?sub_535140@ns_ROCX000005@@YAHH@Z)

namespace ns_ROCX000005 {
extern "C" int __cdecl sub_5BF350(int, int, int);
extern "C" int __cdecl sub_5BF240(int, int, int);
extern "C" int __cdecl sub_56C740(int, int, int);

extern int dword_8ABE80;

int __cdecl sub_535140(int a)
{
    int v1 = sub_5BF350(a, 2, 0);
    int v2 = sub_5BF240(a, 1, dword_8ABE80);
    sub_56C740(v2, v1, a);
    return 0;
}
}
