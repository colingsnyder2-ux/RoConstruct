// from server: 100% by auto
// roc 2009-06 00476aa0  unit: Ogre::RbxMeshLoader  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00476aa0
//
// 00476aa0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00476aa4  8b5004               mov edx, dword ptr [eax + 4]
// 00476aa7  53                   push ebx
// 00476aa8  56                   push esi
// 00476aa9  57                   push edi
// 00476aaa  8bd9                 mov ebx, ecx
// 00476aac  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00476ab0  8d7804               lea edi, [eax + 4]
// 00476ab3  51                   push ecx
// 00476ab4  52                   push edx
// 00476ab5  50                   push eax
// 00476ab6  8bcb                 mov ecx, ebx
// 00476ab8  e8d3b11f00           call 0x671c90
// 00476abd  6a01                 push 1
// 00476abf  8bcb                 mov ecx, ebx
// 00476ac1  8bf0                 mov esi, eax
// 00476ac3  e808b21f00           call 0x671cd0
// 00476ac8  8937                 mov dword ptr [edi], esi
// 00476aca  8b4604               mov eax, dword ptr [esi + 4]
// 00476acd  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 00476ad3  8930                 mov dword ptr [eax], esi
// 00476ad5  8b442414             mov eax, dword ptr [esp + 0x14]
// 00476ad9  85c0                 test eax, eax
// 00476adb  7506                 jne 0x476ae3
// 00476add  ffd7                 call edi
// 00476adf  8b442414             mov eax, dword ptr [esp + 0x14]
// 00476ae3  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00476ae7  8b4904               mov ecx, dword ptr [ecx + 4]
// 00476aea  894c2418             mov dword ptr [esp + 0x18], ecx
// 00476aee  85c0                 test eax, eax
// 00476af0  7404                 je 0x476af6
// 00476af2  8b00                 mov eax, dword ptr [eax]
// 00476af4  eb02                 jmp 0x476af8
// 00476af6  33c0                 xor eax, eax
// 00476af8  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 00476afb  7506                 jne 0x476b03
// 00476afd  ffd7                 call edi
// 00476aff  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00476b03  8b742410             mov esi, dword ptr [esp + 0x10]
// 00476b07  c70600000000         mov dword ptr [esi], 0
// 00476b0d  894e04               mov dword ptr [esi + 4], ecx
// 00476b10  85db                 test ebx, ebx
// 00476b12  7502                 jne 0x476b16
// 00476b14  ffd7                 call edi
// 00476b16  8b13                 mov edx, dword ptr [ebx]
// 00476b18  5f                   pop edi
// 00476b19  8916                 mov dword ptr [esi], edx
// 00476b1b  8bc6                 mov eax, esi
// 00476b1d  5e                   pop esi
// 00476b1e  5b                   pop ebx
// 00476b1f  c21000               ret 0x10
// standard library list<ptr> (function ?insert@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@ABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
