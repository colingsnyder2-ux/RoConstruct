// from server: 100% by auto
// roc 2009-12 0057bca0  unit: RBX::VCylinderMesh::?$FactoryProduct::Creator  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057bca0
//
// 0057bca0  56                   push esi
// 0057bca1  8bf1                 mov esi, ecx
// 0057bca3  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0057bca6  8b01                 mov eax, dword ptr [ecx]
// 0057bca8  8909                 mov dword ptr [ecx], ecx
// 0057bcaa  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0057bcad  894904               mov dword ptr [ecx + 4], ecx
// 0057bcb0  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0057bcb7  3b4614               cmp eax, dword ptr [esi + 0x14]
// 0057bcba  7417                 je 0x57bcd3
// 0057bcbc  57                   push edi
// 0057bcbd  8d4900               lea ecx, [ecx]
// 0057bcc0  8b38                 mov edi, dword ptr [eax]
// 0057bcc2  50                   push eax
// 0057bcc3  e8927b2700           call 0x7f385a
// 0057bcc8  83c404               add esp, 4
// 0057bccb  8bc7                 mov eax, edi
// 0057bccd  3b7e14               cmp edi, dword ptr [esi + 0x14]
// 0057bcd0  75ee                 jne 0x57bcc0
// 0057bcd2  5f                   pop edi
// 0057bcd3  5e                   pop esi
// 0057bcd4  c3                   ret 
// standard library list<ptr> (function ?clear@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
