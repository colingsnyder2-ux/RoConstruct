// from server: 100% by auto
// roc 2010-06 00741c80  unit: RBX::VHttp::?$sp_counted_impl_p  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00741c80
//
// 00741c80  83ec08               sub esp, 8
// 00741c83  8b542414             mov edx, dword ptr [esp + 0x14]
// 00741c87  53                   push ebx
// 00741c88  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00741c8c  56                   push esi
// 00741c8d  8b742418             mov esi, dword ptr [esp + 0x18]
// 00741c91  57                   push edi
// 00741c92  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00741c96  32c0                 xor al, al
// 00741c98  88442410             mov byte ptr [esp + 0x10], al
// 00741c9c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00741ca0  8844240c             mov byte ptr [esp + 0xc], al
// 00741ca4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00741ca8  50                   push eax
// 00741ca9  51                   push ecx
// 00741caa  52                   push edx
// 00741cab  57                   push edi
// 00741cac  56                   push esi
// 00741cad  53                   push ebx
// 00741cae  e8bdf5ffff           call 0x741270
// 00741cb3  2bf3                 sub esi, ebx
// 00741cb5  b867666666           mov eax, 0x66666667
// 00741cba  f7ee                 imul esi
// 00741cbc  c1fa04               sar edx, 4
// 00741cbf  83c418               add esp, 0x18
// 00741cc2  8bc2                 mov eax, edx
// 00741cc4  c1e81f               shr eax, 0x1f
// 00741cc7  03c2                 add eax, edx
// 00741cc9  8d0480               lea eax, [eax + eax*4]
// 00741ccc  8d04c7               lea eax, [edi + eax*8]
// 00741ccf  5f                   pop edi
// 00741cd0  5e                   pop esi
// 00741cd1  5b                   pop ebx
// 00741cd2  83c408               add esp, 8
// 00741cd5  c3                   ret 
// library ogre-1.7.0/OgreEdgeListBuilder.cpp (function ??$_Copy_opt@PAUEdgeGroup@EdgeData@Ogre@@PAU123@@std@@YAPAUEdgeGroup@EdgeData@Ogre@@PAU123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreEdgeListBuilder.cpp
