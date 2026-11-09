// from server: 100% by auto
// roc 2010-06 00641cb0  unit: RBX::VInstance::?$NonFactoryProduct  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00641cb0
//
// 00641cb0  56                   push esi
// 00641cb1  8b742410             mov esi, dword ptr [esp + 0x10]
// 00641cb5  3bce                 cmp ecx, esi
// 00641cb7  740f                 je 0x641cc8
// 00641cb9  57                   push edi
// 00641cba  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00641cbe  57                   push edi
// 00641cbf  e8ac9b0200           call 0x66b870
// 00641cc4  297e18               sub dword ptr [esi + 0x18], edi
// 00641cc7  5f                   pop edi
// 00641cc8  8b442418             mov eax, dword ptr [esp + 0x18]
// 00641ccc  8b4804               mov ecx, dword ptr [eax + 4]
// 00641ccf  8b542420             mov edx, dword ptr [esp + 0x20]
// 00641cd3  8911                 mov dword ptr [ecx], edx
// 00641cd5  8b442420             mov eax, dword ptr [esp + 0x20]
// 00641cd9  8b4804               mov ecx, dword ptr [eax + 4]
// 00641cdc  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00641ce0  8911                 mov dword ptr [ecx], edx
// 00641ce2  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00641ce6  8b4804               mov ecx, dword ptr [eax + 4]
// 00641ce9  8b542418             mov edx, dword ptr [esp + 0x18]
// 00641ced  8911                 mov dword ptr [ecx], edx
// 00641cef  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00641cf3  8b542420             mov edx, dword ptr [esp + 0x20]
// 00641cf7  8b5204               mov edx, dword ptr [edx + 4]
// 00641cfa  8b4804               mov ecx, dword ptr [eax + 4]
// 00641cfd  895004               mov dword ptr [eax + 4], edx
// 00641d00  8b442418             mov eax, dword ptr [esp + 0x18]
// 00641d04  8b5004               mov edx, dword ptr [eax + 4]
// 00641d07  8b442420             mov eax, dword ptr [esp + 0x20]
// 00641d0b  895004               mov dword ptr [eax + 4], edx
// 00641d0e  8b542418             mov edx, dword ptr [esp + 0x18]
// 00641d12  894a04               mov dword ptr [edx + 4], ecx
// 00641d15  5e                   pop esi
// 00641d16  c22400               ret 0x24
// standard library list<ptr> (function ?_Splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@00I_N@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
