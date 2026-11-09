// from server: 100% by auto
// roc 2011-06 00560e40  unit: seg_00560000  size: 296 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00560e40
//
// 00560e40  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00560e44  53                   push ebx
// 00560e45  55                   push ebp
// 00560e46  56                   push esi
// 00560e47  57                   push edi
// 00560e48  85c9                 test ecx, ecx
// 00560e4a  0f8411010000         je 0x560f61
// 00560e50  8b742418             mov esi, dword ptr [esp + 0x18]
// 00560e54  85f6                 test esi, esi
// 00560e56  0f8405010000         je 0x560f61
// 00560e5c  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00560e60  85db                 test ebx, ebx
// 00560e62  0f84f9000000         je 0x560f61
// 00560e68  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00560e6c  85ed                 test ebp, ebp
// 00560e6e  0f84ed000000         je 0x560f61
// 00560e74  8b442424             mov eax, dword ptr [esp + 0x24]
// 00560e78  85c0                 test eax, eax
// 00560e7a  0f84e1000000         je 0x560f61
// 00560e80  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00560e84  85ff                 test edi, edi
// 00560e86  0f84d5000000         je 0x560f61
// 00560e8c  8b16                 mov edx, dword ptr [esi]
// 00560e8e  8913                 mov dword ptr [ebx], edx
// 00560e90  8b5604               mov edx, dword ptr [esi + 4]
// 00560e93  895500               mov dword ptr [ebp], edx
// 00560e96  0fb65618             movzx edx, byte ptr [esi + 0x18]
// 00560e9a  8910                 mov dword ptr [eax], edx
// 00560e9c  807e1801             cmp byte ptr [esi + 0x18], 1
// 00560ea0  7206                 jb 0x560ea8
// 00560ea2  807e1810             cmp byte ptr [esi + 0x18], 0x10
// 00560ea6  7612                 jbe 0x560eba
// 00560ea8  68142ca800           push 0xa82c14
// 00560ead  51                   push ecx
// 00560eae  e87d040000           call 0x561330
// 00560eb3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00560eb7  83c408               add esp, 8
// 00560eba  0fb64619             movzx eax, byte ptr [esi + 0x19]
// 00560ebe  8907                 mov dword ptr [edi], eax
// 00560ec0  807e1906             cmp byte ptr [esi + 0x19], 6
// 00560ec4  7612                 jbe 0x560ed8
// 00560ec6  68002ca800           push 0xa82c00
// 00560ecb  51                   push ecx
// 00560ecc  e85f040000           call 0x561330
// 00560ed1  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00560ed5  83c408               add esp, 8
// 00560ed8  8b442430             mov eax, dword ptr [esp + 0x30]
// 00560edc  85c0                 test eax, eax
// 00560ede  7406                 je 0x560ee6
// 00560ee0  0fb6561a             movzx edx, byte ptr [esi + 0x1a]
// 00560ee4  8910                 mov dword ptr [eax], edx
// 00560ee6  8b442434             mov eax, dword ptr [esp + 0x34]
// 00560eea  85c0                 test eax, eax
// 00560eec  7406                 je 0x560ef4
// 00560eee  0fb6561b             movzx edx, byte ptr [esi + 0x1b]
// 00560ef2  8910                 mov dword ptr [eax], edx
// 00560ef4  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00560ef8  85c0                 test eax, eax
// 00560efa  7406                 je 0x560f02
// 00560efc  0fb6561c             movzx edx, byte ptr [esi + 0x1c]
// 00560f00  8910                 mov dword ptr [eax], edx
// 00560f02  8b03                 mov eax, dword ptr [ebx]
// 00560f04  85c0                 test eax, eax
// 00560f06  7407                 je 0x560f0f
// 00560f08  3dffffff7f           cmp eax, 0x7fffffff
// 00560f0d  7612                 jbe 0x560f21
// 00560f0f  68ec2ba800           push 0xa82bec
// 00560f14  51                   push ecx
// 00560f15  e816040000           call 0x561330
// 00560f1a  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00560f1e  83c408               add esp, 8
// 00560f21  8b4500               mov eax, dword ptr [ebp]
// 00560f24  85c0                 test eax, eax
// 00560f26  7407                 je 0x560f2f
// 00560f28  3dffffff7f           cmp eax, 0x7fffffff
// 00560f2d  7612                 jbe 0x560f41
// 00560f2f  68d42ba800           push 0xa82bd4
// 00560f34  51                   push ecx
// 00560f35  e8f6030000           call 0x561330
// 00560f3a  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00560f3e  83c408               add esp, 8
// 00560f41  813e7effff1f         cmp dword ptr [esi], 0x1fffff7e
// 00560f47  760e                 jbe 0x560f57
// 00560f49  68a02ba800           push 0xa82ba0
// 00560f4e  51                   push ecx
// 00560f4f  e88c040000           call 0x5613e0
// 00560f54  83c408               add esp, 8
// 00560f57  5f                   pop edi
// 00560f58  5e                   pop esi
// 00560f59  5d                   pop ebp
// 00560f5a  b801000000           mov eax, 1
// 00560f5f  5b                   pop ebx
// 00560f60  c3                   ret 
// 00560f61  5f                   pop edi
// 00560f62  5e                   pop esi
// 00560f63  5d                   pop ebp
// 00560f64  33c0                 xor eax, eax
// 00560f66  5b                   pop ebx
// 00560f67  c3                   ret 
// library libpng-1.2.8/pngget.c (function _png_get_IHDR)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.8 pngget.c
