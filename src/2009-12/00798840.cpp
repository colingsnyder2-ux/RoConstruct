// from server: 100% by auto
// roc 2009-12 00798840  unit: lua_exception  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00798840
//
// 00798840  83ec08               sub esp, 8
// 00798843  8b542414             mov edx, dword ptr [esp + 0x14]
// 00798847  53                   push ebx
// 00798848  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0079884c  56                   push esi
// 0079884d  8b742418             mov esi, dword ptr [esp + 0x18]
// 00798851  57                   push edi
// 00798852  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00798856  32c0                 xor al, al
// 00798858  88442410             mov byte ptr [esp + 0x10], al
// 0079885c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00798860  8844240c             mov byte ptr [esp + 0xc], al
// 00798864  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00798868  50                   push eax
// 00798869  51                   push ecx
// 0079886a  52                   push edx
// 0079886b  57                   push edi
// 0079886c  56                   push esi
// 0079886d  53                   push ebx
// 0079886e  e80df7ffff           call 0x797f80
// 00798873  2bf3                 sub esi, ebx
// 00798875  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0079887a  f7ee                 imul esi
// 0079887c  c1fa02               sar edx, 2
// 0079887f  83c418               add esp, 0x18
// 00798882  8bc2                 mov eax, edx
// 00798884  c1e81f               shr eax, 0x1f
// 00798887  03c2                 add eax, edx
// 00798889  8d0440               lea eax, [eax + eax*2]
// 0079888c  8d04c7               lea eax, [edi + eax*8]
// 0079888f  5f                   pop edi
// 00798890  5e                   pop esi
// 00798891  5b                   pop ebx
// 00798892  83c408               add esp, 8
// 00798895  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
