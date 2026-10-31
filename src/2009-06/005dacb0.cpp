// from server: 99% by EspClaude
// from server: 100% by auto
// roc 2008-06 00554f90  unit: RBX::RunService  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00554f90
//
// 00554f90  6aff                 push -1
// 00554f92  6818dd7c00           push 0x7cdd18
// 00554f97  64a100000000         mov eax, dword ptr fs:[0]
// 00554f9d  50                   push eax
// 00554f9e  64892500000000       mov dword ptr fs:[0], esp
// 00554fa5  83ec20               sub esp, 0x20
// 00554fa8  56                   push esi
// 00554fa9  8bf1                 mov esi, ecx
// 00554fab  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00554faf  8b01                 mov eax, dword ptr [ecx]
// 00554fb1  c744240400000000     mov dword ptr [esp + 4], 0
// 00554fb9  85c0                 test eax, eax
// 00554fbb  7416                 je 0x554fd3
// 00554fbd  6a00                 push 0
// 00554fbf  8d542410             lea edx, [esp + 0x10]
// 00554fc3  52                   push edx
// 00554fc4  83c108               add ecx, 8
// 00554fc7  8944240c             mov dword ptr [esp + 0xc], eax
// 00554fcb  8b00                 mov eax, dword ptr [eax]
// 00554fcd  51                   push ecx
// 00554fce  ffd0                 call eax
// 00554fd0  83c40c               add esp, 0xc
// 00554fd3  56                   push esi
// 00554fd4  8d4c2408             lea ecx, [esp + 8]
// 00554fd8  c744243000000000     mov dword ptr [esp + 0x30], 0
// 00554fe0  e8abfbffff           call 0x554b90
// 00554fe5  8b442404             mov eax, dword ptr [esp + 4]
// 00554fe9  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 00554ff1  85c0                 test eax, eax
// 00554ff3  7415                 je 0x55500a
// 00554ff5  8b00                 mov eax, dword ptr [eax]
// 00554ff7  85c0                 test eax, eax
// 00554ff9  740f                 je 0x55500a
// 00554ffb  8d4c240c             lea ecx, [esp + 0xc]
// 00554fff  6a01                 push 1
// 00555001  51                   push ecx
// 00555002  8bd1                 mov edx, ecx
// 00555004  52                   push edx
// 00555005  ffd0                 call eax
// 00555007  83c40c               add esp, 0xc
// 0055500a  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0055500e  8bc6                 mov eax, esi
// 00555010  5e                   pop esi
// 00555011  64890d00000000       mov dword ptr fs:[0], ecx
// 00555018  83c42c               add esp, 0x2c
// 0055501b  c20400               ret 4
// library templates-boost-1_34_1/function_b.cpp (function ??4?$function@$$A6AX_N@ZV?$allocator@X@std@@@boost@@QAEAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 function_b.cpp
