// from server: 100% by auto
// roc 2007-08 00499f10  unit: RBX::Network::Client  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00499f10
//
// 00499f10  53                   push ebx
// 00499f11  55                   push ebp
// 00499f12  56                   push esi
// 00499f13  8bf1                 mov esi, ecx
// 00499f15  8b4610               mov eax, dword ptr [esi + 0x10]
// 00499f18  57                   push edi
// 00499f19  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00499f1c  03c7                 add eax, edi
// 00499f1e  3bf8                 cmp edi, eax
// 00499f20  7606                 jbe 0x499f28
// 00499f22  ff15d8e67700         call dword ptr [0x77e6d8]
// 00499f28  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00499f2b  034e0c               add ecx, dword ptr [esi + 0xc]
// 00499f2e  8bdf                 mov ebx, edi
// 00499f30  8bef                 mov ebp, edi
// 00499f32  c1eb02               shr ebx, 2
// 00499f35  83e503               and ebp, 3
// 00499f38  3bf9                 cmp edi, ecx
// 00499f3a  7206                 jb 0x499f42
// 00499f3c  ff15d8e67700         call dword ptr [0x77e6d8]
// 00499f42  8b4608               mov eax, dword ptr [esi + 8]
// 00499f45  3bc3                 cmp eax, ebx
// 00499f47  7702                 ja 0x499f4b
// 00499f49  2bd8                 sub ebx, eax
// 00499f4b  8b5604               mov edx, dword ptr [esi + 4]
// 00499f4e  8b049a               mov eax, dword ptr [edx + ebx*4]
// 00499f51  5f                   pop edi
// 00499f52  5e                   pop esi
// 00499f53  8d04a8               lea eax, [eax + ebp*4]
// 00499f56  5d                   pop ebp
// 00499f57  5b                   pop ebx
// 00499f58  c3                   ret 
// standard library deque<ptr> (function ?front@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEABQAUT@@XZ)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
