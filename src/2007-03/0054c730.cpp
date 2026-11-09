// from server: 100% by colin
// roc 2007-03 0054c730  unit: seg_00540000  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0054c730
//
// 0054c730  8b5120               mov edx, dword ptr [ecx + 0x20]
// 0054c733  8b4110               mov eax, dword ptr [ecx + 0x10]
// 0054c736  8b12                 mov edx, dword ptr [edx]
// 0054c738  83ec28               sub esp, 0x28
// 0054c73b  3b10                 cmp edx, dword ptr [eax]
// 0054c73d  742a                 je 0x54c769
// 0054c73f  8b4130               mov eax, dword ptr [ecx + 0x30]
// 0054c742  830001               add dword ptr [eax], 1
// 0054c745  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0054c748  8300ff               add dword ptr [eax], -1
// 0054c74b  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0054c74f  83f8ff               cmp eax, -1
// 0054c752  740d                 je 0x54c761
// 0054c754  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0054c757  8b11                 mov edx, dword ptr [ecx]
// 0054c759  8802                 mov byte ptr [edx], al
// 0054c75b  83c428               add esp, 0x28
// 0054c75e  c20400               ret 4
// 0054c761  33c0                 xor eax, eax
// 0054c763  83c428               add esp, 0x28
// 0054c766  c20400               ret 4
// 0054c769  8d0424               lea eax, [esp]
// 0054c76c  50                   push eax
// 0054c76d  e87ee2ffff           call 0x54a9f0
// 0054c772  83c404               add esp, 4
// 0054c775  68dc818500           push 0x8581dc
// 0054c77a  8d4c2404             lea ecx, [esp + 4]
// 0054c77e  51                   push ecx
// 0054c77f  e8aa280d00           call 0x61f02e
// copied from an identical function in another client (function ?pbackfail@?$indirect_streambuf@V?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@iostreams@boost@@U?$char_traits@D@std@@V?$allocator@D@5@Uoutput@23@@detail@iostreams@boost@@MAEHH@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_string_sink_401c42386b16c308.cpp