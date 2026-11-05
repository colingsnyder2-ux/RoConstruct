// from server: 100% by auto
// roc 2010-06 00759420  unit: RBX::PyramidPoly  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00759420
//
// 00759420  6aff                 push -1
// 00759422  68b8d19b00           push 0x9bd1b8
// 00759427  64a100000000         mov eax, dword ptr fs:[0]
// 0075942d  50                   push eax
// 0075942e  64892500000000       mov dword ptr fs:[0], esp
// 00759435  83ec0c               sub esp, 0xc
// 00759438  56                   push esi
// 00759439  8bf1                 mov esi, ecx
// 0075943b  89742404             mov dword ptr [esp + 4], esi
// 0075943f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00759442  8b0e                 mov ecx, dword ptr [esi]
// 00759444  8b10                 mov edx, dword ptr [eax]
// 00759446  50                   push eax
// 00759447  51                   push ecx
// 00759448  52                   push edx
// 00759449  51                   push ecx
// 0075944a  8d442418             lea eax, [esp + 0x18]
// 0075944e  50                   push eax
// 0075944f  8bce                 mov ecx, esi
// 00759451  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00759459  e872feffff           call 0x7592d0
// 0075945e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00759461  51                   push ecx
// 00759462  e833e50400           call 0x7a799a
// 00759467  8b16                 mov edx, dword ptr [esi]
// 00759469  52                   push edx
// 0075946a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00759471  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00759478  e81de50400           call 0x7a799a
// 0075947d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00759481  83c408               add esp, 8
// 00759484  5e                   pop esi
// 00759485  64890d00000000       mov dword ptr fs:[0], ecx
// 0075948c  83c418               add esp, 0x18
// 0075948f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
