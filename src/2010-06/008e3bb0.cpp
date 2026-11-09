// from server: 100% by auto
// roc 2010-06 008e3bb0  unit: RBX::RbxTextureProxy  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008e3bb0
//
// 008e3bb0  6aff                 push -1
// 008e3bb2  68b8d19b00           push 0x9bd1b8
// 008e3bb7  64a100000000         mov eax, dword ptr fs:[0]
// 008e3bbd  50                   push eax
// 008e3bbe  64892500000000       mov dword ptr fs:[0], esp
// 008e3bc5  83ec0c               sub esp, 0xc
// 008e3bc8  56                   push esi
// 008e3bc9  8bf1                 mov esi, ecx
// 008e3bcb  89742404             mov dword ptr [esp + 4], esi
// 008e3bcf  8b4618               mov eax, dword ptr [esi + 0x18]
// 008e3bd2  8b0e                 mov ecx, dword ptr [esi]
// 008e3bd4  8b10                 mov edx, dword ptr [eax]
// 008e3bd6  50                   push eax
// 008e3bd7  51                   push ecx
// 008e3bd8  52                   push edx
// 008e3bd9  51                   push ecx
// 008e3bda  8d442418             lea eax, [esp + 0x18]
// 008e3bde  50                   push eax
// 008e3bdf  8bce                 mov ecx, esi
// 008e3be1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 008e3be9  e832feffff           call 0x8e3a20
// 008e3bee  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 008e3bf1  51                   push ecx
// 008e3bf2  e8a33decff           call 0x7a799a
// 008e3bf7  8b16                 mov edx, dword ptr [esi]
// 008e3bf9  52                   push edx
// 008e3bfa  c7461800000000       mov dword ptr [esi + 0x18], 0
// 008e3c01  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 008e3c08  e88d3decff           call 0x7a799a
// 008e3c0d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008e3c11  83c408               add esp, 8
// 008e3c14  5e                   pop esi
// 008e3c15  64890d00000000       mov dword ptr fs:[0], ecx
// 008e3c1c  83c418               add esp, 0x18
// 008e3c1f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
