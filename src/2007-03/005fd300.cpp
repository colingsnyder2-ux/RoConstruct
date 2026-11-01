// from server: 100% by auto
// roc 2007-03 005fd300  unit: seg_005f0000  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fd300
//
// 005fd300  83ec20               sub esp, 0x20
// 005fd303  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005fd307  8b442424             mov eax, dword ptr [esp + 0x24]
// 005fd30b  8b542430             mov edx, dword ptr [esp + 0x30]
// 005fd30f  894c2410             mov dword ptr [esp + 0x10], ecx
// 005fd313  8944240c             mov dword ptr [esp + 0xc], eax
// 005fd317  8b442434             mov eax, dword ptr [esp + 0x34]
// 005fd31b  8d0c24               lea ecx, [esp]
// 005fd31e  51                   push ecx
// 005fd31f  89542418             mov dword ptr [esp + 0x18], edx
// 005fd323  8944241c             mov dword ptr [esp + 0x1c], eax
// 005fd327  c744242000000000     mov dword ptr [esp + 0x20], 0
// 005fd32f  e8ac380000           call 0x600be0
// 005fd334  83c404               add esp, 4
// 005fd337  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 005fd33c  751c                 jne 0x5fd35a
// 005fd33e  8b542414             mov edx, dword ptr [esp + 0x14]
// 005fd342  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005fd346  52                   push edx
// 005fd347  6a0c                 push 0xc
// 005fd349  8d442408             lea eax, [esp + 8]
// 005fd34d  50                   push eax
// 005fd34e  51                   push ecx
// 005fd34f  ff542420             call dword ptr [esp + 0x20]
// 005fd353  83c410               add esp, 0x10
// 005fd356  8944241c             mov dword ptr [esp + 0x1c], eax
// 005fd35a  8b442428             mov eax, dword ptr [esp + 0x28]
// 005fd35e  8d54240c             lea edx, [esp + 0xc]
// 005fd362  52                   push edx
// 005fd363  6a00                 push 0
// 005fd365  50                   push eax
// 005fd366  e825feffff           call 0x5fd190
// 005fd36b  8b442428             mov eax, dword ptr [esp + 0x28]
// 005fd36f  83c42c               add esp, 0x2c
// 005fd372  c3                   ret 
// library lua-5.1.1/ldump.c (function _luaU_dump)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldump.c
