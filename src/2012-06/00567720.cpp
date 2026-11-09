// roc 2012-06 00567720  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00567720
//
// 00567720  56                   push esi
// 00567721  8bf1                 mov esi, ecx
// 00567723  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00567727  85c9                 test ecx, ecx
// 00567729  7706                 ja 0x567731
// 0056772b  32c0                 xor al, al
// 0056772d  5e                   pop esi
// 0056772e  c20800               ret 8
// 00567731  8b4608               mov eax, dword ptr [esi + 8]
// 00567734  8d50ff               lea edx, [eax - 1]
// 00567737  83e207               and edx, 7
// 0056773a  2bc2                 sub eax, edx
// 0056773c  83c007               add eax, 7
// 0056773f  57                   push edi
// 00567740  8d3ccd00000000       lea edi, [ecx*8]
// 00567747  8d1407               lea edx, [edi + eax]
// 0056774a  894608               mov dword ptr [esi + 8], eax
// 0056774d  3b16                 cmp edx, dword ptr [esi]
// 0056774f  7607                 jbe 0x567758
// 00567751  5f                   pop edi
// 00567752  32c0                 xor al, al
// 00567754  5e                   pop esi
// 00567755  c20800               ret 8
// 00567758  c1e803               shr eax, 3
// 0056775b  03460c               add eax, dword ptr [esi + 0xc]
// 0056775e  51                   push ecx
// 0056775f  50                   push eax
// 00567760  8b442414             mov eax, dword ptr [esp + 0x14]
// 00567764  50                   push eax
// 00567765  e8f2be4100           call 0x98365c
// 0056776a  017e08               add dword ptr [esi + 8], edi
// 0056776d  83c40c               add esp, 0xc
// 00567770  5f                   pop edi
// 00567771  b001                 mov al, 1
// 00567773  5e                   pop esi
// 00567774  c20800               ret 8
// copied from an identical function in another client (function ?ReadAlignedBytes@BitStream@RakNet@@QAE_NPAEI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 BitStream.cpp