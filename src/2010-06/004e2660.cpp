// from server: 100% by auto
// roc 2010-06 004e2660  unit: RBX::Network::IdSerializer  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004e2660
//
// 004e2660  83ec08               sub esp, 8
// 004e2663  8b542414             mov edx, dword ptr [esp + 0x14]
// 004e2667  53                   push ebx
// 004e2668  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004e266c  56                   push esi
// 004e266d  8b742418             mov esi, dword ptr [esp + 0x18]
// 004e2671  57                   push edi
// 004e2672  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004e2676  32c0                 xor al, al
// 004e2678  88442410             mov byte ptr [esp + 0x10], al
// 004e267c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004e2680  8844240c             mov byte ptr [esp + 0xc], al
// 004e2684  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004e2688  50                   push eax
// 004e2689  51                   push ecx
// 004e268a  52                   push edx
// 004e268b  57                   push edi
// 004e268c  56                   push esi
// 004e268d  53                   push ebx
// 004e268e  e88dfbffff           call 0x4e2220
// 004e2693  2bf3                 sub esi, ebx
// 004e2695  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004e269a  f7ee                 imul esi
// 004e269c  d1fa                 sar edx, 1
// 004e269e  8bc2                 mov eax, edx
// 004e26a0  c1e81f               shr eax, 0x1f
// 004e26a3  03c2                 add eax, edx
// 004e26a5  8d0440               lea eax, [eax + eax*2]
// 004e26a8  03c0                 add eax, eax
// 004e26aa  03c0                 add eax, eax
// 004e26ac  83c418               add esp, 0x18
// 004e26af  8bc8                 mov ecx, eax
// 004e26b1  8bc7                 mov eax, edi
// 004e26b3  5f                   pop edi
// 004e26b4  5e                   pop esi
// 004e26b5  2bc1                 sub eax, ecx
// 004e26b7  5b                   pop ebx
// 004e26b8  83c408               add esp, 8
// 004e26bb  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??$_Copy_backward_opt@PAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@@std@@YAPAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
