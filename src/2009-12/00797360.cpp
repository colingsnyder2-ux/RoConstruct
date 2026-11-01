// from server: 100% by auto
// roc 2009-12 00797360  unit: lua_exception  size: 216 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00797360
//
// 00797360  83ec64               sub esp, 0x64
// 00797363  56                   push esi
// 00797364  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00797368  8b4644               mov eax, dword ptr [esi + 0x44]
// 0079736b  8944246c             mov dword ptr [esp + 0x6c], eax
// 0079736f  85c0                 test eax, eax
// 00797371  0f84bc000000         je 0x797433
// 00797377  807e3900             cmp byte ptr [esi + 0x39], 0
// 0079737b  0f84b2000000         je 0x797433
// 00797381  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00797384  8b4614               mov eax, dword ptr [esi + 0x14]
// 00797387  8b542474             mov edx, dword ptr [esp + 0x74]
// 0079738b  53                   push ebx
// 0079738c  8b5e08               mov ebx, dword ptr [esi + 8]
// 0079738f  55                   push ebp
// 00797390  8b6808               mov ebp, dword ptr [eax + 8]
// 00797393  57                   push edi
// 00797394  8bfb                 mov edi, ebx
// 00797396  2bf9                 sub edi, ecx
// 00797398  2be9                 sub ebp, ecx
// 0079739a  8b4c247c             mov ecx, dword ptr [esp + 0x7c]
// 0079739e  894c2410             mov dword ptr [esp + 0x10], ecx
// 007973a2  89542424             mov dword ptr [esp + 0x24], edx
// 007973a6  83f904               cmp ecx, 4
// 007973a9  750a                 jne 0x7973b5
// 007973ab  c744247000000000     mov dword ptr [esp + 0x70], 0
// 007973b3  eb1a                 jmp 0x7973cf
// 007973b5  2b4628               sub eax, dword ptr [esi + 0x28]
// 007973b8  8bc8                 mov ecx, eax
// 007973ba  b8abaaaa2a           mov eax, 0x2aaaaaab
// 007973bf  f7e9                 imul ecx
// 007973c1  c1fa02               sar edx, 2
// 007973c4  8bc2                 mov eax, edx
// 007973c6  c1e81f               shr eax, 0x1f
// 007973c9  03c2                 add eax, edx
// 007973cb  89442470             mov dword ptr [esp + 0x70], eax
// 007973cf  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 007973d2  2bcb                 sub ecx, ebx
// 007973d4  81f940010000         cmp ecx, 0x140
// 007973da  7f1b                 jg 0x7973f7
// 007973dc  8b462c               mov eax, dword ptr [esi + 0x2c]
// 007973df  83f814               cmp eax, 0x14
// 007973e2  7c06                 jl 0x7973ea
// 007973e4  8d1400               lea edx, [eax + eax]
// 007973e7  52                   push edx
// 007973e8  eb04                 jmp 0x7973ee
// 007973ea  83c014               add eax, 0x14
// 007973ed  50                   push eax
// 007973ee  56                   push esi
// 007973ef  e85cfeffff           call 0x797250
// 007973f4  83c408               add esp, 8
// 007973f7  8b4608               mov eax, dword ptr [esi + 8]
// 007973fa  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 007973fd  8d542410             lea edx, [esp + 0x10]
// 00797401  0540010000           add eax, 0x140
// 00797406  52                   push edx
// 00797407  894108               mov dword ptr [ecx + 8], eax
// 0079740a  56                   push esi
// 0079740b  c6463900             mov byte ptr [esi + 0x39], 0
// 0079740f  ff942480000000       call dword ptr [esp + 0x80]
// 00797416  8b4620               mov eax, dword ptr [esi + 0x20]
// 00797419  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0079741c  03c5                 add eax, ebp
// 0079741e  83c408               add esp, 8
// 00797421  c6463901             mov byte ptr [esi + 0x39], 1
// 00797425  894108               mov dword ptr [ecx + 8], eax
// 00797428  8b5620               mov edx, dword ptr [esi + 0x20]
// 0079742b  03d7                 add edx, edi
// 0079742d  5f                   pop edi
// 0079742e  5d                   pop ebp
// 0079742f  895608               mov dword ptr [esi + 8], edx
// 00797432  5b                   pop ebx
// 00797433  5e                   pop esi
// 00797434  83c464               add esp, 0x64
// 00797437  c3                   ret 
// library lua-5.1.3/ldo.c (function _luaD_callhook)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 ldo.c
