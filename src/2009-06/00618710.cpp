// from server: 100% by auto
// roc 2009-06 00618710  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00618710
//
// 00618710  56                   push esi
// 00618711  8bf1                 mov esi, ecx
// 00618713  8b06                 mov eax, dword ptr [esi]
// 00618715  57                   push edi
// 00618716  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 0061871c  85c0                 test eax, eax
// 0061871e  7508                 jne 0x618728
// 00618720  ffd7                 call edi
// 00618722  8b06                 mov eax, dword ptr [esi]
// 00618724  85c0                 test eax, eax
// 00618726  7404                 je 0x61872c
// 00618728  8b00                 mov eax, dword ptr [eax]
// 0061872a  eb02                 jmp 0x61872e
// 0061872c  33c0                 xor eax, eax
// 0061872e  8b4e04               mov ecx, dword ptr [esi + 4]
// 00618731  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 00618734  7502                 jne 0x618738
// 00618736  ffd7                 call edi
// 00618738  8b4604               mov eax, dword ptr [esi + 4]
// 0061873b  5f                   pop edi
// 0061873c  83c008               add eax, 8
// 0061873f  5e                   pop esi
// 00618740  c3                   ret 
// standard library list<ptr> (function ??D?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEABQAUT@@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
