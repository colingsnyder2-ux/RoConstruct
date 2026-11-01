// from server: 100% by colin
// roc 2007-08 0054c190  unit: boost::iostreams::DUinput::V?$basic_null_device::?$stream_buffer  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054c190
//
// 0054c190  64a100000000         mov eax, dword ptr fs:[0]
// 0054c196  6aff                 push -1
// 0054c198  68b2417500           push 0x7541b2
// 0054c19d  50                   push eax
// 0054c19e  64892500000000       mov dword ptr fs:[0], esp
// 0054c1a5  83ec44               sub esp, 0x44
// 0054c1a8  56                   push esi
// 0054c1a9  8bf1                 mov esi, ecx
// 0054c1ab  f6465801             test byte ptr [esi + 0x58], 1
// 0054c1af  7470                 je 0x54c221
// 0054c1b1  6824797a00           push 0x7a7924
// 0054c1b6  8d4c2408             lea ecx, [esp + 8]
// 0054c1ba  ff1598e67700         call dword ptr [0x77e698]
// 0054c1c0  8d4c2420             lea ecx, [esp + 0x20]
// 0054c1c4  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0054c1cc  ff15f8e67700         call dword ptr [0x77e6f8]
// 0054c1d2  8d442404             lea eax, [esp + 4]
// 0054c1d6  50                   push eax
// 0054c1d7  8d4c2430             lea ecx, [esp + 0x30]
// 0054c1db  c644245401           mov byte ptr [esp + 0x54], 1
// 0054c1e0  c744242418707800     mov dword ptr [esp + 0x24], 0x787018
// 0054c1e8  ff159ce67700         call dword ptr [0x77e69c]
// 0054c1ee  8d4c242c             lea ecx, [esp + 0x2c]
// 0054c1f2  c644245000           mov byte ptr [esp + 0x50], 0
// 0054c1f7  c744242018707800     mov dword ptr [esp + 0x20], 0x787018
// 0054c1ff  ff15ace67700         call dword ptr [0x77e6ac]
// 0054c205  8d4c2420             lea ecx, [esp + 0x20]
// 0054c209  ff15f4e67700         call dword ptr [0x77e6f4]
// 0054c20f  8d4c2404             lea ecx, [esp + 4]
// 0054c213  c7442450ffffffff     mov dword ptr [esp + 0x50], 0xffffffff
// 0054c21b  ff15ace67700         call dword ptr [0x77e6ac]
// 0054c221  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0054c225  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 0054c229  8b442458             mov eax, dword ptr [esp + 0x58]
// 0054c22d  51                   push ecx
// 0054c22e  52                   push edx
// 0054c22f  50                   push eax
// 0054c230  8bce                 mov ecx, esi
// 0054c232  e829f5ffff           call 0x54b760
// 0054c237  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0054c23b  5e                   pop esi
// 0054c23c  64890d00000000       mov dword ptr fs:[0], ecx
// 0054c243  83c450               add esp, 0x50
// 0054c246  c20c00               ret 0xc
// copied from an identical function in another client (function ?open_impl@?$stream_buffer@V?$reference_wrapper@V?$basic_istream@DU?$char_traits@D@std@@@std@@@boost@@U?$char_traits@D@std@@V?$allocator@D@4@Uinput_seekable@iostreams@2@@iostreams@boost@@AAEXABV?$reference_wrapper@V?$basic_istream@DU?$char_traits@D@std@@@std@@@3@HH@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1-dll roc_boost_resume_389d0bd197ae56e1.cpp