// from server: 100% by auto
// roc 2010-06 007889d0  unit: RBX::HUMAN::GettingUp  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007889d0
//
// 007889d0  83ec08               sub esp, 8
// 007889d3  8b542414             mov edx, dword ptr [esp + 0x14]
// 007889d7  53                   push ebx
// 007889d8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 007889dc  56                   push esi
// 007889dd  8b742418             mov esi, dword ptr [esp + 0x18]
// 007889e1  57                   push edi
// 007889e2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007889e6  32c0                 xor al, al
// 007889e8  88442410             mov byte ptr [esp + 0x10], al
// 007889ec  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007889f0  8844240c             mov byte ptr [esp + 0xc], al
// 007889f4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007889f8  50                   push eax
// 007889f9  51                   push ecx
// 007889fa  52                   push edx
// 007889fb  57                   push edi
// 007889fc  56                   push esi
// 007889fd  53                   push ebx
// 007889fe  e81df5ffff           call 0x787f20
// 00788a03  2bf3                 sub esi, ebx
// 00788a05  b867666666           mov eax, 0x66666667
// 00788a0a  f7ee                 imul esi
// 00788a0c  c1fa04               sar edx, 4
// 00788a0f  83c418               add esp, 0x18
// 00788a12  8bc2                 mov eax, edx
// 00788a14  c1e81f               shr eax, 0x1f
// 00788a17  03c2                 add eax, edx
// 00788a19  8d0480               lea eax, [eax + eax*4]
// 00788a1c  8d04c7               lea eax, [edi + eax*8]
// 00788a1f  5f                   pop edi
// 00788a20  5e                   pop esi
// 00788a21  5b                   pop ebx
// 00788a22  83c408               add esp, 8
// 00788a25  c3                   ret 
// library ogre-1.7.0/OgreEdgeListBuilder.cpp (function ??$_Copy_opt@PAUEdgeGroup@EdgeData@Ogre@@PAU123@@std@@YAPAUEdgeGroup@EdgeData@Ogre@@PAU123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreEdgeListBuilder.cpp
