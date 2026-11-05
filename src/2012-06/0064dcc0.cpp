// from server: 100% by auto
// roc 2012-06 0064dcc0  unit: seg_00640000  size: 296 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0064dcc0
//
// 0064dcc0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0064dcc4  53                   push ebx
// 0064dcc5  55                   push ebp
// 0064dcc6  56                   push esi
// 0064dcc7  57                   push edi
// 0064dcc8  85c9                 test ecx, ecx
// 0064dcca  0f8411010000         je 0x64dde1
// 0064dcd0  8b742418             mov esi, dword ptr [esp + 0x18]
// 0064dcd4  85f6                 test esi, esi
// 0064dcd6  0f8405010000         je 0x64dde1
// 0064dcdc  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0064dce0  85db                 test ebx, ebx
// 0064dce2  0f84f9000000         je 0x64dde1
// 0064dce8  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0064dcec  85ed                 test ebp, ebp
// 0064dcee  0f84ed000000         je 0x64dde1
// 0064dcf4  8b442424             mov eax, dword ptr [esp + 0x24]
// 0064dcf8  85c0                 test eax, eax
// 0064dcfa  0f84e1000000         je 0x64dde1
// 0064dd00  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0064dd04  85ff                 test edi, edi
// 0064dd06  0f84d5000000         je 0x64dde1
// 0064dd0c  8b16                 mov edx, dword ptr [esi]
// 0064dd0e  8913                 mov dword ptr [ebx], edx
// 0064dd10  8b5604               mov edx, dword ptr [esi + 4]
// 0064dd13  895500               mov dword ptr [ebp], edx
// 0064dd16  0fb65618             movzx edx, byte ptr [esi + 0x18]
// 0064dd1a  8910                 mov dword ptr [eax], edx
// 0064dd1c  807e1801             cmp byte ptr [esi + 0x18], 1
// 0064dd20  7206                 jb 0x64dd28
// 0064dd22  807e1810             cmp byte ptr [esi + 0x18], 0x10
// 0064dd26  7612                 jbe 0x64dd3a
// 0064dd28  68c06ab800           push 0xb86ac0
// 0064dd2d  51                   push ecx
// 0064dd2e  e87d040000           call 0x64e1b0
// 0064dd33  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0064dd37  83c408               add esp, 8
// 0064dd3a  0fb64619             movzx eax, byte ptr [esi + 0x19]
// 0064dd3e  8907                 mov dword ptr [edi], eax
// 0064dd40  807e1906             cmp byte ptr [esi + 0x19], 6
// 0064dd44  7612                 jbe 0x64dd58
// 0064dd46  68ac6ab800           push 0xb86aac
// 0064dd4b  51                   push ecx
// 0064dd4c  e85f040000           call 0x64e1b0
// 0064dd51  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0064dd55  83c408               add esp, 8
// 0064dd58  8b442430             mov eax, dword ptr [esp + 0x30]
// 0064dd5c  85c0                 test eax, eax
// 0064dd5e  7406                 je 0x64dd66
// 0064dd60  0fb6561a             movzx edx, byte ptr [esi + 0x1a]
// 0064dd64  8910                 mov dword ptr [eax], edx
// 0064dd66  8b442434             mov eax, dword ptr [esp + 0x34]
// 0064dd6a  85c0                 test eax, eax
// 0064dd6c  7406                 je 0x64dd74
// 0064dd6e  0fb6561b             movzx edx, byte ptr [esi + 0x1b]
// 0064dd72  8910                 mov dword ptr [eax], edx
// 0064dd74  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0064dd78  85c0                 test eax, eax
// 0064dd7a  7406                 je 0x64dd82
// 0064dd7c  0fb6561c             movzx edx, byte ptr [esi + 0x1c]
// 0064dd80  8910                 mov dword ptr [eax], edx
// 0064dd82  8b03                 mov eax, dword ptr [ebx]
// 0064dd84  85c0                 test eax, eax
// 0064dd86  7407                 je 0x64dd8f
// 0064dd88  3dffffff7f           cmp eax, 0x7fffffff
// 0064dd8d  7612                 jbe 0x64dda1
// 0064dd8f  68986ab800           push 0xb86a98
// 0064dd94  51                   push ecx
// 0064dd95  e816040000           call 0x64e1b0
// 0064dd9a  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0064dd9e  83c408               add esp, 8
// 0064dda1  8b4500               mov eax, dword ptr [ebp]
// 0064dda4  85c0                 test eax, eax
// 0064dda6  7407                 je 0x64ddaf
// 0064dda8  3dffffff7f           cmp eax, 0x7fffffff
// 0064ddad  7612                 jbe 0x64ddc1
// 0064ddaf  68806ab800           push 0xb86a80
// 0064ddb4  51                   push ecx
// 0064ddb5  e8f6030000           call 0x64e1b0
// 0064ddba  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0064ddbe  83c408               add esp, 8
// 0064ddc1  813e7effff1f         cmp dword ptr [esi], 0x1fffff7e
// 0064ddc7  760e                 jbe 0x64ddd7
// 0064ddc9  684c6ab800           push 0xb86a4c
// 0064ddce  51                   push ecx
// 0064ddcf  e88c040000           call 0x64e260
// 0064ddd4  83c408               add esp, 8
// 0064ddd7  5f                   pop edi
// 0064ddd8  5e                   pop esi
// 0064ddd9  5d                   pop ebp
// 0064ddda  b801000000           mov eax, 1
// 0064dddf  5b                   pop ebx
// 0064dde0  c3                   ret 
// 0064dde1  5f                   pop edi
// 0064dde2  5e                   pop esi
// 0064dde3  5d                   pop ebp
// 0064dde4  33c0                 xor eax, eax
// 0064dde6  5b                   pop ebx
// 0064dde7  c3                   ret 
// library libpng-1.2.8/pngget.c (function _png_get_IHDR)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.8 pngget.c
