// from server: 100% by auto
// roc 2008-06 00594ec0  unit: RBX::Lua::ThreadRef::VNode::?$sp_counted_impl_p  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00594ec0
//
// 00594ec0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00594ec4  8b5004               mov edx, dword ptr [eax + 4]
// 00594ec7  53                   push ebx
// 00594ec8  56                   push esi
// 00594ec9  57                   push edi
// 00594eca  8bd9                 mov ebx, ecx
// 00594ecc  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00594ed0  8d7804               lea edi, [eax + 4]
// 00594ed3  51                   push ecx
// 00594ed4  52                   push edx
// 00594ed5  50                   push eax
// 00594ed6  8bcb                 mov ecx, ebx
// 00594ed8  e843ffffff           call 0x594e20
// 00594edd  6a01                 push 1
// 00594edf  8bcb                 mov ecx, ebx
// 00594ee1  8bf0                 mov esi, eax
// 00594ee3  e8d8dd0e00           call 0x682cc0
// 00594ee8  8937                 mov dword ptr [edi], esi
// 00594eea  8b4604               mov eax, dword ptr [esi + 4]
// 00594eed  8b3d90288000         mov edi, dword ptr [0x802890]
// 00594ef3  8930                 mov dword ptr [eax], esi
// 00594ef5  8b442414             mov eax, dword ptr [esp + 0x14]
// 00594ef9  85c0                 test eax, eax
// 00594efb  7506                 jne 0x594f03
// 00594efd  ffd7                 call edi
// 00594eff  8b442414             mov eax, dword ptr [esp + 0x14]
// 00594f03  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00594f07  8b4904               mov ecx, dword ptr [ecx + 4]
// 00594f0a  894c2418             mov dword ptr [esp + 0x18], ecx
// 00594f0e  85c0                 test eax, eax
// 00594f10  7404                 je 0x594f16
// 00594f12  8b00                 mov eax, dword ptr [eax]
// 00594f14  eb02                 jmp 0x594f18
// 00594f16  33c0                 xor eax, eax
// 00594f18  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 00594f1b  7506                 jne 0x594f23
// 00594f1d  ffd7                 call edi
// 00594f1f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00594f23  8b742410             mov esi, dword ptr [esp + 0x10]
// 00594f27  c70600000000         mov dword ptr [esi], 0
// 00594f2d  894e04               mov dword ptr [esi + 4], ecx
// 00594f30  85db                 test ebx, ebx
// 00594f32  7502                 jne 0x594f36
// 00594f34  ffd7                 call edi
// 00594f36  8b13                 mov edx, dword ptr [ebx]
// 00594f38  5f                   pop edi
// 00594f39  8916                 mov dword ptr [esi], edx
// 00594f3b  8bc6                 mov eax, esi
// 00594f3d  5e                   pop esi
// 00594f3e  5b                   pop ebx
// 00594f3f  c21000               ret 0x10
// standard library list<ptr> (function ?insert@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@ABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
