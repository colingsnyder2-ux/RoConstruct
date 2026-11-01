// from server: 100% by auto
// roc 2007-03 006159e0  unit: seg_00610000  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006159e0
//
// 006159e0  8b442408             mov eax, dword ptr [esp + 8]
// 006159e4  83e806               sub eax, 6
// 006159e7  744b                 je 0x615a34
// 006159e9  83e807               sub eax, 7
// 006159ec  7433                 je 0x615a21
// 006159ee  83e801               sub eax, 1
// 006159f1  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006159f5  7421                 je 0x615a18
// 006159f7  833805               cmp dword ptr [eax], 5
// 006159fa  750d                 jne 0x615a09
// 006159fc  83c9ff               or ecx, 0xffffffff
// 006159ff  394810               cmp dword ptr [eax + 0x10], ecx
// 00615a02  7505                 jne 0x615a09
// 00615a04  394814               cmp dword ptr [eax + 0x14], ecx
// 00615a07  743d                 je 0x615a46
// 00615a09  50                   push eax
// 00615a0a  8b442408             mov eax, dword ptr [esp + 8]
// 00615a0e  50                   push eax
// 00615a0f  e89cf8ffff           call 0x6152b0
// 00615a14  83c408               add esp, 8
// 00615a17  c3                   ret 
// 00615a18  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00615a1c  e95ffcffff           jmp 0x615680
// 00615a21  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00615a25  8b542404             mov edx, dword ptr [esp + 4]
// 00615a29  51                   push ecx
// 00615a2a  52                   push edx
// 00615a2b  e8b0fbffff           call 0x6155e0
// 00615a30  83c408               add esp, 8
// 00615a33  c3                   ret 
// 00615a34  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00615a38  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00615a3c  50                   push eax
// 00615a3d  51                   push ecx
// 00615a3e  e87df7ffff           call 0x6151c0
// 00615a43  83c408               add esp, 8
// 00615a46  c3                   ret 
// library lua-5.1.1/lcode.c (function _luaK_infix)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
