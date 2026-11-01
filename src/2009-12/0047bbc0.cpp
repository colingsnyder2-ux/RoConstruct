// from server: 100% by auto
// roc 2009-12 0047bbc0  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047bbc0
//
// 0047bbc0  83ec08               sub esp, 8
// 0047bbc3  8b542414             mov edx, dword ptr [esp + 0x14]
// 0047bbc7  53                   push ebx
// 0047bbc8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0047bbcc  56                   push esi
// 0047bbcd  8b742418             mov esi, dword ptr [esp + 0x18]
// 0047bbd1  57                   push edi
// 0047bbd2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0047bbd6  32c0                 xor al, al
// 0047bbd8  88442410             mov byte ptr [esp + 0x10], al
// 0047bbdc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0047bbe0  8844240c             mov byte ptr [esp + 0xc], al
// 0047bbe4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0047bbe8  50                   push eax
// 0047bbe9  51                   push ecx
// 0047bbea  52                   push edx
// 0047bbeb  57                   push edi
// 0047bbec  56                   push esi
// 0047bbed  53                   push ebx
// 0047bbee  e8edfeffff           call 0x47bae0
// 0047bbf3  2bf3                 sub esi, ebx
// 0047bbf5  83c418               add esp, 0x18
// 0047bbf8  c1fe06               sar esi, 6
// 0047bbfb  c1e606               shl esi, 6
// 0047bbfe  8bc7                 mov eax, edi
// 0047bc00  5f                   pop edi
// 0047bc01  2bc6                 sub eax, esi
// 0047bc03  5e                   pop esi
// 0047bc04  5b                   pop ebx
// 0047bc05  83c408               add esp, 8
// 0047bc08  c3                   ret 
// library ogre-1.7.0/OgreTangentSpaceCalc.cpp (function ??$_Copy_backward_opt@PAUVertexInfo@TangentSpaceCalc@Ogre@@PAU123@@std@@YAPAUVertexInfo@TangentSpaceCalc@Ogre@@PAU123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreTangentSpaceCalc.cpp
