// from server: 100% by auto
// roc 2010-06 006aa260  unit: VWiniInetRequest_source::?$stream_buffer  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006aa260
//
// 006aa260  53                   push ebx
// 006aa261  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 006aa267  56                   push esi
// 006aa268  8bf1                 mov esi, ecx
// 006aa26a  8b06                 mov eax, dword ptr [esi]
// 006aa26c  57                   push edi
// 006aa26d  85c0                 test eax, eax
// 006aa26f  7508                 jne 0x6aa279
// 006aa271  ffd3                 call ebx
// 006aa273  8b06                 mov eax, dword ptr [esi]
// 006aa275  85c0                 test eax, eax
// 006aa277  7404                 je 0x6aa27d
// 006aa279  8b10                 mov edx, dword ptr [eax]
// 006aa27b  eb02                 jmp 0x6aa27f
// 006aa27d  33d2                 xor edx, edx
// 006aa27f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006aa283  8d3c89               lea edi, [ecx + ecx*4]
// 006aa286  8b4e04               mov ecx, dword ptr [esi + 4]
// 006aa289  03ff                 add edi, edi
// 006aa28b  03ff                 add edi, edi
// 006aa28d  03ff                 add edi, edi
// 006aa28f  03cf                 add ecx, edi
// 006aa291  3b4a10               cmp ecx, dword ptr [edx + 0x10]
// 006aa294  770f                 ja 0x6aa2a5
// 006aa296  85c0                 test eax, eax
// 006aa298  7404                 je 0x6aa29e
// 006aa29a  8b00                 mov eax, dword ptr [eax]
// 006aa29c  eb02                 jmp 0x6aa2a0
// 006aa29e  33c0                 xor eax, eax
// 006aa2a0  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 006aa2a3  7302                 jae 0x6aa2a7
// 006aa2a5  ffd3                 call ebx
// 006aa2a7  017e04               add dword ptr [esi + 4], edi
// 006aa2aa  5f                   pop edi
// 006aa2ab  8bc6                 mov eax, esi
// 006aa2ad  5e                   pop esi
// 006aa2ae  5b                   pop ebx
// 006aa2af  c20400               ret 4
// standard library vector<pod40> (function ??Y?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@std@@QAEAAV01@H@Z)

// stl: vector<pod40>
struct E { int v[10]; };
#include <vector>
template class std::vector<E>;
