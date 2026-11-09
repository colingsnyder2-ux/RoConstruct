// from server: 100% by colin
// roc 2007-08 0054c060  unit: boost::iostreams::DUinput::V?$basic_null_device::?$stream_buffer  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054c060
//
// 0054c060  6aff                 push -1
// 0054c062  68f3247500           push 0x7524f3
// 0054c067  64a100000000         mov eax, dword ptr fs:[0]
// 0054c06d  50                   push eax
// 0054c06e  64892500000000       mov dword ptr fs:[0], esp
// 0054c075  83ec08               sub esp, 8
// 0054c078  56                   push esi
// 0054c079  8bf1                 mov esi, ecx
// 0054c07b  89742408             mov dword ptr [esp + 8], esi
// 0054c07f  8b464c               mov eax, dword ptr [esi + 0x4c]
// 0054c082  85c0                 test eax, eax
// 0054c084  c744241401000000     mov dword ptr [esp + 0x14], 1
// 0054c08c  740f                 je 0x54c09d
// 0054c08e  8b4e50               mov ecx, dword ptr [esi + 0x50]
// 0054c091  51                   push ecx
// 0054c092  50                   push eax
// 0054c093  8d4c240f             lea ecx, [esp + 0xf]
// 0054c097  ff1510e67700         call dword ptr [0x77e610]
// 0054c09d  807e4400             cmp byte ptr [esi + 0x44], 0
// 0054c0a1  7404                 je 0x54c0a7
// 0054c0a3  c6464400             mov byte ptr [esi + 0x44], 0
// 0054c0a7  8bce                 mov ecx, esi
// 0054c0a9  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0054c0b1  ff151ce57700         call dword ptr [0x77e51c]
// 0054c0b7  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0054c0bb  5e                   pop esi
// 0054c0bc  64890d00000000       mov dword ptr fs:[0], ecx
// 0054c0c3  83c414               add esp, 0x14
// 0054c0c6  c3                   ret 
// copied from an identical function in another client (function ??1?$indirect_streambuf@V?$reference_wrapper@V?$basic_istream@DU?$char_traits@D@std@@@std@@@boost@@U?$char_traits@D@std@@V?$allocator@D@4@Uinput_seekable@iostreams@2@@detail@iostreams@boost@@UAE@XZ)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1-dll roc_boost_resume_389d0bd197ae56e1.cpp