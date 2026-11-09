// from server: 100% by auto
// roc 2009-06 00680400  unit: RBX::Mechanism  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00680400
//
// 00680400  53                   push ebx
// 00680401  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 00680407  56                   push esi
// 00680408  8b31                 mov esi, dword ptr [ecx]
// 0068040a  57                   push edi
// 0068040b  8b7904               mov edi, dword ptr [ecx + 4]
// 0068040e  85f6                 test esi, esi
// 00680410  7518                 jne 0x68042a
// 00680412  ffd3                 call ebx
// 00680414  33c0                 xor eax, eax
// 00680416  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0068041a  8d3c8f               lea edi, [edi + ecx*4]
// 0068041d  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00680420  7713                 ja 0x680435
// 00680422  85f6                 test esi, esi
// 00680424  7408                 je 0x68042e
// 00680426  8b06                 mov eax, dword ptr [esi]
// 00680428  eb06                 jmp 0x680430
// 0068042a  8b06                 mov eax, dword ptr [esi]
// 0068042c  ebe8                 jmp 0x680416
// 0068042e  33c0                 xor eax, eax
// 00680430  3b780c               cmp edi, dword ptr [eax + 0xc]
// 00680433  7302                 jae 0x680437
// 00680435  ffd3                 call ebx
// 00680437  8b442410             mov eax, dword ptr [esp + 0x10]
// 0068043b  897804               mov dword ptr [eax + 4], edi
// 0068043e  5f                   pop edi
// 0068043f  8930                 mov dword ptr [eax], esi
// 00680441  5e                   pop esi
// 00680442  5b                   pop ebx
// 00680443  c20800               ret 8
// standard library vector<ptr> (function ??H?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBE?AV01@H@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
