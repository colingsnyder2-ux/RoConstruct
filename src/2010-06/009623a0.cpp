// from server: 100% by auto
// roc 2010-06 009623a0  unit: RBX::SceneUpdater  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009623a0
//
// 009623a0  56                   push esi
// 009623a1  8b742410             mov esi, dword ptr [esp + 0x10]
// 009623a5  3bce                 cmp ecx, esi
// 009623a7  740f                 je 0x9623b8
// 009623a9  57                   push edi
// 009623aa  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 009623ae  57                   push edi
// 009623af  e82c1ddaff           call 0x7040e0
// 009623b4  297e18               sub dword ptr [esi + 0x18], edi
// 009623b7  5f                   pop edi
// 009623b8  8b442418             mov eax, dword ptr [esp + 0x18]
// 009623bc  8b4804               mov ecx, dword ptr [eax + 4]
// 009623bf  8b542420             mov edx, dword ptr [esp + 0x20]
// 009623c3  8911                 mov dword ptr [ecx], edx
// 009623c5  8b442420             mov eax, dword ptr [esp + 0x20]
// 009623c9  8b4804               mov ecx, dword ptr [eax + 4]
// 009623cc  8b54240c             mov edx, dword ptr [esp + 0xc]
// 009623d0  8911                 mov dword ptr [ecx], edx
// 009623d2  8b44240c             mov eax, dword ptr [esp + 0xc]
// 009623d6  8b4804               mov ecx, dword ptr [eax + 4]
// 009623d9  8b542418             mov edx, dword ptr [esp + 0x18]
// 009623dd  8911                 mov dword ptr [ecx], edx
// 009623df  8b44240c             mov eax, dword ptr [esp + 0xc]
// 009623e3  8b542420             mov edx, dword ptr [esp + 0x20]
// 009623e7  8b5204               mov edx, dword ptr [edx + 4]
// 009623ea  8b4804               mov ecx, dword ptr [eax + 4]
// 009623ed  895004               mov dword ptr [eax + 4], edx
// 009623f0  8b442418             mov eax, dword ptr [esp + 0x18]
// 009623f4  8b5004               mov edx, dword ptr [eax + 4]
// 009623f7  8b442420             mov eax, dword ptr [esp + 0x20]
// 009623fb  895004               mov dword ptr [eax + 4], edx
// 009623fe  8b542418             mov edx, dword ptr [esp + 0x18]
// 00962402  894a04               mov dword ptr [edx + 4], ecx
// 00962405  5e                   pop esi
// 00962406  c22400               ret 0x24
// standard library list<ptr> (function ?_Splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@00I_N@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
