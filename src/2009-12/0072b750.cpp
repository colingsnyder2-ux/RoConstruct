// from server: 100% by auto
// roc 2009-12 0072b750  unit: VWiniInetRequest_source::?$stream_buffer  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0072b750
//
// 0072b750  53                   push ebx
// 0072b751  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 0072b757  56                   push esi
// 0072b758  8bf1                 mov esi, ecx
// 0072b75a  8b06                 mov eax, dword ptr [esi]
// 0072b75c  57                   push edi
// 0072b75d  85c0                 test eax, eax
// 0072b75f  7508                 jne 0x72b769
// 0072b761  ffd3                 call ebx
// 0072b763  8b06                 mov eax, dword ptr [esi]
// 0072b765  85c0                 test eax, eax
// 0072b767  7404                 je 0x72b76d
// 0072b769  8b10                 mov edx, dword ptr [eax]
// 0072b76b  eb02                 jmp 0x72b76f
// 0072b76d  33d2                 xor edx, edx
// 0072b76f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0072b773  8d3c89               lea edi, [ecx + ecx*4]
// 0072b776  8b4e04               mov ecx, dword ptr [esi + 4]
// 0072b779  03ff                 add edi, edi
// 0072b77b  03ff                 add edi, edi
// 0072b77d  03ff                 add edi, edi
// 0072b77f  03cf                 add ecx, edi
// 0072b781  3b4a10               cmp ecx, dword ptr [edx + 0x10]
// 0072b784  770f                 ja 0x72b795
// 0072b786  85c0                 test eax, eax
// 0072b788  7404                 je 0x72b78e
// 0072b78a  8b00                 mov eax, dword ptr [eax]
// 0072b78c  eb02                 jmp 0x72b790
// 0072b78e  33c0                 xor eax, eax
// 0072b790  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0072b793  7302                 jae 0x72b797
// 0072b795  ffd3                 call ebx
// 0072b797  017e04               add dword ptr [esi + 4], edi
// 0072b79a  5f                   pop edi
// 0072b79b  8bc6                 mov eax, esi
// 0072b79d  5e                   pop esi
// 0072b79e  5b                   pop ebx
// 0072b79f  c20400               ret 4
// standard library vector<pod40> (function ??Y?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@std@@QAEAAV01@H@Z)

// stl: vector<pod40>
struct E { int v[10]; };
#include <vector>
template class std::vector<E>;
