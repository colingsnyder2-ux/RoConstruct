// from server: 100% by auto
// roc 2009-12 00582270  unit: Ogre::RbxSceneUpdater  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00582270
//
// 00582270  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00582274  8b5004               mov edx, dword ptr [eax + 4]
// 00582277  53                   push ebx
// 00582278  56                   push esi
// 00582279  57                   push edi
// 0058227a  8bd9                 mov ebx, ecx
// 0058227c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00582280  8d7804               lea edi, [eax + 4]
// 00582283  51                   push ecx
// 00582284  52                   push edx
// 00582285  50                   push eax
// 00582286  8bcb                 mov ecx, ebx
// 00582288  e8b3f4ffff           call 0x581740
// 0058228d  6a01                 push 1
// 0058228f  8bcb                 mov ecx, ebx
// 00582291  8bf0                 mov esi, eax
// 00582293  e8089dffff           call 0x57bfa0
// 00582298  8937                 mov dword ptr [edi], esi
// 0058229a  8b4604               mov eax, dword ptr [esi + 4]
// 0058229d  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 005822a3  8930                 mov dword ptr [eax], esi
// 005822a5  8b442414             mov eax, dword ptr [esp + 0x14]
// 005822a9  85c0                 test eax, eax
// 005822ab  7506                 jne 0x5822b3
// 005822ad  ffd7                 call edi
// 005822af  8b442414             mov eax, dword ptr [esp + 0x14]
// 005822b3  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005822b7  8b4904               mov ecx, dword ptr [ecx + 4]
// 005822ba  894c2418             mov dword ptr [esp + 0x18], ecx
// 005822be  85c0                 test eax, eax
// 005822c0  7404                 je 0x5822c6
// 005822c2  8b00                 mov eax, dword ptr [eax]
// 005822c4  eb02                 jmp 0x5822c8
// 005822c6  33c0                 xor eax, eax
// 005822c8  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 005822cb  7506                 jne 0x5822d3
// 005822cd  ffd7                 call edi
// 005822cf  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005822d3  8b742410             mov esi, dword ptr [esp + 0x10]
// 005822d7  c70600000000         mov dword ptr [esi], 0
// 005822dd  894e04               mov dword ptr [esi + 4], ecx
// 005822e0  85db                 test ebx, ebx
// 005822e2  7502                 jne 0x5822e6
// 005822e4  ffd7                 call edi
// 005822e6  8b13                 mov edx, dword ptr [ebx]
// 005822e8  5f                   pop edi
// 005822e9  8916                 mov dword ptr [esi], edx
// 005822eb  8bc6                 mov eax, esi
// 005822ed  5e                   pop esi
// 005822ee  5b                   pop ebx
// 005822ef  c21000               ret 0x10
// standard library list<ptr> (function ?insert@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@ABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
