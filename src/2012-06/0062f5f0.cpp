// from server: 100% by auto
// roc 2012-06 0062f5f0  unit: G3D::BinaryInput  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062f5f0
//
// 0062f5f0  83ec08               sub esp, 8
// 0062f5f3  8b01                 mov eax, dword ptr [ecx]
// 0062f5f5  8b4904               mov ecx, dword ptr [ecx + 4]
// 0062f5f8  8b542410             mov edx, dword ptr [esp + 0x10]
// 0062f5fc  894c2404             mov dword ptr [esp + 4], ecx
// 0062f600  52                   push edx
// 0062f601  8d4c2404             lea ecx, [esp + 4]
// 0062f605  89442404             mov dword ptr [esp + 4], eax
// 0062f609  e8e2fbffff           call 0x62f1f0
// 0062f60e  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0062f612  8b0c24               mov ecx, dword ptr [esp]
// 0062f615  8b542404             mov edx, dword ptr [esp + 4]
// 0062f619  8908                 mov dword ptr [eax], ecx
// 0062f61b  895004               mov dword ptr [eax + 4], edx
// 0062f61e  83c408               add esp, 8
// 0062f621  c20800               ret 8
// standard library vector<string> (function ??H?$_Vector_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QBE?AV01@H@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
