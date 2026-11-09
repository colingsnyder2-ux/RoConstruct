// from server: 100% by auto
// roc 2009-12 0057ba40  unit: RBX::VCylinderMesh::?$FactoryProduct::Creator  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057ba40
//
// 0057ba40  56                   push esi
// 0057ba41  8bf1                 mov esi, ecx
// 0057ba43  833e00               cmp dword ptr [esi], 0
// 0057ba46  57                   push edi
// 0057ba47  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 0057ba4d  7502                 jne 0x57ba51
// 0057ba4f  ffd7                 call edi
// 0057ba51  8b4604               mov eax, dword ptr [esi + 4]
// 0057ba54  8b4804               mov ecx, dword ptr [eax + 4]
// 0057ba57  8b06                 mov eax, dword ptr [esi]
// 0057ba59  894e04               mov dword ptr [esi + 4], ecx
// 0057ba5c  85c0                 test eax, eax
// 0057ba5e  7404                 je 0x57ba64
// 0057ba60  8b00                 mov eax, dword ptr [eax]
// 0057ba62  eb02                 jmp 0x57ba66
// 0057ba64  33c0                 xor eax, eax
// 0057ba66  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 0057ba69  7502                 jne 0x57ba6d
// 0057ba6b  ffd7                 call edi
// 0057ba6d  5f                   pop edi
// 0057ba6e  8bc6                 mov eax, esi
// 0057ba70  5e                   pop esi
// 0057ba71  c3                   ret 
// standard library list<ptr> (function ??F?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAV012@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
