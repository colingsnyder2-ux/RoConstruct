// from server: 100% by auto
// roc 2007-08 0046a810  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0046a810
//
// 0046a810  83ec08               sub esp, 8
// 0046a813  8b542414             mov edx, dword ptr [esp + 0x14]
// 0046a817  53                   push ebx
// 0046a818  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0046a81c  56                   push esi
// 0046a81d  8b742418             mov esi, dword ptr [esp + 0x18]
// 0046a821  57                   push edi
// 0046a822  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0046a826  32c0                 xor al, al
// 0046a828  88442410             mov byte ptr [esp + 0x10], al
// 0046a82c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0046a830  8844240c             mov byte ptr [esp + 0xc], al
// 0046a834  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0046a838  50                   push eax
// 0046a839  51                   push ecx
// 0046a83a  52                   push edx
// 0046a83b  57                   push edi
// 0046a83c  56                   push esi
// 0046a83d  53                   push ebx
// 0046a83e  e87dfeffff           call 0x46a6c0
// 0046a843  2bf3                 sub esi, ebx
// 0046a845  83c418               add esp, 0x18
// 0046a848  c1fe06               sar esi, 6
// 0046a84b  c1e606               shl esi, 6
// 0046a84e  8bc7                 mov eax, edi
// 0046a850  5f                   pop edi
// 0046a851  2bc6                 sub eax, esi
// 0046a853  5e                   pop esi
// 0046a854  5b                   pop ebx
// 0046a855  83c408               add esp, 8
// 0046a858  c3                   ret 
// library ogre-1.7.0/OgreTangentSpaceCalc.cpp (function ??$_Copy_backward_opt@PAUVertexInfo@TangentSpaceCalc@Ogre@@PAU123@@std@@YAPAUVertexInfo@TangentSpaceCalc@Ogre@@PAU123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreTangentSpaceCalc.cpp
