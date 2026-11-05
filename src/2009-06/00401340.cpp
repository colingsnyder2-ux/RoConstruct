// from server: 100% by auto
// roc 2009-06 00401340  unit: CAboutRobloxDialog  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00401340
//
// 00401340  8b442404             mov eax, dword ptr [esp + 4]
// 00401344  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00401348  3bc1                 cmp eax, ecx
// 0040134a  740a                 je 0x401356
// 0040134c  8a10                 mov dl, byte ptr [eax]
// 0040134e  53                   push ebx
// 0040134f  8a19                 mov bl, byte ptr [ecx]
// 00401351  8818                 mov byte ptr [eax], bl
// 00401353  8811                 mov byte ptr [ecx], dl
// 00401355  5b                   pop ebx
// 00401356  c3                   ret 
// standard library vector<char> (function ??$swap@D@std@@YAXAAD0@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
