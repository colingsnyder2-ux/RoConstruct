// from server: 100% by auto
// roc 2009-12 0052f210  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0052f210
//
// 0052f210  56                   push esi
// 0052f211  57                   push edi
// 0052f212  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0052f216  8bf1                 mov esi, ecx
// 0052f218  85ff                 test edi, edi
// 0052f21a  7450                 je 0x52f26c
// 0052f21c  f60607               test byte ptr [esi], 7
// 0052f21f  7535                 jne 0x52f256
// 0052f221  8d04fd00000000       lea eax, [edi*8]
// 0052f228  50                   push eax
// 0052f229  e822fbffff           call 0x52ed50
// 0052f22e  8b16                 mov edx, dword ptr [esi]
// 0052f230  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0052f234  83c207               add edx, 7
// 0052f237  c1ea03               shr edx, 3
// 0052f23a  03560c               add edx, dword ptr [esi + 0xc]
// 0052f23d  57                   push edi
// 0052f23e  51                   push ecx
// 0052f23f  52                   push edx
// 0052f240  e8a15a2c00           call 0x7f4ce6
// 0052f245  83c40c               add esp, 0xc
// 0052f248  8d04fd00000000       lea eax, [edi*8]
// 0052f24f  0106                 add dword ptr [esi], eax
// 0052f251  5f                   pop edi
// 0052f252  5e                   pop esi
// 0052f253  c20800               ret 8
// 0052f256  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0052f25a  6a01                 push 1
// 0052f25c  8d0cfd00000000       lea ecx, [edi*8]
// 0052f263  51                   push ecx
// 0052f264  52                   push edx
// 0052f265  8bce                 mov ecx, esi
// 0052f267  e8d4fdffff           call 0x52f040
// 0052f26c  5f                   pop edi
// 0052f26d  5e                   pop esi
// 0052f26e  c20800               ret 8
// library raknet-4.081/BitStream.cpp (function ?Write@BitStream@RakNet@@QAEXPBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 BitStream.cpp
