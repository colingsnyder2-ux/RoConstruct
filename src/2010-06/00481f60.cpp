// from server: 100% by auto
// roc 2010-06 00481f60  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00481f60
//
// 00481f60  83ec08               sub esp, 8
// 00481f63  8b542414             mov edx, dword ptr [esp + 0x14]
// 00481f67  53                   push ebx
// 00481f68  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00481f6c  56                   push esi
// 00481f6d  8b742418             mov esi, dword ptr [esp + 0x18]
// 00481f71  57                   push edi
// 00481f72  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00481f76  32c0                 xor al, al
// 00481f78  88442410             mov byte ptr [esp + 0x10], al
// 00481f7c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00481f80  8844240c             mov byte ptr [esp + 0xc], al
// 00481f84  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00481f88  50                   push eax
// 00481f89  51                   push ecx
// 00481f8a  52                   push edx
// 00481f8b  57                   push edi
// 00481f8c  56                   push esi
// 00481f8d  53                   push ebx
// 00481f8e  e80dfeffff           call 0x481da0
// 00481f93  2bf3                 sub esi, ebx
// 00481f95  83c418               add esp, 0x18
// 00481f98  c1fe06               sar esi, 6
// 00481f9b  c1e606               shl esi, 6
// 00481f9e  8bc7                 mov eax, edi
// 00481fa0  5f                   pop edi
// 00481fa1  2bc6                 sub eax, esi
// 00481fa3  5e                   pop esi
// 00481fa4  5b                   pop ebx
// 00481fa5  83c408               add esp, 8
// 00481fa8  c3                   ret 
// library ogre-1.7.0/OgreTangentSpaceCalc.cpp (function ??$_Copy_backward_opt@PAUVertexInfo@TangentSpaceCalc@Ogre@@PAU123@@std@@YAPAUVertexInfo@TangentSpaceCalc@Ogre@@PAU123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreTangentSpaceCalc.cpp
