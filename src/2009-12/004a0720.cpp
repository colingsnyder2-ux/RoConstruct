// from server: 100% by auto
// roc 2009-12 004a0720  unit: Ogre::UTVertexTangent3DTex::?$SpecializedMeshGen  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a0720
//
// 004a0720  83ec08               sub esp, 8
// 004a0723  8b542414             mov edx, dword ptr [esp + 0x14]
// 004a0727  53                   push ebx
// 004a0728  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004a072c  56                   push esi
// 004a072d  8b742418             mov esi, dword ptr [esp + 0x18]
// 004a0731  57                   push edi
// 004a0732  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004a0736  32c0                 xor al, al
// 004a0738  88442410             mov byte ptr [esp + 0x10], al
// 004a073c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004a0740  8844240c             mov byte ptr [esp + 0xc], al
// 004a0744  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004a0748  50                   push eax
// 004a0749  51                   push ecx
// 004a074a  52                   push edx
// 004a074b  57                   push edi
// 004a074c  56                   push esi
// 004a074d  53                   push ebx
// 004a074e  e8bdfeffff           call 0x4a0610
// 004a0753  2bf3                 sub esi, ebx
// 004a0755  b889888888           mov eax, 0x88888889
// 004a075a  f7ee                 imul esi
// 004a075c  03d6                 add edx, esi
// 004a075e  c1fa05               sar edx, 5
// 004a0761  8bc2                 mov eax, edx
// 004a0763  c1e81f               shr eax, 0x1f
// 004a0766  03c2                 add eax, edx
// 004a0768  8bc8                 mov ecx, eax
// 004a076a  c1e104               shl ecx, 4
// 004a076d  83c418               add esp, 0x18
// 004a0770  2bc8                 sub ecx, eax
// 004a0772  8bc7                 mov eax, edi
// 004a0774  03c9                 add ecx, ecx
// 004a0776  5f                   pop edi
// 004a0777  03c9                 add ecx, ecx
// 004a0779  5e                   pop esi
// 004a077a  2bc1                 sub eax, ecx
// 004a077c  5b                   pop ebx
// 004a077d  83c408               add esp, 8
// 004a0780  c3                   ret 
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ??$_Copy_backward_opt@PAVParameterDef@Ogre@@PAV12@@std@@YAPAVParameterDef@Ogre@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
