// roc 2012-06 0085bc80  unit: boost::iostreams::Uoutput::?$filtering_stream  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0085bc80
//
// 0085bc80  6aff                 push -1
// 0085bc82  6878e3ac00           push 0xace378
// 0085bc87  64a100000000         mov eax, dword ptr fs:[0]
// 0085bc8d  50                   push eax
// 0085bc8e  64892500000000       mov dword ptr fs:[0], esp
// 0085bc95  51                   push ecx
// 0085bc96  56                   push esi
// 0085bc97  8bf1                 mov esi, ecx
// 0085bc99  8b4608               mov eax, dword ptr [esi + 8]
// 0085bc9c  c706f046bd00         mov dword ptr [esi], 0xbd46f0
// 0085bca2  8b4804               mov ecx, dword ptr [eax + 4]
// 0085bca5  89742404             mov dword ptr [esp + 4], esi
// 0085bca9  c7443108e846bd00     mov dword ptr [ecx + esi + 8], 0xbd46e8
// 0085bcb1  8b4604               mov eax, dword ptr [esi + 4]
// 0085bcb4  8b00                 mov eax, dword ptr [eax]
// 0085bcb6  f6401c01             test byte ptr [eax + 0x1c], 1
// 0085bcba  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0085bcc2  7410                 je 0x85bcd4
// 0085bcc4  8b5608               mov edx, dword ptr [esi + 8]
// 0085bcc7  8b4204               mov eax, dword ptr [edx + 4]
// 0085bcca  8b4c3030             mov ecx, dword ptr [eax + esi + 0x30]
// 0085bcce  ff158425b200         call dword ptr [0xb22584]
// 0085bcd4  8bce                 mov ecx, esi
// 0085bcd6  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0085bcde  e84df4ffff           call 0x85b130
// 0085bce3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0085bce7  5e                   pop esi
// 0085bce8  64890d00000000       mov dword ptr fs:[0], ecx
// 0085bcef  83c410               add esp, 0x10
// 0085bcf2  c3                   ret 
// copied from an identical function in another client (function ??1?$filtering_stream@Uinput@iostreams@boost@@DU?$char_traits@D@std@@V?$allocator@D@5@Upublic_@23@@iostreams@boost@@UAE@XZ)

// roc-cl: 50727
// roc-lang: cpp
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1-dll roc_boost_resume_1a066d61bcfa73c0.cpp