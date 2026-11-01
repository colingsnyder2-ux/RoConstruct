// from server: 100% by colin
// roc 2007-08 0054dba0  unit: boost::iostreams::DUoutput::V?$basic_null_device::?$stream_buffer  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054dba0
//
// 0054dba0  8b5120               mov edx, dword ptr [ecx + 0x20]
// 0054dba3  8b4110               mov eax, dword ptr [ecx + 0x10]
// 0054dba6  8b12                 mov edx, dword ptr [edx]
// 0054dba8  83ec28               sub esp, 0x28
// 0054dbab  3b10                 cmp edx, dword ptr [eax]
// 0054dbad  742a                 je 0x54dbd9
// 0054dbaf  8b4130               mov eax, dword ptr [ecx + 0x30]
// 0054dbb2  830001               add dword ptr [eax], 1
// 0054dbb5  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0054dbb8  8300ff               add dword ptr [eax], -1
// 0054dbbb  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0054dbbf  83f8ff               cmp eax, -1
// 0054dbc2  740d                 je 0x54dbd1
// 0054dbc4  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0054dbc7  8b11                 mov edx, dword ptr [ecx]
// 0054dbc9  8802                 mov byte ptr [edx], al
// 0054dbcb  83c428               add esp, 0x28
// 0054dbce  c20400               ret 4
// 0054dbd1  33c0                 xor eax, eax
// 0054dbd3  83c428               add esp, 0x28
// 0054dbd6  c20400               ret 4
// 0054dbd9  8d0424               lea eax, [esp]
// 0054dbdc  50                   push eax
// 0054dbdd  e82ed7ffff           call 0x54b310
// 0054dbe2  83c404               add esp, 4
// 0054dbe5  68c49a8500           push 0x859ac4
// 0054dbea  8d4c2404             lea ecx, [esp + 4]
// 0054dbee  51                   push ecx
// 0054dbef  e8aa2f0e00           call 0x630b9e
// copied from an identical function in another client (function ?pbackfail@?$indirect_streambuf@V?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@iostreams@boost@@U?$char_traits@D@std@@V?$allocator@D@5@Uoutput@23@@detail@iostreams@boost@@MAEHH@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_string_sink_401c42386b16c308.cpp