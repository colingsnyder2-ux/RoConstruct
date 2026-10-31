// from server: 100% by EspClaude
// roc 2009-06 00565290  unit: boost::Vbad_lexical_cast::U?$error_info_injector::?$clone_impl  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00565290
//
// 00565290  83ec18               sub esp, 0x18
// 00565293  53                   push ebx
// 00565294  8b19                 mov ebx, dword ptr [ecx]
// 00565296  55                   push ebp
// 00565297  56                   push esi
// 00565298  8b742428             mov esi, dword ptr [esp + 0x28]
// 0056529c  57                   push edi
// 0056529d  8b7904               mov edi, dword ptr [ecx + 4]
// 005652a0  8d442418             lea eax, [esp + 0x18]
// 005652a4  50                   push eax
// 005652a5  8bce                 mov ecx, esi
// 005652a7  ff15e4e48900         call dword ptr [0x89e4e4]
// 005652ad  8b4804               mov ecx, dword ptr [eax + 4]
// 005652b0  8b28                 mov ebp, dword ptr [eax]
// 005652b2  8d542420             lea edx, [esp + 0x20]
// 005652b6  894c2414             mov dword ptr [esp + 0x14], ecx
// 005652ba  52                   push edx
// 005652bb  8bce                 mov ecx, esi
// 005652bd  ff15e8e48900         call dword ptr [0x89e4e8]
// 005652c3  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005652c7  8b542414             mov edx, dword ptr [esp + 0x14]
// 005652cb  51                   push ecx
// 005652cc  8b4804               mov ecx, dword ptr [eax + 4]
// 005652cf  57                   push edi
// 005652d0  53                   push ebx
// 005652d1  52                   push edx
// 005652d2  8b10                 mov edx, dword ptr [eax]
// 005652d4  55                   push ebp
// 005652d5  51                   push ecx
// 005652d6  52                   push edx
// 005652d7  8bce                 mov ecx, esi
// 005652d9  e8b2feffff           call 0x565190
// 005652de  5f                   pop edi
// 005652df  5e                   pop esi
// 005652e0  5d                   pop ebp
// 005652e1  b001                 mov al, 1
// 005652e3  5b                   pop ebx
// 005652e4  83c418               add esp, 0x18
// 005652e7  c20400               ret 4
// copied from an identical function in another client (function ??$?5V?$allocator@D@std@@@?$lexical_stream_limited_src@DUlexical_streambuf_fake@detail@boost@@U?$char_traits@D@std@@@detail@boost@@QAE_NAAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.35.0-dll libs/program_options/src/value_semantic.cpp