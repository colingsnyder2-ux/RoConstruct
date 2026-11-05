// from server: 100% by auto
// roc 2009-06 00440be0  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 231 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00440be0
//
// 00440be0  56                   push esi
// 00440be1  57                   push edi
// 00440be2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00440be6  8bf1                 mov esi, ecx
// 00440be8  3bf7                 cmp esi, edi
// 00440bea  0f84d0000000         je 0x440cc0
// 00440bf0  53                   push ebx
// 00440bf1  8b5f10               mov ebx, dword ptr [edi + 0x10]
// 00440bf4  55                   push ebp
// 00440bf5  8b6f0c               mov ebp, dword ptr [edi + 0xc]
// 00440bf8  8bc3                 mov eax, ebx
// 00440bfa  2bc5                 sub eax, ebp
// 00440bfc  c1f802               sar eax, 2
// 00440bff  85c0                 test eax, eax
// 00440c01  750e                 jne 0x440c11
// 00440c03  e8c8feffff           call 0x440ad0
// 00440c08  5d                   pop ebp
// 00440c09  5b                   pop ebx
// 00440c0a  5f                   pop edi
// 00440c0b  8bc6                 mov eax, esi
// 00440c0d  5e                   pop esi
// 00440c0e  c20400               ret 4
// 00440c11  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00440c14  8b5610               mov edx, dword ptr [esi + 0x10]
// 00440c17  2bd1                 sub edx, ecx
// 00440c19  c1fa02               sar edx, 2
// 00440c1c  3bc2                 cmp eax, edx
// 00440c1e  7726                 ja 0x440c46
// 00440c20  51                   push ecx
// 00440c21  53                   push ebx
// 00440c22  55                   push ebp
// 00440c23  e8e8f3ffff           call 0x440010
// 00440c28  8b4710               mov eax, dword ptr [edi + 0x10]
// 00440c2b  2b470c               sub eax, dword ptr [edi + 0xc]
// 00440c2e  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00440c31  83c40c               add esp, 0xc
// 00440c34  5d                   pop ebp
// 00440c35  c1f802               sar eax, 2
// 00440c38  5b                   pop ebx
// 00440c39  8d1481               lea edx, [ecx + eax*4]
// 00440c3c  5f                   pop edi
// 00440c3d  895610               mov dword ptr [esi + 0x10], edx
// 00440c40  8bc6                 mov eax, esi
// 00440c42  5e                   pop esi
// 00440c43  c20400               ret 4
// 00440c46  85c9                 test ecx, ecx
// 00440c48  7504                 jne 0x440c4e
// 00440c4a  33db                 xor ebx, ebx
// 00440c4c  eb08                 jmp 0x440c56
// 00440c4e  8b5e14               mov ebx, dword ptr [esi + 0x14]
// 00440c51  2bd9                 sub ebx, ecx
// 00440c53  c1fb02               sar ebx, 2
// 00440c56  3bc3                 cmp eax, ebx
// 00440c58  772c                 ja 0x440c86
// 00440c5a  8bc5                 mov eax, ebp
// 00440c5c  51                   push ecx
// 00440c5d  8d1c90               lea ebx, [eax + edx*4]
// 00440c60  53                   push ebx
// 00440c61  50                   push eax
// 00440c62  e8a9f3ffff           call 0x440010
// 00440c67  8b4610               mov eax, dword ptr [esi + 0x10]
// 00440c6a  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 00440c6d  83c40c               add esp, 0xc
// 00440c70  50                   push eax
// 00440c71  51                   push ecx
// 00440c72  53                   push ebx
// 00440c73  8bce                 mov ecx, esi
// 00440c75  e8c6472600           call 0x6a5440
// 00440c7a  5d                   pop ebp
// 00440c7b  5b                   pop ebx
// 00440c7c  894610               mov dword ptr [esi + 0x10], eax
// 00440c7f  5f                   pop edi
// 00440c80  8bc6                 mov eax, esi
// 00440c82  5e                   pop esi
// 00440c83  c20400               ret 4
// 00440c86  85c9                 test ecx, ecx
// 00440c88  7409                 je 0x440c93
// 00440c8a  51                   push ecx
// 00440c8b  e8a27d2d00           call 0x718a32
// 00440c90  83c404               add esp, 4
// 00440c93  8b4710               mov eax, dword ptr [edi + 0x10]
// 00440c96  2b470c               sub eax, dword ptr [edi + 0xc]
// 00440c99  8bce                 mov ecx, esi
// 00440c9b  c1f802               sar eax, 2
// 00440c9e  50                   push eax
// 00440c9f  e8dc16ffff           call 0x432380
// 00440ca4  84c0                 test al, al
// 00440ca6  7416                 je 0x440cbe
// 00440ca8  8b560c               mov edx, dword ptr [esi + 0xc]
// 00440cab  8b4710               mov eax, dword ptr [edi + 0x10]
// 00440cae  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00440cb1  52                   push edx
// 00440cb2  50                   push eax
// 00440cb3  51                   push ecx
// 00440cb4  8bce                 mov ecx, esi
// 00440cb6  e885472600           call 0x6a5440
// 00440cbb  894610               mov dword ptr [esi + 0x10], eax
// 00440cbe  5d                   pop ebp
// 00440cbf  5b                   pop ebx
// 00440cc0  5f                   pop edi
// 00440cc1  8bc6                 mov eax, esi
// 00440cc3  5e                   pop esi
// 00440cc4  c20400               ret 4
// standard library vector<ptr> (function ??4?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAV01@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
