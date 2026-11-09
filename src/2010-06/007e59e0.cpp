// from server: 100% by auto
// roc 2010-06 007e59e0  unit: CXTTreeBase  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e59e0
//
// 007e59e0  56                   push esi
// 007e59e1  8bf1                 mov esi, ecx
// 007e59e3  8b4604               mov eax, dword ptr [esi + 4]
// 007e59e6  57                   push edi
// 007e59e7  85c0                 test eax, eax
// 007e59e9  7410                 je 0x7e59fb
// 007e59eb  50                   push eax
// 007e59ec  e85522fcff           call 0x7a7c46
// 007e59f1  83c404               add esp, 4
// 007e59f4  c7460400000000       mov dword ptr [esi + 4], 0
// 007e59fb  837c241000           cmp dword ptr [esp + 0x10], 0
// 007e5a00  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007e5a04  743a                 je 0x7e5a40
// 007e5a06  33c9                 xor ecx, ecx
// 007e5a08  8bc7                 mov eax, edi
// 007e5a0a  ba04000000           mov edx, 4
// 007e5a0f  f7e2                 mul edx
// 007e5a11  0f90c1               seto cl
// 007e5a14  f7d9                 neg ecx
// 007e5a16  0bc8                 or ecx, eax
// 007e5a18  51                   push ecx
// 007e5a19  e86422fcff           call 0x7a7c82
// 007e5a1e  83c404               add esp, 4
// 007e5a21  894604               mov dword ptr [esi + 4], eax
// 007e5a24  85c0                 test eax, eax
// 007e5a26  7505                 jne 0x7e5a2d
// 007e5a28  e81f22fcff           call 0x7a7c4c
// 007e5a2d  8d0cbd00000000       lea ecx, [edi*4]
// 007e5a34  51                   push ecx
// 007e5a35  6a00                 push 0
// 007e5a37  50                   push eax
// 007e5a38  e8a731fcff           call 0x7a8be4
// 007e5a3d  83c40c               add esp, 0xc
// 007e5a40  897e08               mov dword ptr [esi + 8], edi
// 007e5a43  5f                   pop edi
// 007e5a44  5e                   pop esi
// 007e5a45  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?InitHashTable@?$CMap@PAUHICON__@@PAU1@HH@@QAEXIH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
