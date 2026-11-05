// roc 2009-12 008e5820  unit: CXTColorSelectorCtrl  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e5820
//
// 008e5820  56                   push esi
// 008e5821  57                   push edi
// 008e5822  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008e5826  8bf1                 mov esi, ecx
// 008e5828  83ff1a               cmp edi, 0x1a
// 008e582b  7405                 je 0x8e5832
// 008e582d  83ff15               cmp edi, 0x15
// 008e5830  751c                 jne 0x8e584e
// 008e5832  e839c0ffff           call 0x8e1870
// 008e5837  8b10                 mov edx, dword ptr [eax]
// 008e5839  8bc8                 mov ecx, eax
// 008e583b  8b4204               mov eax, dword ptr [edx + 4]
// 008e583e  ffd0                 call eax
// 008e5840  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 008e5843  6a00                 push 0
// 008e5845  6a00                 push 0
// 008e5847  51                   push ecx
// 008e5848  ff15e8cb9800         call dword ptr [0x98cbe8]
// 008e584e  8b542418             mov edx, dword ptr [esp + 0x18]
// 008e5852  8b442414             mov eax, dword ptr [esp + 0x14]
// 008e5856  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008e585a  52                   push edx
// 008e585b  50                   push eax
// 008e585c  51                   push ecx
// 008e585d  57                   push edi
// 008e585e  8bce                 mov ecx, esi
// 008e5860  e875e1f0ff           call 0x7f39da
// 008e5865  5f                   pop edi
// 008e5866  5e                   pop esi
// 008e5867  c21000               ret 0x10
// copied from an identical function in another client (function ?sub_69F420@CXTCaptionButton@ns_ROCX000001@ns_ROCX000098@@QAEXHHHH@Z)

namespace ns_ROCX000001 {
extern void G1_func_0075fce0();
void fn_ROCX000001()
{
    G1_func_0075fce0();
}
}
