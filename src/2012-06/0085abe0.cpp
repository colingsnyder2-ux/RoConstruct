// roc 2012-06 0085abe0  unit: boost::iostreams::DUoutput::V?$basic_null_device::?$stream_buffer  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0085abe0
//
// 0085abe0  64a100000000         mov eax, dword ptr fs:[0]
// 0085abe6  6aff                 push -1
// 0085abe8  684269aa00           push 0xaa6942
// 0085abed  50                   push eax
// 0085abee  64892500000000       mov dword ptr fs:[0], esp
// 0085abf5  83ec44               sub esp, 0x44
// 0085abf8  56                   push esi
// 0085abf9  8bf1                 mov esi, ecx
// 0085abfb  f6465801             test byte ptr [esi + 0x58], 1
// 0085abff  7470                 je 0x85ac71
// 0085ac01  683c45bd00           push 0xbd453c
// 0085ac06  8d4c2408             lea ecx, [esp + 8]
// 0085ac0a  ff154826b200         call dword ptr [0xb22648]
// 0085ac10  8d4c2420             lea ecx, [esp + 0x20]
// 0085ac14  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0085ac1c  ff15dc29b200         call dword ptr [0xb229dc]
// 0085ac22  8d442404             lea eax, [esp + 4]
// 0085ac26  50                   push eax
// 0085ac27  8d4c2430             lea ecx, [esp + 0x30]
// 0085ac2b  c644245401           mov byte ptr [esp + 0x54], 1
// 0085ac30  c74424244c3cb400     mov dword ptr [esp + 0x24], 0xb43c4c
// 0085ac38  ff154426b200         call dword ptr [0xb22644]
// 0085ac3e  8d4c242c             lea ecx, [esp + 0x2c]
// 0085ac42  c644245000           mov byte ptr [esp + 0x50], 0
// 0085ac47  c74424204c3cb400     mov dword ptr [esp + 0x20], 0xb43c4c
// 0085ac4f  ff153c26b200         call dword ptr [0xb2263c]
// 0085ac55  8d4c2420             lea ecx, [esp + 0x20]
// 0085ac59  ff15d829b200         call dword ptr [0xb229d8]
// 0085ac5f  8d4c2404             lea ecx, [esp + 4]
// 0085ac63  c7442450ffffffff     mov dword ptr [esp + 0x50], 0xffffffff
// 0085ac6b  ff153c26b200         call dword ptr [0xb2263c]
// 0085ac71  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0085ac75  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 0085ac79  8b442458             mov eax, dword ptr [esp + 0x58]
// 0085ac7d  51                   push ecx
// 0085ac7e  52                   push edx
// 0085ac7f  50                   push eax
// 0085ac80  8bce                 mov ecx, esi
// 0085ac82  e8a9f2ffff           call 0x859f30
// 0085ac87  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0085ac8b  5e                   pop esi
// 0085ac8c  64890d00000000       mov dword ptr fs:[0], ecx
// 0085ac93  83c450               add esp, 0x50
// 0085ac96  c20c00               ret 0xc
// copied from an identical function in another client (function ?open_impl@?$stream_buffer@V?$reference_wrapper@V?$basic_istream@DU?$char_traits@D@std@@@std@@@boost@@U?$char_traits@D@std@@V?$allocator@D@4@Uinput_seekable@iostreams@2@@iostreams@boost@@AAEXABV?$reference_wrapper@V?$basic_istream@DU?$char_traits@D@std@@@std@@@3@HH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1-dll roc_boost_resume_389d0bd197ae56e1.cpp