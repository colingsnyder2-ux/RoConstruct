// from server: 100% by auto
// roc 2010-06 008f2e40  unit: Ogre::UTVertexSurfaceTex::?$SpecializedMeshGen  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f2e40
//
// 008f2e40  83ec08               sub esp, 8
// 008f2e43  8b542414             mov edx, dword ptr [esp + 0x14]
// 008f2e47  53                   push ebx
// 008f2e48  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 008f2e4c  56                   push esi
// 008f2e4d  8b742418             mov esi, dword ptr [esp + 0x18]
// 008f2e51  57                   push edi
// 008f2e52  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008f2e56  32c0                 xor al, al
// 008f2e58  88442410             mov byte ptr [esp + 0x10], al
// 008f2e5c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008f2e60  8844240c             mov byte ptr [esp + 0xc], al
// 008f2e64  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008f2e68  50                   push eax
// 008f2e69  51                   push ecx
// 008f2e6a  52                   push edx
// 008f2e6b  57                   push edi
// 008f2e6c  56                   push esi
// 008f2e6d  53                   push ebx
// 008f2e6e  e8ddfeffff           call 0x8f2d50
// 008f2e73  2bf3                 sub esi, ebx
// 008f2e75  b8e9a28b2e           mov eax, 0x2e8ba2e9
// 008f2e7a  f7ee                 imul esi
// 008f2e7c  c1fa03               sar edx, 3
// 008f2e7f  8bc2                 mov eax, edx
// 008f2e81  c1e81f               shr eax, 0x1f
// 008f2e84  03c2                 add eax, edx
// 008f2e86  8bc8                 mov ecx, eax
// 008f2e88  6bc92c               imul ecx, ecx, 0x2c
// 008f2e8b  83c418               add esp, 0x18
// 008f2e8e  8bc7                 mov eax, edi
// 008f2e90  5f                   pop edi
// 008f2e91  5e                   pop esi
// 008f2e92  2bc1                 sub eax, ecx
// 008f2e94  5b                   pop ebx
// 008f2e95  83c408               add esp, 8
// 008f2e98  c3                   ret 
// library ogre-1.6.4/OgreCompiler2Pass.cpp (function ??$_Copy_backward_opt@PAULexemeTokenDef@Compiler2Pass@Ogre@@PAU123@@std@@YAPAULexemeTokenDef@Compiler2Pass@Ogre@@PAU123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreCompiler2Pass.cpp
