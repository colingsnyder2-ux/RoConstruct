// from server: 100% by auto
// roc 2008-06 004a86c0  unit: RBX::VHint::?$FactoryProduct::Creator  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a86c0
//
// 004a86c0  83ec08               sub esp, 8
// 004a86c3  53                   push ebx
// 004a86c4  55                   push ebp
// 004a86c5  56                   push esi
// 004a86c6  8bf1                 mov esi, ecx
// 004a86c8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004a86cb  57                   push edi
// 004a86cc  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004a86cf  8bcb                 mov ecx, ebx
// 004a86d1  2bcf                 sub ecx, edi
// 004a86d3  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004a86d8  f7e9                 imul ecx
// 004a86da  d1fa                 sar edx, 1
// 004a86dc  8bc2                 mov eax, edx
// 004a86de  c1e81f               shr eax, 0x1f
// 004a86e1  03c2                 add eax, edx
// 004a86e3  7504                 jne 0x4a86e9
// 004a86e5  33ff                 xor edi, edi
// 004a86e7  eb34                 jmp 0x4a871d
// 004a86e9  3bfb                 cmp edi, ebx
// 004a86eb  7606                 jbe 0x4a86f3
// 004a86ed  ff1590288000         call dword ptr [0x802890]
// 004a86f3  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004a86f7  8b06                 mov eax, dword ptr [esi]
// 004a86f9  85c9                 test ecx, ecx
// 004a86fb  7404                 je 0x4a8701
// 004a86fd  3bc8                 cmp ecx, eax
// 004a86ff  7406                 je 0x4a8707
// 004a8701  ff1590288000         call dword ptr [0x802890]
// 004a8707  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004a870b  2bcf                 sub ecx, edi
// 004a870d  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004a8712  f7e9                 imul ecx
// 004a8714  d1fa                 sar edx, 1
// 004a8716  8bfa                 mov edi, edx
// 004a8718  c1ef1f               shr edi, 0x1f
// 004a871b  03fa                 add edi, edx
// 004a871d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004a8721  8b542424             mov edx, dword ptr [esp + 0x24]
// 004a8725  8b442420             mov eax, dword ptr [esp + 0x20]
// 004a8729  51                   push ecx
// 004a872a  6a01                 push 1
// 004a872c  52                   push edx
// 004a872d  50                   push eax
// 004a872e  8bce                 mov ecx, esi
// 004a8730  e8dbf9ffff           call 0x4a8110
// 004a8735  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004a8738  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 004a873b  7606                 jbe 0x4a8743
// 004a873d  ff1590288000         call dword ptr [0x802890]
// 004a8743  8b36                 mov esi, dword ptr [esi]
// 004a8745  8bee                 mov ebp, esi
// 004a8747  895c2414             mov dword ptr [esp + 0x14], ebx
// 004a874b  85f6                 test esi, esi
// 004a874d  751b                 jne 0x4a876a
// 004a874f  ff1590288000         call dword ptr [0x802890]
// 004a8755  33c0                 xor eax, eax
// 004a8757  8d0c7f               lea ecx, [edi + edi*2]
// 004a875a  8d3c8b               lea edi, [ebx + ecx*4]
// 004a875d  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004a8760  7713                 ja 0x4a8775
// 004a8762  85f6                 test esi, esi
// 004a8764  7408                 je 0x4a876e
// 004a8766  8b36                 mov esi, dword ptr [esi]
// 004a8768  eb06                 jmp 0x4a8770
// 004a876a  8b06                 mov eax, dword ptr [esi]
// 004a876c  ebe9                 jmp 0x4a8757
// 004a876e  33f6                 xor esi, esi
// 004a8770  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 004a8773  7306                 jae 0x4a877b
// 004a8775  ff1590288000         call dword ptr [0x802890]
// 004a877b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a877f  897804               mov dword ptr [eax + 4], edi
// 004a8782  5f                   pop edi
// 004a8783  5e                   pop esi
// 004a8784  8928                 mov dword ptr [eax], ebp
// 004a8786  5d                   pop ebp
// 004a8787  5b                   pop ebx
// 004a8788  83c408               add esp, 8
// 004a878b  c21000               ret 0x10
// standard library vector<pod12> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
