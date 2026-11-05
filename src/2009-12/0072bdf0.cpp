// from server: 100% by auto
// roc 2009-12 0072bdf0  unit: boost::Vthread::?$sp_counted_impl_p  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0072bdf0
//
// 0072bdf0  83ec08               sub esp, 8
// 0072bdf3  8b542414             mov edx, dword ptr [esp + 0x14]
// 0072bdf7  53                   push ebx
// 0072bdf8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0072bdfc  56                   push esi
// 0072bdfd  8b742418             mov esi, dword ptr [esp + 0x18]
// 0072be01  57                   push edi
// 0072be02  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0072be06  32c0                 xor al, al
// 0072be08  88442410             mov byte ptr [esp + 0x10], al
// 0072be0c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0072be10  8844240c             mov byte ptr [esp + 0xc], al
// 0072be14  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0072be18  50                   push eax
// 0072be19  51                   push ecx
// 0072be1a  52                   push edx
// 0072be1b  57                   push edi
// 0072be1c  56                   push esi
// 0072be1d  53                   push ebx
// 0072be1e  e87dfdffff           call 0x72bba0
// 0072be23  2bf3                 sub esi, ebx
// 0072be25  b867666666           mov eax, 0x66666667
// 0072be2a  f7ee                 imul esi
// 0072be2c  c1fa04               sar edx, 4
// 0072be2f  8bc2                 mov eax, edx
// 0072be31  c1e81f               shr eax, 0x1f
// 0072be34  03c2                 add eax, edx
// 0072be36  8d0480               lea eax, [eax + eax*4]
// 0072be39  03c0                 add eax, eax
// 0072be3b  03c0                 add eax, eax
// 0072be3d  03c0                 add eax, eax
// 0072be3f  83c418               add esp, 0x18
// 0072be42  8bc8                 mov ecx, eax
// 0072be44  8bc7                 mov eax, edi
// 0072be46  5f                   pop edi
// 0072be47  5e                   pop esi
// 0072be48  2bc1                 sub eax, ecx
// 0072be4a  5b                   pop ebx
// 0072be4b  83c408               add esp, 8
// 0072be4e  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??$_Copy_backward_opt@PAVVertex@?$ConvexClipper@N@Wml@@PAV123@@std@@YAPAVVertex@?$ConvexClipper@N@Wml@@PAV123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
