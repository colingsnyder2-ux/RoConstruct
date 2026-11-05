// from server: 100% by auto
// roc 2009-06 0048cf70  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048cf70
//
// 0048cf70  83ec08               sub esp, 8
// 0048cf73  53                   push ebx
// 0048cf74  55                   push ebp
// 0048cf75  56                   push esi
// 0048cf76  8bf1                 mov esi, ecx
// 0048cf78  8b4610               mov eax, dword ptr [esi + 0x10]
// 0048cf7b  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0048cf7e  8bc8                 mov ecx, eax
// 0048cf80  2bcb                 sub ecx, ebx
// 0048cf82  57                   push edi
// 0048cf83  f7c1e0ffffff         test ecx, 0xffffffe0
// 0048cf89  7504                 jne 0x48cf8f
// 0048cf8b  33ff                 xor edi, edi
// 0048cf8d  eb27                 jmp 0x48cfb6
// 0048cf8f  3bd8                 cmp ebx, eax
// 0048cf91  7606                 jbe 0x48cf99
// 0048cf93  ff15ace98900         call dword ptr [0x89e9ac]
// 0048cf99  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0048cf9d  8b06                 mov eax, dword ptr [esi]
// 0048cf9f  85c9                 test ecx, ecx
// 0048cfa1  7404                 je 0x48cfa7
// 0048cfa3  3bc8                 cmp ecx, eax
// 0048cfa5  7406                 je 0x48cfad
// 0048cfa7  ff15ace98900         call dword ptr [0x89e9ac]
// 0048cfad  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0048cfb1  2bfb                 sub edi, ebx
// 0048cfb3  c1ff05               sar edi, 5
// 0048cfb6  8b542428             mov edx, dword ptr [esp + 0x28]
// 0048cfba  8b442424             mov eax, dword ptr [esp + 0x24]
// 0048cfbe  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0048cfc2  52                   push edx
// 0048cfc3  6a01                 push 1
// 0048cfc5  50                   push eax
// 0048cfc6  51                   push ecx
// 0048cfc7  8bce                 mov ecx, esi
// 0048cfc9  e8f2faffff           call 0x48cac0
// 0048cfce  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0048cfd1  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0048cfd4  7606                 jbe 0x48cfdc
// 0048cfd6  ff15ace98900         call dword ptr [0x89e9ac]
// 0048cfdc  8b36                 mov esi, dword ptr [esi]
// 0048cfde  8bee                 mov ebp, esi
// 0048cfe0  895c2414             mov dword ptr [esp + 0x14], ebx
// 0048cfe4  85f6                 test esi, esi
// 0048cfe6  751a                 jne 0x48d002
// 0048cfe8  ff15ace98900         call dword ptr [0x89e9ac]
// 0048cfee  33c0                 xor eax, eax
// 0048cff0  c1e705               shl edi, 5
// 0048cff3  03fb                 add edi, ebx
// 0048cff5  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0048cff8  7713                 ja 0x48d00d
// 0048cffa  85f6                 test esi, esi
// 0048cffc  7408                 je 0x48d006
// 0048cffe  8b36                 mov esi, dword ptr [esi]
// 0048d000  eb06                 jmp 0x48d008
// 0048d002  8b06                 mov eax, dword ptr [esi]
// 0048d004  ebea                 jmp 0x48cff0
// 0048d006  33f6                 xor esi, esi
// 0048d008  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0048d00b  7306                 jae 0x48d013
// 0048d00d  ff15ace98900         call dword ptr [0x89e9ac]
// 0048d013  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048d017  897804               mov dword ptr [eax + 4], edi
// 0048d01a  5f                   pop edi
// 0048d01b  5e                   pop esi
// 0048d01c  8928                 mov dword ptr [eax], ebp
// 0048d01e  5d                   pop ebp
// 0048d01f  5b                   pop ebx
// 0048d020  83c408               add esp, 8
// 0048d023  c21000               ret 0x10
// standard library vector<pod32> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
