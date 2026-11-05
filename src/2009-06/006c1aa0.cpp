// from server: 100% by auto
// roc 2009-06 006c1aa0  unit: VWaitScriptSlot::?$TGenericSlotWrapper  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006c1aa0
//
// 006c1aa0  53                   push ebx
// 006c1aa1  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 006c1aa7  56                   push esi
// 006c1aa8  8bf1                 mov esi, ecx
// 006c1aaa  8b06                 mov eax, dword ptr [esi]
// 006c1aac  57                   push edi
// 006c1aad  85c0                 test eax, eax
// 006c1aaf  7508                 jne 0x6c1ab9
// 006c1ab1  ffd3                 call ebx
// 006c1ab3  8b06                 mov eax, dword ptr [esi]
// 006c1ab5  85c0                 test eax, eax
// 006c1ab7  7404                 je 0x6c1abd
// 006c1ab9  8b10                 mov edx, dword ptr [eax]
// 006c1abb  eb02                 jmp 0x6c1abf
// 006c1abd  33d2                 xor edx, edx
// 006c1abf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006c1ac3  8d3c49               lea edi, [ecx + ecx*2]
// 006c1ac6  8b4e04               mov ecx, dword ptr [esi + 4]
// 006c1ac9  03ff                 add edi, edi
// 006c1acb  03ff                 add edi, edi
// 006c1acd  03ff                 add edi, edi
// 006c1acf  03cf                 add ecx, edi
// 006c1ad1  3b4a10               cmp ecx, dword ptr [edx + 0x10]
// 006c1ad4  770f                 ja 0x6c1ae5
// 006c1ad6  85c0                 test eax, eax
// 006c1ad8  7404                 je 0x6c1ade
// 006c1ada  8b00                 mov eax, dword ptr [eax]
// 006c1adc  eb02                 jmp 0x6c1ae0
// 006c1ade  33c0                 xor eax, eax
// 006c1ae0  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 006c1ae3  7302                 jae 0x6c1ae7
// 006c1ae5  ffd3                 call ebx
// 006c1ae7  017e04               add dword ptr [esi + 4], edi
// 006c1aea  5f                   pop edi
// 006c1aeb  8bc6                 mov eax, esi
// 006c1aed  5e                   pop esi
// 006c1aee  5b                   pop ebx
// 006c1aef  c20400               ret 4
// standard library vector<pod24> (function ??Y?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@std@@QAEAAV01@H@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
