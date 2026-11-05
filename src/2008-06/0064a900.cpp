// from server: 100% by auto
// roc 2008-06 0064a900  unit: RBX::SleepStage  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064a900
//
// 0064a900  53                   push ebx
// 0064a901  8b1d90288000         mov ebx, dword ptr [0x802890]
// 0064a907  56                   push esi
// 0064a908  8b31                 mov esi, dword ptr [ecx]
// 0064a90a  57                   push edi
// 0064a90b  8b7904               mov edi, dword ptr [ecx + 4]
// 0064a90e  85f6                 test esi, esi
// 0064a910  7518                 jne 0x64a92a
// 0064a912  ffd3                 call ebx
// 0064a914  33c0                 xor eax, eax
// 0064a916  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0064a91a  8d3c8f               lea edi, [edi + ecx*4]
// 0064a91d  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0064a920  7713                 ja 0x64a935
// 0064a922  85f6                 test esi, esi
// 0064a924  7408                 je 0x64a92e
// 0064a926  8b06                 mov eax, dword ptr [esi]
// 0064a928  eb06                 jmp 0x64a930
// 0064a92a  8b06                 mov eax, dword ptr [esi]
// 0064a92c  ebe8                 jmp 0x64a916
// 0064a92e  33c0                 xor eax, eax
// 0064a930  3b780c               cmp edi, dword ptr [eax + 0xc]
// 0064a933  7302                 jae 0x64a937
// 0064a935  ffd3                 call ebx
// 0064a937  8b442410             mov eax, dword ptr [esp + 0x10]
// 0064a93b  897804               mov dword ptr [eax + 4], edi
// 0064a93e  5f                   pop edi
// 0064a93f  8930                 mov dword ptr [eax], esi
// 0064a941  5e                   pop esi
// 0064a942  5b                   pop ebx
// 0064a943  c20800               ret 8
// standard library vector<ptr> (function ??H?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBE?AV01@H@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
