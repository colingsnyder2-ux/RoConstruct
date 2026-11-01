// from server: 100% by auto
// roc 2007-08 0040f8c0  unit: CopyVerb  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040f8c0
//
// 0040f8c0  83ec08               sub esp, 8
// 0040f8c3  8b542414             mov edx, dword ptr [esp + 0x14]
// 0040f8c7  53                   push ebx
// 0040f8c8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0040f8cc  56                   push esi
// 0040f8cd  8b742418             mov esi, dword ptr [esp + 0x18]
// 0040f8d1  57                   push edi
// 0040f8d2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0040f8d6  32c0                 xor al, al
// 0040f8d8  88442410             mov byte ptr [esp + 0x10], al
// 0040f8dc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0040f8e0  8844240c             mov byte ptr [esp + 0xc], al
// 0040f8e4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040f8e8  50                   push eax
// 0040f8e9  51                   push ecx
// 0040f8ea  52                   push edx
// 0040f8eb  57                   push edi
// 0040f8ec  56                   push esi
// 0040f8ed  53                   push ebx
// 0040f8ee  e8fdfbffff           call 0x40f4f0
// 0040f8f3  2bf3                 sub esi, ebx
// 0040f8f5  b8398ee338           mov eax, 0x38e38e39
// 0040f8fa  f7ee                 imul esi
// 0040f8fc  c1fa03               sar edx, 3
// 0040f8ff  83c418               add esp, 0x18
// 0040f902  8bc2                 mov eax, edx
// 0040f904  c1e81f               shr eax, 0x1f
// 0040f907  03c2                 add eax, edx
// 0040f909  8d04c0               lea eax, [eax + eax*8]
// 0040f90c  8d0487               lea eax, [edi + eax*4]
// 0040f90f  5f                   pop edi
// 0040f910  5e                   pop esi
// 0040f911  5b                   pop ebx
// 0040f912  83c408               add esp, 8
// 0040f915  c3                   ret 
// library ogre-1.7.0/OgreTechnique.cpp (function ??$_Copy_opt@PAUGPUDeviceNameRule@Technique@Ogre@@PAU123@@std@@YAPAUGPUDeviceNameRule@Technique@Ogre@@PAU123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreTechnique.cpp
