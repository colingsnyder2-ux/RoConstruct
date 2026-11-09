// from server: 100% by auto
// roc 2011-06 00543790  unit: G3D::BinaryInput  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00543790
//
// 00543790  83ec08               sub esp, 8
// 00543793  8b01                 mov eax, dword ptr [ecx]
// 00543795  8b4904               mov ecx, dword ptr [ecx + 4]
// 00543798  8b542410             mov edx, dword ptr [esp + 0x10]
// 0054379c  894c2404             mov dword ptr [esp + 4], ecx
// 005437a0  52                   push edx
// 005437a1  8d4c2404             lea ecx, [esp + 4]
// 005437a5  89442404             mov dword ptr [esp + 4], eax
// 005437a9  e832fbffff           call 0x5432e0
// 005437ae  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005437b2  8b0c24               mov ecx, dword ptr [esp]
// 005437b5  8b542404             mov edx, dword ptr [esp + 4]
// 005437b9  8908                 mov dword ptr [eax], ecx
// 005437bb  895004               mov dword ptr [eax + 4], edx
// 005437be  83c408               add esp, 8
// 005437c1  c20800               ret 8
// standard library vector<string> (function ??H?$_Vector_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QBE?AV01@H@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
