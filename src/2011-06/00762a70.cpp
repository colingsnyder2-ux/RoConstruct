// from server: 100% by auto
// roc 2011-06 00762a70  unit: seg_00760000  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762a70
//
// 00762a70  56                   push esi
// 00762a71  8b742408             mov esi, dword ptr [esp + 8]
// 00762a75  8b4610               mov eax, dword ptr [esi + 0x10]
// 00762a78  8b4844               mov ecx, dword ptr [eax + 0x44]
// 00762a7b  57                   push edi
// 00762a7c  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 00762a7f  7209                 jb 0x762a8a
// 00762a81  56                   push esi
// 00762a82  e819470700           call 0x7d71a0
// 00762a87  83c404               add esp, 4
// 00762a8a  8b4614               mov eax, dword ptr [esi + 0x14]
// 00762a8d  3b4628               cmp eax, dword ptr [esi + 0x28]
// 00762a90  7505                 jne 0x762a97
// 00762a92  8b4648               mov eax, dword ptr [esi + 0x48]
// 00762a95  eb08                 jmp 0x762a9f
// 00762a97  8b5004               mov edx, dword ptr [eax + 4]
// 00762a9a  8b02                 mov eax, dword ptr [edx]
// 00762a9c  8b400c               mov eax, dword ptr [eax + 0xc]
// 00762a9f  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00762aa3  50                   push eax
// 00762aa4  57                   push edi
// 00762aa5  56                   push esi
// 00762aa6  e8c5780700           call 0x7da370
// 00762aab  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00762aaf  894810               mov dword ptr [eax + 0x10], ecx
// 00762ab2  8bcf                 mov ecx, edi
// 00762ab4  c1e104               shl ecx, 4
// 00762ab7  294e08               sub dword ptr [esi + 8], ecx
// 00762aba  83c40c               add esp, 0xc
// 00762abd  85ff                 test edi, edi
// 00762abf  7431                 je 0x762af2
// 00762ac1  53                   push ebx
// 00762ac2  bbe8ffffff           mov ebx, 0xffffffe8
// 00762ac7  55                   push ebp
// 00762ac8  8d540118             lea edx, [ecx + eax + 0x18]
// 00762acc  2bd8                 sub ebx, eax
// 00762ace  8bff                 mov edi, edi
// 00762ad0  8b4e08               mov ecx, dword ptr [esi + 8]
// 00762ad3  83ea10               sub edx, 0x10
// 00762ad6  03cb                 add ecx, ebx
// 00762ad8  8b2c11               mov ebp, dword ptr [ecx + edx]
// 00762adb  03ca                 add ecx, edx
// 00762add  892a                 mov dword ptr [edx], ebp
// 00762adf  8b6904               mov ebp, dword ptr [ecx + 4]
// 00762ae2  4f                   dec edi
// 00762ae3  896a04               mov dword ptr [edx + 4], ebp
// 00762ae6  8b4908               mov ecx, dword ptr [ecx + 8]
// 00762ae9  894a08               mov dword ptr [edx + 8], ecx
// 00762aec  85ff                 test edi, edi
// 00762aee  75e0                 jne 0x762ad0
// 00762af0  5d                   pop ebp
// 00762af1  5b                   pop ebx
// 00762af2  8b4e08               mov ecx, dword ptr [esi + 8]
// 00762af5  8901                 mov dword ptr [ecx], eax
// 00762af7  c7410806000000       mov dword ptr [ecx + 8], 6
// 00762afe  83460810             add dword ptr [esi + 8], 0x10
// 00762b02  5f                   pop edi
// 00762b03  5e                   pop esi
// 00762b04  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushcclosure)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
