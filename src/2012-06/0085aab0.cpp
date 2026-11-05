// roc 2012-06 0085aab0  unit: boost::iostreams::DUoutput::V?$basic_null_device::?$stream_buffer  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0085aab0
//
// 0085aab0  6aff                 push -1
// 0085aab2  6823e2ac00           push 0xace223
// 0085aab7  64a100000000         mov eax, dword ptr fs:[0]
// 0085aabd  50                   push eax
// 0085aabe  64892500000000       mov dword ptr fs:[0], esp
// 0085aac5  83ec08               sub esp, 8
// 0085aac8  56                   push esi
// 0085aac9  8bf1                 mov esi, ecx
// 0085aacb  89742408             mov dword ptr [esp + 8], esi
// 0085aacf  8b464c               mov eax, dword ptr [esi + 0x4c]
// 0085aad2  c744241401000000     mov dword ptr [esp + 0x14], 1
// 0085aada  85c0                 test eax, eax
// 0085aadc  740f                 je 0x85aaed
// 0085aade  8b4e50               mov ecx, dword ptr [esi + 0x50]
// 0085aae1  51                   push ecx
// 0085aae2  50                   push eax
// 0085aae3  8d4c240f             lea ecx, [esp + 0xf]
// 0085aae7  ff15f825b200         call dword ptr [0xb225f8]
// 0085aaed  807e4400             cmp byte ptr [esi + 0x44], 0
// 0085aaf1  7404                 je 0x85aaf7
// 0085aaf3  c6464400             mov byte ptr [esi + 0x44], 0
// 0085aaf7  8bce                 mov ecx, esi
// 0085aaf9  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0085ab01  ff15b424b200         call dword ptr [0xb224b4]
// 0085ab07  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0085ab0b  5e                   pop esi
// 0085ab0c  64890d00000000       mov dword ptr fs:[0], ecx
// 0085ab13  83c414               add esp, 0x14
// 0085ab16  c3                   ret 
// copied from an identical function in another client (function ??1?$indirect_streambuf@V?$reference_wrapper@V?$basic_istream@DU?$char_traits@D@std@@@std@@@boost@@U?$char_traits@D@std@@V?$allocator@D@4@Uinput_seekable@iostreams@2@@detail@iostreams@boost@@UAE@XZ)

// roc-cl: 21022
// roc-lang: cpp
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1-dll roc_boost_resume_389d0bd197ae56e1.cpp