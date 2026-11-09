// roc 2012-06 00567f10  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00567f10
//
// 00567f10  56                   push esi
// 00567f11  57                   push edi
// 00567f12  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00567f16  8bf1                 mov esi, ecx
// 00567f18  85ff                 test edi, edi
// 00567f1a  7450                 je 0x567f6c
// 00567f1c  f60607               test byte ptr [esi], 7
// 00567f1f  7535                 jne 0x567f56
// 00567f21  8d04fd00000000       lea eax, [edi*8]
// 00567f28  50                   push eax
// 00567f29  e842faffff           call 0x567970
// 00567f2e  8b16                 mov edx, dword ptr [esi]
// 00567f30  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00567f34  83c207               add edx, 7
// 00567f37  c1ea03               shr edx, 3
// 00567f3a  03560c               add edx, dword ptr [esi + 0xc]
// 00567f3d  57                   push edi
// 00567f3e  51                   push ecx
// 00567f3f  52                   push edx
// 00567f40  e817b74100           call 0x98365c
// 00567f45  83c40c               add esp, 0xc
// 00567f48  8d04fd00000000       lea eax, [edi*8]
// 00567f4f  0106                 add dword ptr [esi], eax
// 00567f51  5f                   pop edi
// 00567f52  5e                   pop esi
// 00567f53  c20800               ret 8
// 00567f56  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00567f5a  6a01                 push 1
// 00567f5c  8d0cfd00000000       lea ecx, [edi*8]
// 00567f63  51                   push ecx
// 00567f64  52                   push edx
// 00567f65  8bce                 mov ecx, esi
// 00567f67  e824feffff           call 0x567d90
// 00567f6c  5f                   pop edi
// 00567f6d  5e                   pop esi
// 00567f6e  c20800               ret 8
// copied from an identical function in another client (function ?Write@BitStream@RakNet@@QAEXPBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 BitStream.cpp