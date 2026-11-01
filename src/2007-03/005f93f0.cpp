// from server: 100% by auto
// roc 2007-03 005f93f0  unit: seg_005f0000  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f93f0
//
// 005f93f0  53                   push ebx
// 005f93f1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005f93f5  56                   push esi
// 005f93f6  8b7310               mov esi, dword ptr [ebx + 0x10]
// 005f93f9  57                   push edi
// 005f93fa  6afd                 push -3
// 005f93fc  8d461c               lea eax, [esi + 0x1c]
// 005f93ff  50                   push eax
// 005f9400  53                   push ebx
// 005f9401  c6461443             mov byte ptr [esi + 0x14], 0x43
// 005f9405  e806feffff           call 0x5f9210
// 005f940a  33ff                 xor edi, edi
// 005f940c  83c40c               add esp, 0xc
// 005f940f  397e08               cmp dword ptr [esi + 8], edi
// 005f9412  7e19                 jle 0x5f942d
// 005f9414  8b0e                 mov ecx, dword ptr [esi]
// 005f9416  6afd                 push -3
// 005f9418  8d14b9               lea edx, [ecx + edi*4]
// 005f941b  52                   push edx
// 005f941c  53                   push ebx
// 005f941d  e8eefdffff           call 0x5f9210
// 005f9422  83c701               add edi, 1
// 005f9425  83c40c               add esp, 0xc
// 005f9428  3b7e08               cmp edi, dword ptr [esi + 8]
// 005f942b  7ce7                 jl 0x5f9414
// 005f942d  5f                   pop edi
// 005f942e  5e                   pop esi
// 005f942f  5b                   pop ebx
// 005f9430  c3                   ret 
// library lua-5.1.1/lgc.c (function _luaC_freeall)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lgc.c
