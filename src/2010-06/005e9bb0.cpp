// from server: 100% by auto
// roc 2010-06 005e9bb0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005e9bb0
//
// 005e9bb0  56                   push esi
// 005e9bb1  8bf1                 mov esi, ecx
// 005e9bb3  8b06                 mov eax, dword ptr [esi]
// 005e9bb5  57                   push edi
// 005e9bb6  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 005e9bbc  85c0                 test eax, eax
// 005e9bbe  7508                 jne 0x5e9bc8
// 005e9bc0  ffd7                 call edi
// 005e9bc2  8b06                 mov eax, dword ptr [esi]
// 005e9bc4  85c0                 test eax, eax
// 005e9bc6  7404                 je 0x5e9bcc
// 005e9bc8  8b00                 mov eax, dword ptr [eax]
// 005e9bca  eb02                 jmp 0x5e9bce
// 005e9bcc  33c0                 xor eax, eax
// 005e9bce  8b4e04               mov ecx, dword ptr [esi + 4]
// 005e9bd1  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 005e9bd4  7502                 jne 0x5e9bd8
// 005e9bd6  ffd7                 call edi
// 005e9bd8  8b4604               mov eax, dword ptr [esi + 4]
// 005e9bdb  5f                   pop edi
// 005e9bdc  83c008               add eax, 8
// 005e9bdf  5e                   pop esi
// 005e9be0  c3                   ret 
// standard library list<ptr> (function ??D?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEABQAUT@@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
