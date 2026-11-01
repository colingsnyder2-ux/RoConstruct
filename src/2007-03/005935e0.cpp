// from server: 100% by auto
// roc 2007-03 005935e0  unit: seg_00590000  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005935e0
//
// 005935e0  53                   push ebx
// 005935e1  56                   push esi
// 005935e2  8bf1                 mov esi, ecx
// 005935e4  33db                 xor ebx, ebx
// 005935e6  395e10               cmp dword ptr [esi + 0x10], ebx
// 005935e9  57                   push edi
// 005935ea  7440                 je 0x59362c
// 005935ec  83cfff               or edi, 0xffffffff
// 005935ef  90                   nop 
// 005935f0  8b4610               mov eax, dword ptr [esi + 0x10]
// 005935f3  3bc3                 cmp eax, ebx
// 005935f5  7430                 je 0x593627
// 005935f7  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 005935fa  8b5608               mov edx, dword ptr [esi + 8]
// 005935fd  8d4408ff             lea eax, [eax + ecx - 1]
// 00593601  8bc8                 mov ecx, eax
// 00593603  c1e904               shr ecx, 4
// 00593606  3bd1                 cmp edx, ecx
// 00593608  7702                 ja 0x59360c
// 0059360a  2bca                 sub ecx, edx
// 0059360c  8b5604               mov edx, dword ptr [esi + 4]
// 0059360f  83e00f               and eax, 0xf
// 00593612  03048a               add eax, dword ptr [edx + ecx*4]
// 00593615  8d4e01               lea ecx, [esi + 1]
// 00593618  50                   push eax
// 00593619  ff1520e57700         call dword ptr [0x77e520]
// 0059361f  017e10               add dword ptr [esi + 0x10], edi
// 00593622  7503                 jne 0x593627
// 00593624  895e0c               mov dword ptr [esi + 0xc], ebx
// 00593627  395e10               cmp dword ptr [esi + 0x10], ebx
// 0059362a  75c4                 jne 0x5935f0
// 0059362c  8b7e08               mov edi, dword ptr [esi + 8]
// 0059362f  3bfb                 cmp edi, ebx
// 00593631  7620                 jbe 0x593653
// 00593633  8b4604               mov eax, dword ptr [esi + 4]
// 00593636  83ef01               sub edi, 1
// 00593639  391cb8               cmp dword ptr [eax + edi*4], ebx
// 0059363c  8d04b8               lea eax, [eax + edi*4]
// 0059363f  740e                 je 0x59364f
// 00593641  8b08                 mov ecx, dword ptr [eax]
// 00593643  6a10                 push 0x10
// 00593645  51                   push ecx
// 00593646  8d4e01               lea ecx, [esi + 1]
// 00593649  ff1560e77700         call dword ptr [0x77e760]
// 0059364f  3bfb                 cmp edi, ebx
// 00593651  77e0                 ja 0x593633
// 00593653  8b4604               mov eax, dword ptr [esi + 4]
// 00593656  3bc3                 cmp eax, ebx
// 00593658  7409                 je 0x593663
// 0059365a  50                   push eax
// 0059365b  e890aa0800           call 0x61e0f0
// 00593660  83c404               add esp, 4
// 00593663  5f                   pop edi
// 00593664  895e04               mov dword ptr [esi + 4], ebx
// 00593667  895e08               mov dword ptr [esi + 8], ebx
// 0059366a  5e                   pop esi
// 0059366b  5b                   pop ebx
// 0059366c  c3                   ret 
// standard library deque<char> (function ?_Tidy@?$deque@DV?$allocator@D@std@@@std@@IAEXXZ)

// stl: deque<char>
typedef char E;
#include <deque>
template class std::deque<E>;
