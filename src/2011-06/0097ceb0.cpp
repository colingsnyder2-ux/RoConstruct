// from server: 100% by auto
// roc 2011-06 0097ceb0  unit: RBX::BeveledBlockBuilder  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0097ceb0
//
// 0097ceb0  8b442404             mov eax, dword ptr [esp + 4]
// 0097ceb4  8b542408             mov edx, dword ptr [esp + 8]
// 0097ceb8  3bc2                 cmp eax, edx
// 0097ceba  742f                 je 0x97ceeb
// 0097cebc  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0097cec0  56                   push esi
// 0097cec1  8b31                 mov esi, dword ptr [ecx]
// 0097cec3  8930                 mov dword ptr [eax], esi
// 0097cec5  8b7104               mov esi, dword ptr [ecx + 4]
// 0097cec8  897004               mov dword ptr [eax + 4], esi
// 0097cecb  8b7108               mov esi, dword ptr [ecx + 8]
// 0097cece  897008               mov dword ptr [eax + 8], esi
// 0097ced1  8b710c               mov esi, dword ptr [ecx + 0xc]
// 0097ced4  89700c               mov dword ptr [eax + 0xc], esi
// 0097ced7  8b7110               mov esi, dword ptr [ecx + 0x10]
// 0097ceda  897010               mov dword ptr [eax + 0x10], esi
// 0097cedd  8b7114               mov esi, dword ptr [ecx + 0x14]
// 0097cee0  897014               mov dword ptr [eax + 0x14], esi
// 0097cee3  83c018               add eax, 0x18
// 0097cee6  3bc2                 cmp eax, edx
// 0097cee8  75d7                 jne 0x97cec1
// 0097ceea  5e                   pop esi
// 0097ceeb  c3                   ret 
// standard library vector<pod24> (function ??$_Fill@PAUE@@U1@@std@@YAXPAUE@@0ABU1@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
