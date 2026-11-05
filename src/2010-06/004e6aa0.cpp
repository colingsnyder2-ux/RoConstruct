// from server: 100% by auto
// roc 2010-06 004e6aa0  unit: RBX::Network::Replicator  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004e6aa0
//
// 004e6aa0  53                   push ebx
// 004e6aa1  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 004e6aa7  56                   push esi
// 004e6aa8  8b31                 mov esi, dword ptr [ecx]
// 004e6aaa  57                   push edi
// 004e6aab  8b7904               mov edi, dword ptr [ecx + 4]
// 004e6aae  85f6                 test esi, esi
// 004e6ab0  7518                 jne 0x4e6aca
// 004e6ab2  ffd3                 call ebx
// 004e6ab4  33c0                 xor eax, eax
// 004e6ab6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004e6aba  8d3c8f               lea edi, [edi + ecx*4]
// 004e6abd  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004e6ac0  7713                 ja 0x4e6ad5
// 004e6ac2  85f6                 test esi, esi
// 004e6ac4  7408                 je 0x4e6ace
// 004e6ac6  8b06                 mov eax, dword ptr [esi]
// 004e6ac8  eb06                 jmp 0x4e6ad0
// 004e6aca  8b06                 mov eax, dword ptr [esi]
// 004e6acc  ebe8                 jmp 0x4e6ab6
// 004e6ace  33c0                 xor eax, eax
// 004e6ad0  3b780c               cmp edi, dword ptr [eax + 0xc]
// 004e6ad3  7302                 jae 0x4e6ad7
// 004e6ad5  ffd3                 call ebx
// 004e6ad7  8b442410             mov eax, dword ptr [esp + 0x10]
// 004e6adb  897804               mov dword ptr [eax + 4], edi
// 004e6ade  5f                   pop edi
// 004e6adf  8930                 mov dword ptr [eax], esi
// 004e6ae1  5e                   pop esi
// 004e6ae2  5b                   pop ebx
// 004e6ae3  c20800               ret 8
// standard library vector<ptr> (function ??H?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBE?AV01@H@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
