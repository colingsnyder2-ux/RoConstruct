// from server: 100% by Yeetserama
// roc 2010-06 0052bc30  unit: boost::Vbad_lexical_cast::U?$error_info_injector::?$clone_impl  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0052bc30
//
// 0052bc30  83ec18               sub esp, 0x18
// 0052bc33  53                   push ebx
// 0052bc34  8b19                 mov ebx, dword ptr [ecx]
// 0052bc36  55                   push ebp
// 0052bc37  56                   push esi
// 0052bc38  8b742428             mov esi, dword ptr [esp + 0x28]
// 0052bc3c  57                   push edi
// 0052bc3d  8b7904               mov edi, dword ptr [ecx + 4]
// 0052bc40  8d442418             lea eax, [esp + 0x18]
// 0052bc44  50                   push eax
// 0052bc45  8bce                 mov ecx, esi
// 0052bc47  ff153ca59e00         call dword ptr [0x9ea53c]
// 0052bc4d  8b4804               mov ecx, dword ptr [eax + 4]
// 0052bc50  8b28                 mov ebp, dword ptr [eax]
// 0052bc52  8d542420             lea edx, [esp + 0x20]
// 0052bc56  894c2414             mov dword ptr [esp + 0x14], ecx
// 0052bc5a  52                   push edx
// 0052bc5b  8bce                 mov ecx, esi
// 0052bc5d  ff1540a59e00         call dword ptr [0x9ea540]
// 0052bc63  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0052bc67  8b542414             mov edx, dword ptr [esp + 0x14]
// 0052bc6b  51                   push ecx
// 0052bc6c  8b4804               mov ecx, dword ptr [eax + 4]
// 0052bc6f  57                   push edi
// 0052bc70  53                   push ebx
// 0052bc71  52                   push edx
// 0052bc72  8b10                 mov edx, dword ptr [eax]
// 0052bc74  55                   push ebp
// 0052bc75  51                   push ecx
// 0052bc76  52                   push edx
// 0052bc77  8bce                 mov ecx, esi
// 0052bc79  e8b2feffff           call 0x52bb30
// 0052bc7e  5f                   pop edi
// 0052bc7f  5e                   pop esi
// 0052bc80  5d                   pop ebp
// 0052bc81  b001                 mov al, 1
// 0052bc83  5b                   pop ebx
// 0052bc84  83c418               add esp, 0x18
// 0052bc87  c20400               ret 4
// copied from an identical function in another client (function ??$?5V?$allocator@D@std@@@?$lexical_stream_limited_src@DUlexical_streambuf_fake@detail@boost@@U?$char_traits@D@std@@@detail@boost@@QAE_NAAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.35.0-dll libs/program_options/src/value_semantic.cpp