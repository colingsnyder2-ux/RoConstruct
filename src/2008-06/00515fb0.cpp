// from server: 100% by auto
// roc 2008-06 00515fb0  unit: G3D::BinaryInput  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00515fb0
//
// 00515fb0  53                   push ebx
// 00515fb1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00515fb5  55                   push ebp
// 00515fb6  8b2d90288000         mov ebp, dword ptr [0x802890]
// 00515fbc  56                   push esi
// 00515fbd  8bf1                 mov esi, ecx
// 00515fbf  57                   push edi
// 00515fc0  c70300000000         mov dword ptr [ebx], 0
// 00515fc6  85f6                 test esi, esi
// 00515fc8  740e                 je 0x515fd8
// 00515fca  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00515fce  39460c               cmp dword ptr [esi + 0xc], eax
// 00515fd1  7705                 ja 0x515fd8
// 00515fd3  3b4610               cmp eax, dword ptr [esi + 0x10]
// 00515fd6  7606                 jbe 0x515fde
// 00515fd8  ffd5                 call ebp
// 00515fda  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00515fde  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00515fe2  8b0e                 mov ecx, dword ptr [esi]
// 00515fe4  890b                 mov dword ptr [ebx], ecx
// 00515fe6  894304               mov dword ptr [ebx + 4], eax
// 00515fe9  397e0c               cmp dword ptr [esi + 0xc], edi
// 00515fec  7705                 ja 0x515ff3
// 00515fee  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00515ff1  7606                 jbe 0x515ff9
// 00515ff3  ffd5                 call ebp
// 00515ff5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00515ff9  8b03                 mov eax, dword ptr [ebx]
// 00515ffb  8b0e                 mov ecx, dword ptr [esi]
// 00515ffd  85c0                 test eax, eax
// 00515fff  7404                 je 0x516005
// 00516001  3bc1                 cmp eax, ecx
// 00516003  7402                 je 0x516007
// 00516005  ffd5                 call ebp
// 00516007  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0051600a  3bcf                 cmp ecx, edi
// 0051600c  741c                 je 0x51602a
// 0051600e  8b4610               mov eax, dword ptr [esi + 0x10]
// 00516011  2bc7                 sub eax, edi
// 00516013  8d2c08               lea ebp, [eax + ecx]
// 00516016  85c0                 test eax, eax
// 00516018  7e0d                 jle 0x516027
// 0051601a  50                   push eax
// 0051601b  57                   push edi
// 0051601c  50                   push eax
// 0051601d  51                   push ecx
// 0051601e  ff1550288000         call dword ptr [0x802850]
// 00516024  83c410               add esp, 0x10
// 00516027  896e10               mov dword ptr [esi + 0x10], ebp
// 0051602a  5f                   pop edi
// 0051602b  5e                   pop esi
// 0051602c  5d                   pop ebp
// 0051602d  8bc3                 mov eax, ebx
// 0051602f  5b                   pop ebx
// 00516030  c21400               ret 0x14
// standard library vector<char> (function ?erase@?$vector@DV?$allocator@D@std@@@std@@QAE?AV?$_Vector_iterator@DV?$allocator@D@std@@@2@V?$_Vector_const_iterator@DV?$allocator@D@std@@@2@0@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
