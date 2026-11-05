// from server: 100% by auto
// roc 2009-06 00475cf0  unit: Ogre::RbxSceneManagerFactory  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00475cf0
//
// 00475cf0  56                   push esi
// 00475cf1  8bf1                 mov esi, ecx
// 00475cf3  8b06                 mov eax, dword ptr [esi]
// 00475cf5  57                   push edi
// 00475cf6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00475cfa  85c0                 test eax, eax
// 00475cfc  7404                 je 0x475d02
// 00475cfe  3b07                 cmp eax, dword ptr [edi]
// 00475d00  7406                 je 0x475d08
// 00475d02  ff15ace98900         call dword ptr [0x89e9ac]
// 00475d08  8b4604               mov eax, dword ptr [esi + 4]
// 00475d0b  33c9                 xor ecx, ecx
// 00475d0d  3b4704               cmp eax, dword ptr [edi + 4]
// 00475d10  5f                   pop edi
// 00475d11  0f95c1               setne cl
// 00475d14  8ac1                 mov al, cl
// 00475d16  5e                   pop esi
// 00475d17  c20400               ret 4
// standard library vector<ptr> (function ??9?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBE_NABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
