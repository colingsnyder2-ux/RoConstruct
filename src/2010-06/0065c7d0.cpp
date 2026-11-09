// from server: 100% by auto
// roc 2010-06 0065c7d0  unit: RBX::VInstance::?$NonFactoryProduct  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0065c7d0
//
// 0065c7d0  56                   push esi
// 0065c7d1  8b742410             mov esi, dword ptr [esp + 0x10]
// 0065c7d5  3bce                 cmp ecx, esi
// 0065c7d7  740f                 je 0x65c7e8
// 0065c7d9  57                   push edi
// 0065c7da  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0065c7de  57                   push edi
// 0065c7df  e80ceeffff           call 0x65b5f0
// 0065c7e4  297e18               sub dword ptr [esi + 0x18], edi
// 0065c7e7  5f                   pop edi
// 0065c7e8  8b442418             mov eax, dword ptr [esp + 0x18]
// 0065c7ec  8b4804               mov ecx, dword ptr [eax + 4]
// 0065c7ef  8b542420             mov edx, dword ptr [esp + 0x20]
// 0065c7f3  8911                 mov dword ptr [ecx], edx
// 0065c7f5  8b442420             mov eax, dword ptr [esp + 0x20]
// 0065c7f9  8b4804               mov ecx, dword ptr [eax + 4]
// 0065c7fc  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0065c800  8911                 mov dword ptr [ecx], edx
// 0065c802  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0065c806  8b4804               mov ecx, dword ptr [eax + 4]
// 0065c809  8b542418             mov edx, dword ptr [esp + 0x18]
// 0065c80d  8911                 mov dword ptr [ecx], edx
// 0065c80f  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0065c813  8b542420             mov edx, dword ptr [esp + 0x20]
// 0065c817  8b5204               mov edx, dword ptr [edx + 4]
// 0065c81a  8b4804               mov ecx, dword ptr [eax + 4]
// 0065c81d  895004               mov dword ptr [eax + 4], edx
// 0065c820  8b442418             mov eax, dword ptr [esp + 0x18]
// 0065c824  8b5004               mov edx, dword ptr [eax + 4]
// 0065c827  8b442420             mov eax, dword ptr [esp + 0x20]
// 0065c82b  895004               mov dword ptr [eax + 4], edx
// 0065c82e  8b542418             mov edx, dword ptr [esp + 0x18]
// 0065c832  894a04               mov dword ptr [edx + 4], ecx
// 0065c835  5e                   pop esi
// 0065c836  c22400               ret 0x24
// standard library list<ptr> (function ?_Splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@00I_N@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
