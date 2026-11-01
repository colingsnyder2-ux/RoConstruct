// from server: 100% by auto
// roc 2009-12 004b0720  unit: Ogre::RbxTextureCompositorSceneManager  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b0720
//
// 004b0720  83ec08               sub esp, 8
// 004b0723  8b542414             mov edx, dword ptr [esp + 0x14]
// 004b0727  53                   push ebx
// 004b0728  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004b072c  56                   push esi
// 004b072d  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004b0731  57                   push edi
// 004b0732  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 004b0736  32c0                 xor al, al
// 004b0738  88442410             mov byte ptr [esp + 0x10], al
// 004b073c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004b0740  8844240c             mov byte ptr [esp + 0xc], al
// 004b0744  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004b0748  50                   push eax
// 004b0749  51                   push ecx
// 004b074a  52                   push edx
// 004b074b  56                   push esi
// 004b074c  57                   push edi
// 004b074d  53                   push ebx
// 004b074e  e82df0ffff           call 0x4af780
// 004b0753  8bc7                 mov eax, edi
// 004b0755  2bc3                 sub eax, ebx
// 004b0757  83c418               add esp, 0x18
// 004b075a  c1f806               sar eax, 6
// 004b075d  c1e006               shl eax, 6
// 004b0760  5f                   pop edi
// 004b0761  03c6                 add eax, esi
// 004b0763  5e                   pop esi
// 004b0764  5b                   pop ebx
// 004b0765  83c408               add esp, 8
// 004b0768  c3                   ret 
// library ogre-1.6.4/OgreMesh.cpp (function ??$_Copy_opt@PAUVertexInfo@TangentSpaceCalc@Ogre@@PAU123@@std@@YAPAUVertexInfo@TangentSpaceCalc@Ogre@@PAU123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreMesh.cpp
