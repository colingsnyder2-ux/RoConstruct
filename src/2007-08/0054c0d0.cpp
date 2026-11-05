// from server: 100% by colin
// roc 2007-08 0054c0d0  unit: boost::iostreams::DUinput::V?$basic_null_device::?$stream_buffer  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054c0d0
//
// 0054c0d0  64a100000000         mov eax, dword ptr fs:[0]
// 0054c0d6  6aff                 push -1
// 0054c0d8  68b2417500           push 0x7541b2
// 0054c0dd  50                   push eax
// 0054c0de  64892500000000       mov dword ptr fs:[0], esp
// 0054c0e5  83ec44               sub esp, 0x44
// 0054c0e8  56                   push esi
// 0054c0e9  8bf1                 mov esi, ecx
// 0054c0eb  f6465801             test byte ptr [esi + 0x58], 1
// 0054c0ef  7470                 je 0x54c161
// 0054c0f1  6824797a00           push 0x7a7924
// 0054c0f6  8d4c2408             lea ecx, [esp + 8]
// 0054c0fa  ff1598e67700         call dword ptr [0x77e698]
// 0054c100  8d4c2420             lea ecx, [esp + 0x20]
// 0054c104  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0054c10c  ff15f8e67700         call dword ptr [0x77e6f8]
// 0054c112  8d442404             lea eax, [esp + 4]
// 0054c116  50                   push eax
// 0054c117  8d4c2430             lea ecx, [esp + 0x30]
// 0054c11b  c644245401           mov byte ptr [esp + 0x54], 1
// 0054c120  c744242418707800     mov dword ptr [esp + 0x24], 0x787018
// 0054c128  ff159ce67700         call dword ptr [0x77e69c]
// 0054c12e  8d4c242c             lea ecx, [esp + 0x2c]
// 0054c132  c644245000           mov byte ptr [esp + 0x50], 0
// 0054c137  c744242018707800     mov dword ptr [esp + 0x20], 0x787018
// 0054c13f  ff15ace67700         call dword ptr [0x77e6ac]
// 0054c145  8d4c2420             lea ecx, [esp + 0x20]
// 0054c149  ff15f4e67700         call dword ptr [0x77e6f4]
// 0054c14f  8d4c2404             lea ecx, [esp + 4]
// 0054c153  c7442450ffffffff     mov dword ptr [esp + 0x50], 0xffffffff
// 0054c15b  ff15ace67700         call dword ptr [0x77e6ac]
// 0054c161  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0054c165  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 0054c169  8b442458             mov eax, dword ptr [esp + 0x58]
// 0054c16d  51                   push ecx
// 0054c16e  52                   push edx
// 0054c16f  50                   push eax
// 0054c170  8bce                 mov ecx, esi
// 0054c172  e839f3ffff           call 0x54b4b0
// 0054c177  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0054c17b  5e                   pop esi
// 0054c17c  64890d00000000       mov dword ptr fs:[0], ecx
// 0054c183  83c450               add esp, 0x50
// 0054c186  c20c00               ret 0xc
// copied from an identical function in another client (function ?open_impl@?$stream_buffer@V?$reference_wrapper@V?$basic_istream@DU?$char_traits@D@std@@@std@@@boost@@U?$char_traits@D@std@@V?$allocator@D@4@Uinput_seekable@iostreams@2@@iostreams@boost@@AAEXABV?$reference_wrapper@V?$basic_istream@DU?$char_traits@D@std@@@std@@@3@HH@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1-dll roc_boost_resume_389d0bd197ae56e1.cpp