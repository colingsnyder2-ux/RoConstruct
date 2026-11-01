// from server: 100% by auto
// roc 2007-03 0046a8b0  unit: seg_00460000  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0046a8b0
//
// 0046a8b0  83ec08               sub esp, 8
// 0046a8b3  8b542414             mov edx, dword ptr [esp + 0x14]
// 0046a8b7  53                   push ebx
// 0046a8b8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0046a8bc  56                   push esi
// 0046a8bd  8b742418             mov esi, dword ptr [esp + 0x18]
// 0046a8c1  57                   push edi
// 0046a8c2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0046a8c6  32c0                 xor al, al
// 0046a8c8  88442410             mov byte ptr [esp + 0x10], al
// 0046a8cc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0046a8d0  8844240c             mov byte ptr [esp + 0xc], al
// 0046a8d4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0046a8d8  50                   push eax
// 0046a8d9  51                   push ecx
// 0046a8da  52                   push edx
// 0046a8db  57                   push edi
// 0046a8dc  56                   push esi
// 0046a8dd  53                   push ebx
// 0046a8de  e81dfeffff           call 0x46a700
// 0046a8e3  2bf3                 sub esi, ebx
// 0046a8e5  83c418               add esp, 0x18
// 0046a8e8  c1fe06               sar esi, 6
// 0046a8eb  c1e606               shl esi, 6
// 0046a8ee  8bc7                 mov eax, edi
// 0046a8f0  5f                   pop edi
// 0046a8f1  2bc6                 sub eax, esi
// 0046a8f3  5e                   pop esi
// 0046a8f4  5b                   pop ebx
// 0046a8f5  83c408               add esp, 8
// 0046a8f8  c3                   ret 
// library ogre-1.7.0/OgreTangentSpaceCalc.cpp (function ??$_Copy_backward_opt@PAUVertexInfo@TangentSpaceCalc@Ogre@@PAU123@@std@@YAPAUVertexInfo@TangentSpaceCalc@Ogre@@PAU123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreTangentSpaceCalc.cpp
