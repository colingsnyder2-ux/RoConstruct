// from server: 100% by auto
// roc 2008-06 006798b0  unit: Ogre::RbxSceneManagerFactory  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006798b0
//
// 006798b0  6aff                 push -1
// 006798b2  68e8727d00           push 0x7d72e8
// 006798b7  64a100000000         mov eax, dword ptr fs:[0]
// 006798bd  50                   push eax
// 006798be  64892500000000       mov dword ptr fs:[0], esp
// 006798c5  83ec08               sub esp, 8
// 006798c8  56                   push esi
// 006798c9  8bf1                 mov esi, ecx
// 006798cb  6a04                 push 4
// 006798cd  8974240c             mov dword ptr [esp + 0xc], esi
// 006798d1  e84a700200           call 0x6a0920
// 006798d6  83c404               add esp, 4
// 006798d9  85c0                 test eax, eax
// 006798db  7404                 je 0x6798e1
// 006798dd  8930                 mov dword ptr [eax], esi
// 006798df  eb02                 jmp 0x6798e3
// 006798e1  33c0                 xor eax, eax
// 006798e3  8906                 mov dword ptr [esi], eax
// 006798e5  d9ee                 fldz 
// 006798e7  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006798eb  d95c2404             fstp dword ptr [esp + 4]
// 006798ef  8d442404             lea eax, [esp + 4]
// 006798f3  50                   push eax
// 006798f4  51                   push ecx
// 006798f5  8bce                 mov ecx, esi
// 006798f7  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 006798ff  e8acf7ffff           call 0x6790b0
// 00679904  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00679908  8bc6                 mov eax, esi
// 0067990a  5e                   pop esi
// 0067990b  64890d00000000       mov dword ptr fs:[0], ecx
// 00679912  83c414               add esp, 0x14
// 00679915  c20400               ret 4
// standard library vector<float> (function ??0?$vector@MV?$allocator@M@std@@@std@@QAE@I@Z)

// stl: vector<float>
typedef float E;
#include <vector>
template class std::vector<E>;
