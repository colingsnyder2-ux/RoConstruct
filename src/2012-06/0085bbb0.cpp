// roc 2012-06 0085bbb0  unit: VWinHttpRequest_source::?$stream_buffer  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0085bbb0
//
// 0085bbb0  6aff                 push -1
// 0085bbb2  6858e3ac00           push 0xace358
// 0085bbb7  64a100000000         mov eax, dword ptr fs:[0]
// 0085bbbd  50                   push eax
// 0085bbbe  64892500000000       mov dword ptr fs:[0], esp
// 0085bbc5  51                   push ecx
// 0085bbc6  56                   push esi
// 0085bbc7  8bf1                 mov esi, ecx
// 0085bbc9  8b4608               mov eax, dword ptr [esi + 8]
// 0085bbcc  c706dc46bd00         mov dword ptr [esi], 0xbd46dc
// 0085bbd2  8b4804               mov ecx, dword ptr [eax + 4]
// 0085bbd5  89742404             mov dword ptr [esp + 4], esi
// 0085bbd9  c7443108d446bd00     mov dword ptr [ecx + esi + 8], 0xbd46d4
// 0085bbe1  8b4604               mov eax, dword ptr [esi + 4]
// 0085bbe4  8b00                 mov eax, dword ptr [eax]
// 0085bbe6  f6401c01             test byte ptr [eax + 0x1c], 1
// 0085bbea  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0085bbf2  7410                 je 0x85bc04
// 0085bbf4  8b5608               mov edx, dword ptr [esi + 8]
// 0085bbf7  8b4204               mov eax, dword ptr [edx + 4]
// 0085bbfa  8b4c3030             mov ecx, dword ptr [eax + esi + 0x30]
// 0085bbfe  ff158425b200         call dword ptr [0xb22584]
// 0085bc04  8bce                 mov ecx, esi
// 0085bc06  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0085bc0e  e89df4ffff           call 0x85b0b0
// 0085bc13  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0085bc17  5e                   pop esi
// 0085bc18  64890d00000000       mov dword ptr fs:[0], ecx
// 0085bc1f  83c410               add esp, 0x10
// 0085bc22  c3                   ret 
// copied from an identical function in another client (function ??1?$filtering_stream@Uinput@iostreams@boost@@DU?$char_traits@D@std@@V?$allocator@D@5@Upublic_@23@@iostreams@boost@@UAE@XZ)

// roc-cl: 50727
// roc-lang: cpp
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1-dll roc_boost_resume_1a066d61bcfa73c0.cpp