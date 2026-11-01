// from server: 100% by auto
// roc 2009-12 007898e0  unit: RBX::UniversalTool  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007898e0
//
// 007898e0  8b442408             mov eax, dword ptr [esp + 8]
// 007898e4  57                   push edi
// 007898e5  8b7c2408             mov edi, dword ptr [esp + 8]
// 007898e9  8bcf                 mov ecx, edi
// 007898eb  e800edffff           call 0x7885f0
// 007898f0  83780806             cmp dword ptr [eax + 8], 6
// 007898f4  7404                 je 0x7898fa
// 007898f6  33c0                 xor eax, eax
// 007898f8  5f                   pop edi
// 007898f9  c3                   ret 
// 007898fa  8b08                 mov ecx, dword ptr [eax]
// 007898fc  80790600             cmp byte ptr [ecx + 6], 0
// 00789900  8b542410             mov edx, dword ptr [esp + 0x10]
// 00789904  56                   push esi
// 00789905  741b                 je 0x789922
// 00789907  83fa01               cmp edx, 1
// 0078990a  7c7d                 jl 0x789989
// 0078990c  0fb67107             movzx esi, byte ptr [ecx + 7]
// 00789910  3bd6                 cmp edx, esi
// 00789912  7f75                 jg 0x789989
// 00789914  c1e204               shl edx, 4
// 00789917  8d4c0a08             lea ecx, [edx + ecx + 8]
// 0078991b  be56fd9900           mov esi, 0x99fd56
// 00789920  eb22                 jmp 0x789944
// 00789922  83fa01               cmp edx, 1
// 00789925  8b7110               mov esi, dword ptr [ecx + 0x10]
// 00789928  7c5f                 jl 0x789989
// 0078992a  3b5624               cmp edx, dword ptr [esi + 0x24]
// 0078992d  7f5a                 jg 0x789989
// 0078992f  8b761c               mov esi, dword ptr [esi + 0x1c]
// 00789932  8b7496fc             mov esi, dword ptr [esi + edx*4 - 4]
// 00789936  8b4c9110             mov ecx, dword ptr [ecx + edx*4 + 0x10]
// 0078993a  8b4908               mov ecx, dword ptr [ecx + 8]
// 0078993d  83c610               add esi, 0x10
// 00789940  85f6                 test esi, esi
// 00789942  7440                 je 0x789984
// 00789944  834708f0             add dword ptr [edi + 8], -0x10
// 00789948  8b5708               mov edx, dword ptr [edi + 8]
// 0078994b  53                   push ebx
// 0078994c  8b1a                 mov ebx, dword ptr [edx]
// 0078994e  8919                 mov dword ptr [ecx], ebx
// 00789950  8b5a04               mov ebx, dword ptr [edx + 4]
// 00789953  895904               mov dword ptr [ecx + 4], ebx
// 00789956  8b5208               mov edx, dword ptr [edx + 8]
// 00789959  895108               mov dword ptr [ecx + 8], edx
// 0078995c  8b4f08               mov ecx, dword ptr [edi + 8]
// 0078995f  ba04000000           mov edx, 4
// 00789964  395108               cmp dword ptr [ecx + 8], edx
// 00789967  5b                   pop ebx
// 00789968  7c1a                 jl 0x789984
// 0078996a  8b09                 mov ecx, dword ptr [ecx]
// 0078996c  f6410503             test byte ptr [ecx + 5], 3
// 00789970  7412                 je 0x789984
// 00789972  8b00                 mov eax, dword ptr [eax]
// 00789974  845005               test byte ptr [eax + 5], dl
// 00789977  740b                 je 0x789984
// 00789979  51                   push ecx
// 0078997a  50                   push eax
// 0078997b  57                   push edi
// 0078997c  e87f430400           call 0x7cdd00
// 00789981  83c40c               add esp, 0xc
// 00789984  8bc6                 mov eax, esi
// 00789986  5e                   pop esi
// 00789987  5f                   pop edi
// 00789988  c3                   ret 
// 00789989  5e                   pop esi
// 0078998a  33c0                 xor eax, eax
// 0078998c  5f                   pop edi
// 0078998d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_setupvalue)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
