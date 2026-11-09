// from server: 100% by auto
// roc 2009-12 007988a0  unit: lua_exception  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007988a0
//
// 007988a0  83ec08               sub esp, 8
// 007988a3  8b542414             mov edx, dword ptr [esp + 0x14]
// 007988a7  53                   push ebx
// 007988a8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 007988ac  56                   push esi
// 007988ad  8b742418             mov esi, dword ptr [esp + 0x18]
// 007988b1  57                   push edi
// 007988b2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007988b6  32c0                 xor al, al
// 007988b8  88442410             mov byte ptr [esp + 0x10], al
// 007988bc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007988c0  8844240c             mov byte ptr [esp + 0xc], al
// 007988c4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007988c8  50                   push eax
// 007988c9  51                   push ecx
// 007988ca  52                   push edx
// 007988cb  57                   push edi
// 007988cc  56                   push esi
// 007988cd  53                   push ebx
// 007988ce  e83df7ffff           call 0x798010
// 007988d3  2bf3                 sub esi, ebx
// 007988d5  b8abaaaa2a           mov eax, 0x2aaaaaab
// 007988da  f7ee                 imul esi
// 007988dc  c1fa02               sar edx, 2
// 007988df  83c418               add esp, 0x18
// 007988e2  8bc2                 mov eax, edx
// 007988e4  c1e81f               shr eax, 0x1f
// 007988e7  03c2                 add eax, edx
// 007988e9  8d0440               lea eax, [eax + eax*2]
// 007988ec  8d04c7               lea eax, [edi + eax*8]
// 007988ef  5f                   pop edi
// 007988f0  5e                   pop esi
// 007988f1  5b                   pop ebx
// 007988f2  83c408               add esp, 8
// 007988f5  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
