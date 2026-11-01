// from server: 100% by colin
// roc 2007-08 0054b760  unit: UString_sink::?$stream_buffer  size: 165 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054b760
//
// 0054b760  56                   push esi
// 0054b761  8bf1                 mov esi, ecx
// 0054b763  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0054b767  83f9ff               cmp ecx, -1
// 0054b76a  7505                 jne 0x54b771
// 0054b76c  b900100000           mov ecx, 0x1000
// 0054b771  8b442410             mov eax, dword ptr [esp + 0x10]
// 0054b775  83f8ff               cmp eax, -1
// 0054b778  7509                 jne 0x54b783
// 0054b77a  b804000000           mov eax, 4
// 0054b77f  89442410             mov dword ptr [esp + 0x10], eax
// 0054b783  83f802               cmp eax, 2
// 0054b786  c744240c02000000     mov dword ptr [esp + 0xc], 2
// 0054b78e  8d442410             lea eax, [esp + 0x10]
// 0054b792  7f04                 jg 0x54b798
// 0054b794  8d44240c             lea eax, [esp + 0xc]
// 0054b798  85c9                 test ecx, ecx
// 0054b79a  8b00                 mov eax, dword ptr [eax]
// 0054b79c  894654               mov dword ptr [esi + 0x54], eax
// 0054b79f  7505                 jne 0x54b7a6
// 0054b7a1  b901000000           mov ecx, 1
// 0054b7a6  57                   push edi
// 0054b7a7  8d3c08               lea edi, [eax + ecx]
// 0054b7aa  397e50               cmp dword ptr [esi + 0x50], edi
// 0054b7ad  7429                 je 0x54b7d8
// 0054b7af  6a00                 push 0
// 0054b7b1  57                   push edi
// 0054b7b2  8d4c241c             lea ecx, [esp + 0x1c]
// 0054b7b6  ff1518e67700         call dword ptr [0x77e618]
// 0054b7bc  8b5650               mov edx, dword ptr [esi + 0x50]
// 0054b7bf  897e50               mov dword ptr [esi + 0x50], edi
// 0054b7c2  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 0054b7c5  85c9                 test ecx, ecx
// 0054b7c7  89464c               mov dword ptr [esi + 0x4c], eax
// 0054b7ca  740c                 je 0x54b7d8
// 0054b7cc  52                   push edx
// 0054b7cd  51                   push ecx
// 0054b7ce  8d4c241c             lea ecx, [esp + 0x1c]
// 0054b7d2  ff1510e67700         call dword ptr [0x77e610]
// 0054b7d8  8b06                 mov eax, dword ptr [esi]
// 0054b7da  8b5054               mov edx, dword ptr [eax + 0x54]
// 0054b7dd  8bce                 mov ecx, esi
// 0054b7df  ffd2                 call edx
// 0054b7e1  807e4400             cmp byte ptr [esi + 0x44], 0
// 0054b7e5  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0054b7e9  8b00                 mov eax, dword ptr [eax]
// 0054b7eb  5f                   pop edi
// 0054b7ec  7404                 je 0x54b7f2
// 0054b7ee  c6464400             mov byte ptr [esi + 0x44], 0
// 0054b7f2  894640               mov dword ptr [esi + 0x40], eax
// 0054b7f5  c6464401             mov byte ptr [esi + 0x44], 1
// 0054b7f9  834e5801             or dword ptr [esi + 0x58], 1
// 0054b7fd  c6463c00             mov byte ptr [esi + 0x3c], 0
// 0054b801  5e                   pop esi
// 0054b802  c20c00               ret 0xc
// copied from an identical function in another client (function ?open@?$indirect_streambuf@V?$reference_wrapper@V?$basic_istream@DU?$char_traits@D@std@@@std@@@boost@@U?$char_traits@D@std@@V?$allocator@D@4@Uinput_seekable@iostreams@2@@detail@iostreams@boost@@QAEXABV?$reference_wrapper@V?$basic_istream@DU?$char_traits@D@std@@@std@@@4@HH@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1-dll roc_boost_resume_389d0bd197ae56e1.cpp