// from server: 100% by auto
// roc 2010-06 007041b0  unit: RBX::Animator  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007041b0
//
// 007041b0  83ec08               sub esp, 8
// 007041b3  8b542414             mov edx, dword ptr [esp + 0x14]
// 007041b7  53                   push ebx
// 007041b8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 007041bc  56                   push esi
// 007041bd  8b742418             mov esi, dword ptr [esp + 0x18]
// 007041c1  57                   push edi
// 007041c2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007041c6  32c0                 xor al, al
// 007041c8  88442410             mov byte ptr [esp + 0x10], al
// 007041cc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007041d0  8844240c             mov byte ptr [esp + 0xc], al
// 007041d4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007041d8  50                   push eax
// 007041d9  51                   push ecx
// 007041da  52                   push edx
// 007041db  57                   push edi
// 007041dc  56                   push esi
// 007041dd  53                   push ebx
// 007041de  e84dfaffff           call 0x703c30
// 007041e3  2bf3                 sub esi, ebx
// 007041e5  b8398ee338           mov eax, 0x38e38e39
// 007041ea  f7ee                 imul esi
// 007041ec  c1fa03               sar edx, 3
// 007041ef  83c418               add esp, 0x18
// 007041f2  8bc2                 mov eax, edx
// 007041f4  c1e81f               shr eax, 0x1f
// 007041f7  03c2                 add eax, edx
// 007041f9  8d04c0               lea eax, [eax + eax*8]
// 007041fc  8d0487               lea eax, [edi + eax*4]
// 007041ff  5f                   pop edi
// 00704200  5e                   pop esi
// 00704201  5b                   pop ebx
// 00704202  83c408               add esp, 8
// 00704205  c3                   ret 
// library ogre-1.7.0/OgreTechnique.cpp (function ??$_Copy_opt@PAUGPUDeviceNameRule@Technique@Ogre@@PAU123@@std@@YAPAUGPUDeviceNameRule@Technique@Ogre@@PAU123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreTechnique.cpp
