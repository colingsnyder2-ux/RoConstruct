// from server: 100% by auto
// roc 2010-06 00787920  unit: RBX::HUMAN::GettingUp  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00787920
//
// 00787920  83ec08               sub esp, 8
// 00787923  53                   push ebx
// 00787924  55                   push ebp
// 00787925  56                   push esi
// 00787926  8bf1                 mov esi, ecx
// 00787928  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0078792b  57                   push edi
// 0078792c  395e0c               cmp dword ptr [esi + 0xc], ebx
// 0078792f  7606                 jbe 0x787937
// 00787931  ff150ca99e00         call dword ptr [0x9ea90c]
// 00787937  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0078793a  8b2e                 mov ebp, dword ptr [esi]
// 0078793c  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0078793f  7606                 jbe 0x787947
// 00787941  ff150ca99e00         call dword ptr [0x9ea90c]
// 00787947  8b06                 mov eax, dword ptr [esi]
// 00787949  53                   push ebx
// 0078794a  55                   push ebp
// 0078794b  57                   push edi
// 0078794c  50                   push eax
// 0078794d  8d442420             lea eax, [esp + 0x20]
// 00787951  50                   push eax
// 00787952  8bce                 mov ecx, esi
// 00787954  e897ddd9ff           call 0x5256f0
// 00787959  5f                   pop edi
// 0078795a  5e                   pop esi
// 0078795b  5d                   pop ebp
// 0078795c  5b                   pop ebx
// 0078795d  83c408               add esp, 8
// 00787960  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
