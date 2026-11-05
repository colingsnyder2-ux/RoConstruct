// from server: 100% by auto
// roc 2010-06 00730680  unit: lua_exception  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00730680
//
// 00730680  53                   push ebx
// 00730681  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 00730687  56                   push esi
// 00730688  8bf1                 mov esi, ecx
// 0073068a  8b06                 mov eax, dword ptr [esi]
// 0073068c  57                   push edi
// 0073068d  85c0                 test eax, eax
// 0073068f  7508                 jne 0x730699
// 00730691  ffd3                 call ebx
// 00730693  8b06                 mov eax, dword ptr [esi]
// 00730695  85c0                 test eax, eax
// 00730697  7404                 je 0x73069d
// 00730699  8b10                 mov edx, dword ptr [eax]
// 0073069b  eb02                 jmp 0x73069f
// 0073069d  33d2                 xor edx, edx
// 0073069f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007306a3  8d3c49               lea edi, [ecx + ecx*2]
// 007306a6  8b4e04               mov ecx, dword ptr [esi + 4]
// 007306a9  03ff                 add edi, edi
// 007306ab  03ff                 add edi, edi
// 007306ad  03ff                 add edi, edi
// 007306af  03cf                 add ecx, edi
// 007306b1  3b4a10               cmp ecx, dword ptr [edx + 0x10]
// 007306b4  770f                 ja 0x7306c5
// 007306b6  85c0                 test eax, eax
// 007306b8  7404                 je 0x7306be
// 007306ba  8b00                 mov eax, dword ptr [eax]
// 007306bc  eb02                 jmp 0x7306c0
// 007306be  33c0                 xor eax, eax
// 007306c0  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 007306c3  7302                 jae 0x7306c7
// 007306c5  ffd3                 call ebx
// 007306c7  017e04               add dword ptr [esi + 4], edi
// 007306ca  5f                   pop edi
// 007306cb  8bc6                 mov eax, esi
// 007306cd  5e                   pop esi
// 007306ce  5b                   pop ebx
// 007306cf  c20400               ret 4
// standard library vector<pod24> (function ??Y?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@std@@QAEAAV01@H@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
