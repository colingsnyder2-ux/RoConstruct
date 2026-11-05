// roc 2012-06 00567a20  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00567a20
//
// 00567a20  56                   push esi
// 00567a21  8bf1                 mov esi, ecx
// 00567a23  8b06                 mov eax, dword ptr [esi]
// 00567a25  8d4807               lea ecx, [eax + 7]
// 00567a28  57                   push edi
// 00567a29  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00567a2d  c1e903               shr ecx, 3
// 00567a30  3bcf                 cmp ecx, edi
// 00567a32  7344                 jae 0x567a78
// 00567a34  8d50ff               lea edx, [eax - 1]
// 00567a37  83e207               and edx, 7
// 00567a3a  2bc2                 sub eax, edx
// 00567a3c  83c007               add eax, 7
// 00567a3f  8906                 mov dword ptr [esi], eax
// 00567a41  83c007               add eax, 7
// 00567a44  c1e803               shr eax, 3
// 00567a47  2bf8                 sub edi, eax
// 00567a49  8d04fd00000000       lea eax, [edi*8]
// 00567a50  50                   push eax
// 00567a51  8bce                 mov ecx, esi
// 00567a53  e818ffffff           call 0x567970
// 00567a58  8b0e                 mov ecx, dword ptr [esi]
// 00567a5a  83c107               add ecx, 7
// 00567a5d  c1e903               shr ecx, 3
// 00567a60  034e0c               add ecx, dword ptr [esi + 0xc]
// 00567a63  57                   push edi
// 00567a64  6a00                 push 0
// 00567a66  51                   push ecx
// 00567a67  e808b94100           call 0x983374
// 00567a6c  8d14fd00000000       lea edx, [edi*8]
// 00567a73  83c40c               add esp, 0xc
// 00567a76  0116                 add dword ptr [esi], edx
// 00567a78  5f                   pop edi
// 00567a79  5e                   pop esi
// 00567a7a  c20400               ret 4
// copied from an identical function in another client (function ?PadWithZeroToByteLength@BitStream@RakNet@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 BitStream.cpp