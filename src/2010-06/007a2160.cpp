// from server: 100% by auto
// roc 2010-06 007a2160  unit: W4_D3DFORMAT::?$EnumDesc  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007a2160
//
// 007a2160  83ec08               sub esp, 8
// 007a2163  53                   push ebx
// 007a2164  55                   push ebp
// 007a2165  56                   push esi
// 007a2166  8bf1                 mov esi, ecx
// 007a2168  8b4610               mov eax, dword ptr [esi + 0x10]
// 007a216b  57                   push edi
// 007a216c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 007a216f  8bc8                 mov ecx, eax
// 007a2171  2bcf                 sub ecx, edi
// 007a2173  f7c1fcffffff         test ecx, 0xfffffffc
// 007a2179  7504                 jne 0x7a217f
// 007a217b  33db                 xor ebx, ebx
// 007a217d  eb27                 jmp 0x7a21a6
// 007a217f  3bf8                 cmp edi, eax
// 007a2181  7606                 jbe 0x7a2189
// 007a2183  ff150ca99e00         call dword ptr [0x9ea90c]
// 007a2189  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007a218d  8b06                 mov eax, dword ptr [esi]
// 007a218f  85c9                 test ecx, ecx
// 007a2191  7404                 je 0x7a2197
// 007a2193  3bc8                 cmp ecx, eax
// 007a2195  7406                 je 0x7a219d
// 007a2197  ff150ca99e00         call dword ptr [0x9ea90c]
// 007a219d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 007a21a1  2bdf                 sub ebx, edi
// 007a21a3  c1fb02               sar ebx, 2
// 007a21a6  8b542428             mov edx, dword ptr [esp + 0x28]
// 007a21aa  8b442424             mov eax, dword ptr [esp + 0x24]
// 007a21ae  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007a21b2  52                   push edx
// 007a21b3  6a01                 push 1
// 007a21b5  50                   push eax
// 007a21b6  51                   push ecx
// 007a21b7  8bce                 mov ecx, esi
// 007a21b9  e852fdffff           call 0x7a1f10
// 007a21be  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 007a21c1  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 007a21c4  7606                 jbe 0x7a21cc
// 007a21c6  ff150ca99e00         call dword ptr [0x9ea90c]
// 007a21cc  8b36                 mov esi, dword ptr [esi]
// 007a21ce  8bee                 mov ebp, esi
// 007a21d0  897c2414             mov dword ptr [esp + 0x14], edi
// 007a21d4  85f6                 test esi, esi
// 007a21d6  7518                 jne 0x7a21f0
// 007a21d8  ff150ca99e00         call dword ptr [0x9ea90c]
// 007a21de  33c0                 xor eax, eax
// 007a21e0  8d3c9f               lea edi, [edi + ebx*4]
// 007a21e3  3b7810               cmp edi, dword ptr [eax + 0x10]
// 007a21e6  7713                 ja 0x7a21fb
// 007a21e8  85f6                 test esi, esi
// 007a21ea  7408                 je 0x7a21f4
// 007a21ec  8b36                 mov esi, dword ptr [esi]
// 007a21ee  eb06                 jmp 0x7a21f6
// 007a21f0  8b06                 mov eax, dword ptr [esi]
// 007a21f2  ebec                 jmp 0x7a21e0
// 007a21f4  33f6                 xor esi, esi
// 007a21f6  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 007a21f9  7306                 jae 0x7a2201
// 007a21fb  ff150ca99e00         call dword ptr [0x9ea90c]
// 007a2201  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007a2205  897804               mov dword ptr [eax + 4], edi
// 007a2208  5f                   pop edi
// 007a2209  5e                   pop esi
// 007a220a  8928                 mov dword ptr [eax], ebp
// 007a220c  5d                   pop ebp
// 007a220d  5b                   pop ebx
// 007a220e  83c408               add esp, 8
// 007a2211  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@ABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
