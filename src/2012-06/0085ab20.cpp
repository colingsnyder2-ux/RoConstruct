// roc 2012-06 0085ab20  unit: boost::iostreams::DUoutput::V?$basic_null_device::?$stream_buffer  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0085ab20
//
// 0085ab20  64a100000000         mov eax, dword ptr fs:[0]
// 0085ab26  6aff                 push -1
// 0085ab28  684269aa00           push 0xaa6942
// 0085ab2d  50                   push eax
// 0085ab2e  64892500000000       mov dword ptr fs:[0], esp
// 0085ab35  83ec44               sub esp, 0x44
// 0085ab38  56                   push esi
// 0085ab39  8bf1                 mov esi, ecx
// 0085ab3b  f6465801             test byte ptr [esi + 0x58], 1
// 0085ab3f  7470                 je 0x85abb1
// 0085ab41  683c45bd00           push 0xbd453c
// 0085ab46  8d4c2408             lea ecx, [esp + 8]
// 0085ab4a  ff154826b200         call dword ptr [0xb22648]
// 0085ab50  8d4c2420             lea ecx, [esp + 0x20]
// 0085ab54  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0085ab5c  ff15dc29b200         call dword ptr [0xb229dc]
// 0085ab62  8d442404             lea eax, [esp + 4]
// 0085ab66  50                   push eax
// 0085ab67  8d4c2430             lea ecx, [esp + 0x30]
// 0085ab6b  c644245401           mov byte ptr [esp + 0x54], 1
// 0085ab70  c74424244c3cb400     mov dword ptr [esp + 0x24], 0xb43c4c
// 0085ab78  ff154426b200         call dword ptr [0xb22644]
// 0085ab7e  8d4c242c             lea ecx, [esp + 0x2c]
// 0085ab82  c644245000           mov byte ptr [esp + 0x50], 0
// 0085ab87  c74424204c3cb400     mov dword ptr [esp + 0x20], 0xb43c4c
// 0085ab8f  ff153c26b200         call dword ptr [0xb2263c]
// 0085ab95  8d4c2420             lea ecx, [esp + 0x20]
// 0085ab99  ff15d829b200         call dword ptr [0xb229d8]
// 0085ab9f  8d4c2404             lea ecx, [esp + 4]
// 0085aba3  c7442450ffffffff     mov dword ptr [esp + 0x50], 0xffffffff
// 0085abab  ff153c26b200         call dword ptr [0xb2263c]
// 0085abb1  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0085abb5  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 0085abb9  8b442458             mov eax, dword ptr [esp + 0x58]
// 0085abbd  51                   push ecx
// 0085abbe  52                   push edx
// 0085abbf  50                   push eax
// 0085abc0  8bce                 mov ecx, esi
// 0085abc2  e899f0ffff           call 0x859c60
// 0085abc7  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0085abcb  5e                   pop esi
// 0085abcc  64890d00000000       mov dword ptr fs:[0], ecx
// 0085abd3  83c450               add esp, 0x50
// 0085abd6  c20c00               ret 0xc
// copied from an identical function in another client (function ?open_impl@?$stream_buffer@V?$reference_wrapper@V?$basic_istream@DU?$char_traits@D@std@@@std@@@boost@@U?$char_traits@D@std@@V?$allocator@D@4@Uinput_seekable@iostreams@2@@iostreams@boost@@AAEXABV?$reference_wrapper@V?$basic_istream@DU?$char_traits@D@std@@@std@@@3@HH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1-dll roc_boost_resume_389d0bd197ae56e1.cpp