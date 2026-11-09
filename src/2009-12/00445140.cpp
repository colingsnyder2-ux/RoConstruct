// from server: 100% by auto
// roc 2009-12 00445140  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00445140
//
// 00445140  83ec08               sub esp, 8
// 00445143  53                   push ebx
// 00445144  55                   push ebp
// 00445145  56                   push esi
// 00445146  8bf1                 mov esi, ecx
// 00445148  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0044514b  57                   push edi
// 0044514c  395e0c               cmp dword ptr [esi + 0xc], ebx
// 0044514f  7606                 jbe 0x445157
// 00445151  ff1560b79800         call dword ptr [0x98b760]
// 00445157  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0044515a  8b2e                 mov ebp, dword ptr [esi]
// 0044515c  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0044515f  7606                 jbe 0x445167
// 00445161  ff1560b79800         call dword ptr [0x98b760]
// 00445167  8b06                 mov eax, dword ptr [esi]
// 00445169  53                   push ebx
// 0044516a  55                   push ebp
// 0044516b  57                   push edi
// 0044516c  50                   push eax
// 0044516d  8d442420             lea eax, [esp + 0x20]
// 00445171  50                   push eax
// 00445172  8bce                 mov ecx, esi
// 00445174  e8478d2600           call 0x6adec0
// 00445179  5f                   pop edi
// 0044517a  5e                   pop esi
// 0044517b  5d                   pop ebp
// 0044517c  5b                   pop ebx
// 0044517d  83c408               add esp, 8
// 00445180  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
