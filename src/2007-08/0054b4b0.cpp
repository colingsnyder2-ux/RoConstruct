// from server: 100% by colin
// roc 2007-08 0054b4b0  unit: UString_sink::?$stream_buffer  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054b4b0
//
// 0054b4b0  56                   push esi
// 0054b4b1  57                   push edi
// 0054b4b2  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0054b4b6  83ffff               cmp edi, -1
// 0054b4b9  8bf1                 mov esi, ecx
// 0054b4bb  7507                 jne 0x54b4c4
// 0054b4bd  bf00100000           mov edi, 0x1000
// 0054b4c2  eb04                 jmp 0x54b4c8
// 0054b4c4  85ff                 test edi, edi
// 0054b4c6  7409                 je 0x54b4d1
// 0054b4c8  57                   push edi
// 0054b4c9  8d4e4c               lea ecx, [esi + 0x4c]
// 0054b4cc  e8dff9ffff           call 0x54aeb0
// 0054b4d1  8b06                 mov eax, dword ptr [esi]
// 0054b4d3  8b5058               mov edx, dword ptr [eax + 0x58]
// 0054b4d6  8bce                 mov ecx, esi
// 0054b4d8  ffd2                 call edx
// 0054b4da  807e4400             cmp byte ptr [esi + 0x44], 0
// 0054b4de  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0054b4e2  8b00                 mov eax, dword ptr [eax]
// 0054b4e4  7404                 je 0x54b4ea
// 0054b4e6  c6464400             mov byte ptr [esi + 0x44], 0
// 0054b4ea  b901000000           mov ecx, 1
// 0054b4ef  894640               mov dword ptr [esi + 0x40], eax
// 0054b4f2  884e44               mov byte ptr [esi + 0x44], cl
// 0054b4f5  094e58               or dword ptr [esi + 0x58], ecx
// 0054b4f8  3bf9                 cmp edi, ecx
// 0054b4fa  8b4658               mov eax, dword ptr [esi + 0x58]
// 0054b4fd  c6463c00             mov byte ptr [esi + 0x3c], 0
// 0054b501  7e06                 jle 0x54b509
// 0054b503  83c808               or eax, 8
// 0054b506  894658               mov dword ptr [esi + 0x58], eax
// 0054b509  5f                   pop edi
// 0054b50a  5e                   pop esi
// 0054b50b  c20c00               ret 0xc
// copied from an identical function in another client (function ?open@?$indirect_streambuf@V?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@iostreams@boost@@U?$char_traits@D@std@@V?$allocator@D@5@Uoutput@23@@detail@iostreams@boost@@QAEXABV?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@34@HH@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_string_sink_401c42386b16c308.cpp