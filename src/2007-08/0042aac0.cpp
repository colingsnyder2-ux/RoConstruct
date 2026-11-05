// from server: 100% by auto
// roc 2007-08 0042aac0  unit: EventHandler  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042aac0
//
// 0042aac0  56                   push esi
// 0042aac1  8bf1                 mov esi, ecx
// 0042aac3  833e00               cmp dword ptr [esi], 0
// 0042aac6  57                   push edi
// 0042aac7  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 0042aacd  7502                 jne 0x42aad1
// 0042aacf  ffd7                 call edi
// 0042aad1  8b06                 mov eax, dword ptr [esi]
// 0042aad3  8b4e04               mov ecx, dword ptr [esi + 4]
// 0042aad6  3b4804               cmp ecx, dword ptr [eax + 4]
// 0042aad9  7502                 jne 0x42aadd
// 0042aadb  ffd7                 call edi
// 0042aadd  8b4604               mov eax, dword ptr [esi + 4]
// 0042aae0  5f                   pop edi
// 0042aae1  83c008               add eax, 8
// 0042aae4  5e                   pop esi
// 0042aae5  c3                   ret 
// standard library list<ptr> (function ??D?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEABQAUT@@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
