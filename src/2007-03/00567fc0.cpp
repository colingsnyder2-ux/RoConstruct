// from server: 100% by auto
// roc 2007-03 00567fc0  unit: seg_00560000  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00567fc0
//
// 00567fc0  53                   push ebx
// 00567fc1  55                   push ebp
// 00567fc2  56                   push esi
// 00567fc3  8bf1                 mov esi, ecx
// 00567fc5  8b460c               mov eax, dword ptr [esi + 0xc]
// 00567fc8  57                   push edi
// 00567fc9  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00567fcc  03f8                 add edi, eax
// 00567fce  3bc7                 cmp eax, edi
// 00567fd0  7606                 jbe 0x567fd8
// 00567fd2  ff1544e97700         call dword ptr [0x77e944]
// 00567fd8  8b460c               mov eax, dword ptr [esi + 0xc]
// 00567fdb  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00567fde  83c7ff               add edi, -1
// 00567fe1  03c8                 add ecx, eax
// 00567fe3  3bf9                 cmp edi, ecx
// 00567fe5  7704                 ja 0x567feb
// 00567fe7  3bf8                 cmp edi, eax
// 00567fe9  7306                 jae 0x567ff1
// 00567feb  ff1544e97700         call dword ptr [0x77e944]
// 00567ff1  8b560c               mov edx, dword ptr [esi + 0xc]
// 00567ff4  035610               add edx, dword ptr [esi + 0x10]
// 00567ff7  8bdf                 mov ebx, edi
// 00567ff9  8bef                 mov ebp, edi
// 00567ffb  c1eb02               shr ebx, 2
// 00567ffe  83e503               and ebp, 3
// 00568001  3bfa                 cmp edi, edx
// 00568003  7206                 jb 0x56800b
// 00568005  ff1544e97700         call dword ptr [0x77e944]
// 0056800b  8b4608               mov eax, dword ptr [esi + 8]
// 0056800e  3bc3                 cmp eax, ebx
// 00568010  7702                 ja 0x568014
// 00568012  2bd8                 sub ebx, eax
// 00568014  8b4604               mov eax, dword ptr [esi + 4]
// 00568017  8b0c98               mov ecx, dword ptr [eax + ebx*4]
// 0056801a  5f                   pop edi
// 0056801b  5e                   pop esi
// 0056801c  8d04a9               lea eax, [ecx + ebp*4]
// 0056801f  5d                   pop ebp
// 00568020  5b                   pop ebx
// 00568021  c3                   ret 
// standard library deque<ptr> (function ?back@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEABQAUT@@XZ)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
