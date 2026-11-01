// from server: 100% by auto
// roc 2009-12 0049f120  unit: Ogre::UTVertexSurfaceTex::?$SpecializedMeshGen  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0049f120
//
// 0049f120  83ec08               sub esp, 8
// 0049f123  8b542414             mov edx, dword ptr [esp + 0x14]
// 0049f127  53                   push ebx
// 0049f128  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0049f12c  56                   push esi
// 0049f12d  8b742418             mov esi, dword ptr [esp + 0x18]
// 0049f131  57                   push edi
// 0049f132  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0049f136  32c0                 xor al, al
// 0049f138  88442410             mov byte ptr [esp + 0x10], al
// 0049f13c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0049f140  8844240c             mov byte ptr [esp + 0xc], al
// 0049f144  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0049f148  50                   push eax
// 0049f149  51                   push ecx
// 0049f14a  52                   push edx
// 0049f14b  57                   push edi
// 0049f14c  56                   push esi
// 0049f14d  53                   push ebx
// 0049f14e  e8ddfeffff           call 0x49f030
// 0049f153  2bf3                 sub esi, ebx
// 0049f155  b8e9a28b2e           mov eax, 0x2e8ba2e9
// 0049f15a  f7ee                 imul esi
// 0049f15c  c1fa03               sar edx, 3
// 0049f15f  8bc2                 mov eax, edx
// 0049f161  c1e81f               shr eax, 0x1f
// 0049f164  03c2                 add eax, edx
// 0049f166  8bc8                 mov ecx, eax
// 0049f168  6bc92c               imul ecx, ecx, 0x2c
// 0049f16b  83c418               add esp, 0x18
// 0049f16e  8bc7                 mov eax, edi
// 0049f170  5f                   pop edi
// 0049f171  5e                   pop esi
// 0049f172  2bc1                 sub eax, ecx
// 0049f174  5b                   pop ebx
// 0049f175  83c408               add esp, 8
// 0049f178  c3                   ret 
// library ogre-1.6.4/OgreCompiler2Pass.cpp (function ??$_Copy_backward_opt@PAULexemeTokenDef@Compiler2Pass@Ogre@@PAU123@@std@@YAPAULexemeTokenDef@Compiler2Pass@Ogre@@PAU123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreCompiler2Pass.cpp
