// from server: 100% by auto
// roc 2009-12 004b0bf0  unit: Ogre::RbxTextureCompositorSceneManager  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b0bf0
//
// 004b0bf0  83ec08               sub esp, 8
// 004b0bf3  8b542414             mov edx, dword ptr [esp + 0x14]
// 004b0bf7  53                   push ebx
// 004b0bf8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004b0bfc  56                   push esi
// 004b0bfd  8b742418             mov esi, dword ptr [esp + 0x18]
// 004b0c01  57                   push edi
// 004b0c02  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004b0c06  32c0                 xor al, al
// 004b0c08  88442410             mov byte ptr [esp + 0x10], al
// 004b0c0c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004b0c10  8844240c             mov byte ptr [esp + 0xc], al
// 004b0c14  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004b0c18  50                   push eax
// 004b0c19  51                   push ecx
// 004b0c1a  52                   push edx
// 004b0c1b  57                   push edi
// 004b0c1c  56                   push esi
// 004b0c1d  53                   push ebx
// 004b0c1e  e81decffff           call 0x4af840
// 004b0c23  2bf3                 sub esi, ebx
// 004b0c25  83c418               add esp, 0x18
// 004b0c28  c1fe06               sar esi, 6
// 004b0c2b  c1e606               shl esi, 6
// 004b0c2e  8bc7                 mov eax, edi
// 004b0c30  5f                   pop edi
// 004b0c31  2bc6                 sub eax, esi
// 004b0c33  5e                   pop esi
// 004b0c34  5b                   pop ebx
// 004b0c35  83c408               add esp, 8
// 004b0c38  c3                   ret 
// library ogre-1.7.0/OgreTangentSpaceCalc.cpp (function ??$_Copy_backward_opt@PAUVertexInfo@TangentSpaceCalc@Ogre@@PAU123@@std@@YAPAUVertexInfo@TangentSpaceCalc@Ogre@@PAU123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreTangentSpaceCalc.cpp
