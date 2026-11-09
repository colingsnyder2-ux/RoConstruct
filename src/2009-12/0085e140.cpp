// roc 2009-12 0085e140  unit: CXTSplitterWnd  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085e140
//
// 0085e140  56                   push esi
// 0085e141  57                   push edi
// 0085e142  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0085e146  8bf1                 mov esi, ecx
// 0085e148  83ff1a               cmp edi, 0x1a
// 0085e14b  7405                 je 0x85e152
// 0085e14d  83ff15               cmp edi, 0x15
// 0085e150  751c                 jne 0x85e16e
// 0085e152  e859f6ffff           call 0x85d7b0
// 0085e157  8b10                 mov edx, dword ptr [eax]
// 0085e159  8bc8                 mov ecx, eax
// 0085e15b  8b4204               mov eax, dword ptr [edx + 4]
// 0085e15e  ffd0                 call eax
// 0085e160  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0085e163  6a00                 push 0
// 0085e165  6a00                 push 0
// 0085e167  51                   push ecx
// 0085e168  ff15e8cb9800         call dword ptr [0x98cbe8]
// 0085e16e  8b542418             mov edx, dword ptr [esp + 0x18]
// 0085e172  8b442414             mov eax, dword ptr [esp + 0x14]
// 0085e176  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0085e17a  52                   push edx
// 0085e17b  50                   push eax
// 0085e17c  51                   push ecx
// 0085e17d  57                   push edi
// 0085e17e  8bce                 mov ecx, esi
// 0085e180  e85558f9ff           call 0x7f39da
// 0085e185  5f                   pop edi
// 0085e186  5e                   pop esi
// 0085e187  c21000               ret 0x10
// copied from an identical function in another client (function ?sub_69F420@CXTCaptionButton@ns_ROCX000001@ns_ROCX000098@@QAEXHHHH@Z)

namespace ns_ROCX000001 {
extern void G1_func_0075fce0();
void fn_ROCX000001()
{
    G1_func_0075fce0();
}
}
