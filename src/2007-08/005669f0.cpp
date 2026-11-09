// from server: 100% by auto
// roc 2007-08 005669f0  unit: TextXmlWriter  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005669f0
//
// 005669f0  53                   push ebx
// 005669f1  55                   push ebp
// 005669f2  56                   push esi
// 005669f3  8bf1                 mov esi, ecx
// 005669f5  8b460c               mov eax, dword ptr [esi + 0xc]
// 005669f8  57                   push edi
// 005669f9  8b7e10               mov edi, dword ptr [esi + 0x10]
// 005669fc  03f8                 add edi, eax
// 005669fe  3bc7                 cmp eax, edi
// 00566a00  7606                 jbe 0x566a08
// 00566a02  ff15d8e67700         call dword ptr [0x77e6d8]
// 00566a08  8b460c               mov eax, dword ptr [esi + 0xc]
// 00566a0b  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00566a0e  83c7ff               add edi, -1
// 00566a11  03c8                 add ecx, eax
// 00566a13  3bf9                 cmp edi, ecx
// 00566a15  7704                 ja 0x566a1b
// 00566a17  3bf8                 cmp edi, eax
// 00566a19  7306                 jae 0x566a21
// 00566a1b  ff15d8e67700         call dword ptr [0x77e6d8]
// 00566a21  8b560c               mov edx, dword ptr [esi + 0xc]
// 00566a24  035610               add edx, dword ptr [esi + 0x10]
// 00566a27  8bdf                 mov ebx, edi
// 00566a29  8bef                 mov ebp, edi
// 00566a2b  c1eb02               shr ebx, 2
// 00566a2e  83e503               and ebp, 3
// 00566a31  3bfa                 cmp edi, edx
// 00566a33  7206                 jb 0x566a3b
// 00566a35  ff15d8e67700         call dword ptr [0x77e6d8]
// 00566a3b  8b4608               mov eax, dword ptr [esi + 8]
// 00566a3e  3bc3                 cmp eax, ebx
// 00566a40  7702                 ja 0x566a44
// 00566a42  2bd8                 sub ebx, eax
// 00566a44  8b4604               mov eax, dword ptr [esi + 4]
// 00566a47  8b0c98               mov ecx, dword ptr [eax + ebx*4]
// 00566a4a  5f                   pop edi
// 00566a4b  5e                   pop esi
// 00566a4c  8d04a9               lea eax, [ecx + ebp*4]
// 00566a4f  5d                   pop ebp
// 00566a50  5b                   pop ebx
// 00566a51  c3                   ret 
// standard library deque<ptr> (function ?back@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEABQAUT@@XZ)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
