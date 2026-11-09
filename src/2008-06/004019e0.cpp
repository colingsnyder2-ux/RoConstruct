// from server: 100% by auto
// roc 2008-06 004019e0  unit: VCWorkspace::?$CComObject  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004019e0
//
// 004019e0  8b442404             mov eax, dword ptr [esp + 4]
// 004019e4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004019e8  3bc1                 cmp eax, ecx
// 004019ea  740a                 je 0x4019f6
// 004019ec  8a10                 mov dl, byte ptr [eax]
// 004019ee  53                   push ebx
// 004019ef  8a19                 mov bl, byte ptr [ecx]
// 004019f1  8818                 mov byte ptr [eax], bl
// 004019f3  8811                 mov byte ptr [ecx], dl
// 004019f5  5b                   pop ebx
// 004019f6  c3                   ret 
// standard library set<ptr> (function ??$swap@D@std@@YAXAAD0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
