// from server: 100% by auto
// roc 2008-06 00648ec0  unit: RBX::Block  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00648ec0
//
// 00648ec0  6aff                 push -1
// 00648ec2  6828d97b00           push 0x7bd928
// 00648ec7  64a100000000         mov eax, dword ptr fs:[0]
// 00648ecd  50                   push eax
// 00648ece  64892500000000       mov dword ptr fs:[0], esp
// 00648ed5  83ec0c               sub esp, 0xc
// 00648ed8  56                   push esi
// 00648ed9  8bf1                 mov esi, ecx
// 00648edb  89742404             mov dword ptr [esp + 4], esi
// 00648edf  8b4618               mov eax, dword ptr [esi + 0x18]
// 00648ee2  8b0e                 mov ecx, dword ptr [esi]
// 00648ee4  8b10                 mov edx, dword ptr [eax]
// 00648ee6  50                   push eax
// 00648ee7  51                   push ecx
// 00648ee8  52                   push edx
// 00648ee9  51                   push ecx
// 00648eea  8d442418             lea eax, [esp + 0x18]
// 00648eee  50                   push eax
// 00648eef  8bce                 mov ecx, esi
// 00648ef1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00648ef9  e892fbffff           call 0x648a90
// 00648efe  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00648f01  51                   push ecx
// 00648f02  e873770500           call 0x6a067a
// 00648f07  8b16                 mov edx, dword ptr [esi]
// 00648f09  52                   push edx
// 00648f0a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00648f11  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00648f18  e85d770500           call 0x6a067a
// 00648f1d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00648f21  83c408               add esp, 8
// 00648f24  5e                   pop esi
// 00648f25  64890d00000000       mov dword ptr fs:[0], ecx
// 00648f2c  83c418               add esp, 0x18
// 00648f2f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
