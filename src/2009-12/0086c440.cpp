// roc 2009-12 0086c440  unit: CXTCaptionButton  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086c440
//
// 0086c440  56                   push esi
// 0086c441  57                   push edi
// 0086c442  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0086c446  8bf1                 mov esi, ecx
// 0086c448  83ff1a               cmp edi, 0x1a
// 0086c44b  7405                 je 0x86c452
// 0086c44d  83ff15               cmp edi, 0x15
// 0086c450  751c                 jne 0x86c46e
// 0086c452  e819540700           call 0x8e1870
// 0086c457  8b10                 mov edx, dword ptr [eax]
// 0086c459  8bc8                 mov ecx, eax
// 0086c45b  8b4204               mov eax, dword ptr [edx + 4]
// 0086c45e  ffd0                 call eax
// 0086c460  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0086c463  6a00                 push 0
// 0086c465  6a00                 push 0
// 0086c467  51                   push ecx
// 0086c468  ff15e8cb9800         call dword ptr [0x98cbe8]
// 0086c46e  8b542418             mov edx, dword ptr [esp + 0x18]
// 0086c472  8b442414             mov eax, dword ptr [esp + 0x14]
// 0086c476  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0086c47a  52                   push edx
// 0086c47b  50                   push eax
// 0086c47c  51                   push ecx
// 0086c47d  57                   push edi
// 0086c47e  8bce                 mov ecx, esi
// 0086c480  e89b930700           call 0x8e5820
// 0086c485  5f                   pop edi
// 0086c486  5e                   pop esi
// 0086c487  c21000               ret 0x10
// copied from an identical function in another client (function ?sub_69F420@CXTCaptionButton@ns_ROCX000001@ns_ROCX000098@@QAEXHHHH@Z)

namespace ns_ROCX000001 {
extern void G1_func_0075fce0();
void fn_ROCX000001()
{
    G1_func_0075fce0();
}
}
