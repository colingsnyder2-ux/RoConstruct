// from server: 100% by auto
// roc 2009-12 006c0a70  unit: RBX::VInstance::?$NonFactoryProduct  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006c0a70
//
// 006c0a70  56                   push esi
// 006c0a71  8b742410             mov esi, dword ptr [esp + 0x10]
// 006c0a75  3bce                 cmp ecx, esi
// 006c0a77  740f                 je 0x6c0a88
// 006c0a79  57                   push edi
// 006c0a7a  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006c0a7e  57                   push edi
// 006c0a7f  e8bcd1ffff           call 0x6bdc40
// 006c0a84  297e18               sub dword ptr [esi + 0x18], edi
// 006c0a87  5f                   pop edi
// 006c0a88  8b442418             mov eax, dword ptr [esp + 0x18]
// 006c0a8c  8b4804               mov ecx, dword ptr [eax + 4]
// 006c0a8f  8b542420             mov edx, dword ptr [esp + 0x20]
// 006c0a93  8911                 mov dword ptr [ecx], edx
// 006c0a95  8b442420             mov eax, dword ptr [esp + 0x20]
// 006c0a99  8b4804               mov ecx, dword ptr [eax + 4]
// 006c0a9c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006c0aa0  8911                 mov dword ptr [ecx], edx
// 006c0aa2  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006c0aa6  8b4804               mov ecx, dword ptr [eax + 4]
// 006c0aa9  8b542418             mov edx, dword ptr [esp + 0x18]
// 006c0aad  8911                 mov dword ptr [ecx], edx
// 006c0aaf  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006c0ab3  8b542420             mov edx, dword ptr [esp + 0x20]
// 006c0ab7  8b5204               mov edx, dword ptr [edx + 4]
// 006c0aba  8b4804               mov ecx, dword ptr [eax + 4]
// 006c0abd  895004               mov dword ptr [eax + 4], edx
// 006c0ac0  8b442418             mov eax, dword ptr [esp + 0x18]
// 006c0ac4  8b5004               mov edx, dword ptr [eax + 4]
// 006c0ac7  8b442420             mov eax, dword ptr [esp + 0x20]
// 006c0acb  895004               mov dword ptr [eax + 4], edx
// 006c0ace  8b542418             mov edx, dword ptr [esp + 0x18]
// 006c0ad2  894a04               mov dword ptr [edx + 4], ecx
// 006c0ad5  5e                   pop esi
// 006c0ad6  c22400               ret 0x24
// standard library list<ptr> (function ?_Splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@00I_N@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
