// from server: 100% by auto
// roc 2007-03 00595bc0  unit: seg_00590000  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00595bc0
//
// 00595bc0  53                   push ebx
// 00595bc1  56                   push esi
// 00595bc2  8bf1                 mov esi, ecx
// 00595bc4  8b4610               mov eax, dword ptr [esi + 0x10]
// 00595bc7  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00595bca  03c8                 add ecx, eax
// 00595bcc  f6c10f               test cl, 0xf
// 00595bcf  57                   push edi
// 00595bd0  7514                 jne 0x595be6
// 00595bd2  83c010               add eax, 0x10
// 00595bd5  c1e804               shr eax, 4
// 00595bd8  394608               cmp dword ptr [esi + 8], eax
// 00595bdb  7709                 ja 0x595be6
// 00595bdd  6a01                 push 1
// 00595bdf  8bce                 mov ecx, esi
// 00595be1  e8faf3ffff           call 0x594fe0
// 00595be6  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00595be9  037e10               add edi, dword ptr [esi + 0x10]
// 00595bec  8b4608               mov eax, dword ptr [esi + 8]
// 00595bef  8bdf                 mov ebx, edi
// 00595bf1  c1eb04               shr ebx, 4
// 00595bf4  3bc3                 cmp eax, ebx
// 00595bf6  7702                 ja 0x595bfa
// 00595bf8  2bd8                 sub ebx, eax
// 00595bfa  8b5604               mov edx, dword ptr [esi + 4]
// 00595bfd  833c9a00             cmp dword ptr [edx + ebx*4], 0
// 00595c01  7511                 jne 0x595c14
// 00595c03  6a10                 push 0x10
// 00595c05  8d4e01               lea ecx, [esi + 1]
// 00595c08  ff15c8e57700         call dword ptr [0x77e5c8]
// 00595c0e  8b4e04               mov ecx, dword ptr [esi + 4]
// 00595c11  890499               mov dword ptr [ecx + ebx*4], eax
// 00595c14  8b4604               mov eax, dword ptr [esi + 4]
// 00595c17  8b542410             mov edx, dword ptr [esp + 0x10]
// 00595c1b  83e70f               and edi, 0xf
// 00595c1e  033c98               add edi, dword ptr [eax + ebx*4]
// 00595c21  52                   push edx
// 00595c22  57                   push edi
// 00595c23  8d4e01               lea ecx, [esi + 1]
// 00595c26  ff15f8e47700         call dword ptr [0x77e4f8]
// 00595c2c  83461001             add dword ptr [esi + 0x10], 1
// 00595c30  5f                   pop edi
// 00595c31  5e                   pop esi
// 00595c32  5b                   pop ebx
// 00595c33  c20400               ret 4
// standard library deque<char> (function ?push_back@?$deque@DV?$allocator@D@std@@@std@@QAEXABD@Z)

// stl: deque<char>
typedef char E;
#include <deque>
template class std::deque<E>;
