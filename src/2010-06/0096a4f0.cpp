// from server: 100% by auto
// roc 2010-06 0096a4f0  unit: Ogre::RbxSceneUpdater  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0096a4f0
//
// 0096a4f0  83ec08               sub esp, 8
// 0096a4f3  8b542414             mov edx, dword ptr [esp + 0x14]
// 0096a4f7  53                   push ebx
// 0096a4f8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0096a4fc  56                   push esi
// 0096a4fd  8b742418             mov esi, dword ptr [esp + 0x18]
// 0096a501  57                   push edi
// 0096a502  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0096a506  32c0                 xor al, al
// 0096a508  88442410             mov byte ptr [esp + 0x10], al
// 0096a50c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0096a510  8844240c             mov byte ptr [esp + 0xc], al
// 0096a514  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0096a518  50                   push eax
// 0096a519  51                   push ecx
// 0096a51a  52                   push edx
// 0096a51b  57                   push edi
// 0096a51c  56                   push esi
// 0096a51d  53                   push ebx
// 0096a51e  e83de1ffff           call 0x968660
// 0096a523  2bf3                 sub esi, ebx
// 0096a525  b867666666           mov eax, 0x66666667
// 0096a52a  f7ee                 imul esi
// 0096a52c  c1fa03               sar edx, 3
// 0096a52f  83c418               add esp, 0x18
// 0096a532  8bc2                 mov eax, edx
// 0096a534  c1e81f               shr eax, 0x1f
// 0096a537  03c2                 add eax, edx
// 0096a539  8d0480               lea eax, [eax + eax*4]
// 0096a53c  8d0487               lea eax, [edi + eax*4]
// 0096a53f  5f                   pop edi
// 0096a540  5e                   pop esi
// 0096a541  5b                   pop ebx
// 0096a542  83c408               add esp, 8
// 0096a545  c3                   ret 
// standard library vector<pod20> (function ??$_Copy_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
