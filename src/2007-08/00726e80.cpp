// from server: 100% by auto
// roc 2007-08 00726e80  unit: boost::thread_resource_error  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00726e80
//
// 00726e80  56                   push esi
// 00726e81  8bf1                 mov esi, ecx
// 00726e83  8b4e04               mov ecx, dword ptr [esi + 4]
// 00726e86  8b01                 mov eax, dword ptr [ecx]
// 00726e88  8909                 mov dword ptr [ecx], ecx
// 00726e8a  8b4e04               mov ecx, dword ptr [esi + 4]
// 00726e8d  894904               mov dword ptr [ecx + 4], ecx
// 00726e90  3b4604               cmp eax, dword ptr [esi + 4]
// 00726e93  c7460800000000       mov dword ptr [esi + 8], 0
// 00726e9a  7417                 je 0x726eb3
// 00726e9c  57                   push edi
// 00726e9d  8d4900               lea ecx, [ecx]
// 00726ea0  8b38                 mov edi, dword ptr [eax]
// 00726ea2  50                   push eax
// 00726ea3  e8ba8df0ff           call 0x62fc62
// 00726ea8  83c404               add esp, 4
// 00726eab  3b7e04               cmp edi, dword ptr [esi + 4]
// 00726eae  8bc7                 mov eax, edi
// 00726eb0  75ee                 jne 0x726ea0
// 00726eb2  5f                   pop edi
// 00726eb3  8b4604               mov eax, dword ptr [esi + 4]
// 00726eb6  50                   push eax
// 00726eb7  e8a68df0ff           call 0x62fc62
// 00726ebc  83c404               add esp, 4
// 00726ebf  c7460400000000       mov dword ptr [esi + 4], 0
// 00726ec6  5e                   pop esi
// 00726ec7  c3                   ret 
// standard library list<ptr> (function ?_Tidy@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXXZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
