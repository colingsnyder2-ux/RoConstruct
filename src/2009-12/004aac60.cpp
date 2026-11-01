// from server: 100% by auto
// roc 2009-12 004aac60  unit: Ogre::RbxSceneUpdater::?1??debugCheckFrame::NodeVisiter  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004aac60
//
// 004aac60  56                   push esi
// 004aac61  8bf1                 mov esi, ecx
// 004aac63  8b06                 mov eax, dword ptr [esi]
// 004aac65  57                   push edi
// 004aac66  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 004aac6c  85c0                 test eax, eax
// 004aac6e  7508                 jne 0x4aac78
// 004aac70  ffd7                 call edi
// 004aac72  8b06                 mov eax, dword ptr [esi]
// 004aac74  85c0                 test eax, eax
// 004aac76  7404                 je 0x4aac7c
// 004aac78  8b00                 mov eax, dword ptr [eax]
// 004aac7a  eb02                 jmp 0x4aac7e
// 004aac7c  33c0                 xor eax, eax
// 004aac7e  8b4e04               mov ecx, dword ptr [esi + 4]
// 004aac81  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 004aac84  7502                 jne 0x4aac88
// 004aac86  ffd7                 call edi
// 004aac88  8b5604               mov edx, dword ptr [esi + 4]
// 004aac8b  8b02                 mov eax, dword ptr [edx]
// 004aac8d  894604               mov dword ptr [esi + 4], eax
// 004aac90  5f                   pop edi
// 004aac91  8bc6                 mov eax, esi
// 004aac93  5e                   pop esi
// 004aac94  c3                   ret 
// standard library list<ptr> (function ??E?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAV012@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
