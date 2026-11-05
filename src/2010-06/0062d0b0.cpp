// from server: 100% by auto
// roc 2010-06 0062d0b0  unit: RBX::VInstance::?$NonFactoryProduct  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0062d0b0
//
// 0062d0b0  56                   push esi
// 0062d0b1  8b742410             mov esi, dword ptr [esp + 0x10]
// 0062d0b5  3bce                 cmp ecx, esi
// 0062d0b7  740f                 je 0x62d0c8
// 0062d0b9  57                   push edi
// 0062d0ba  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0062d0be  57                   push edi
// 0062d0bf  e84cecffff           call 0x62bd10
// 0062d0c4  297e18               sub dword ptr [esi + 0x18], edi
// 0062d0c7  5f                   pop edi
// 0062d0c8  8b442418             mov eax, dword ptr [esp + 0x18]
// 0062d0cc  8b4804               mov ecx, dword ptr [eax + 4]
// 0062d0cf  8b542420             mov edx, dword ptr [esp + 0x20]
// 0062d0d3  8911                 mov dword ptr [ecx], edx
// 0062d0d5  8b442420             mov eax, dword ptr [esp + 0x20]
// 0062d0d9  8b4804               mov ecx, dword ptr [eax + 4]
// 0062d0dc  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0062d0e0  8911                 mov dword ptr [ecx], edx
// 0062d0e2  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0062d0e6  8b4804               mov ecx, dword ptr [eax + 4]
// 0062d0e9  8b542418             mov edx, dword ptr [esp + 0x18]
// 0062d0ed  8911                 mov dword ptr [ecx], edx
// 0062d0ef  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0062d0f3  8b542420             mov edx, dword ptr [esp + 0x20]
// 0062d0f7  8b5204               mov edx, dword ptr [edx + 4]
// 0062d0fa  8b4804               mov ecx, dword ptr [eax + 4]
// 0062d0fd  895004               mov dword ptr [eax + 4], edx
// 0062d100  8b442418             mov eax, dword ptr [esp + 0x18]
// 0062d104  8b5004               mov edx, dword ptr [eax + 4]
// 0062d107  8b442420             mov eax, dword ptr [esp + 0x20]
// 0062d10b  895004               mov dword ptr [eax + 4], edx
// 0062d10e  8b542418             mov edx, dword ptr [esp + 0x18]
// 0062d112  894a04               mov dword ptr [edx + 4], ecx
// 0062d115  5e                   pop esi
// 0062d116  c22400               ret 0x24
// standard library list<ptr> (function ?_Splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@00I_N@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
