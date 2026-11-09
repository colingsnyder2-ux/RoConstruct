// from server: 100% by auto
// roc 2010-06 00540b80  unit: RBX::AggregatingSceneManager  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00540b80
//
// 00540b80  56                   push esi
// 00540b81  8b742410             mov esi, dword ptr [esp + 0x10]
// 00540b85  3bce                 cmp ecx, esi
// 00540b87  740f                 je 0x540b98
// 00540b89  57                   push edi
// 00540b8a  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00540b8e  57                   push edi
// 00540b8f  e87c900a00           call 0x5e9c10
// 00540b94  297e18               sub dword ptr [esi + 0x18], edi
// 00540b97  5f                   pop edi
// 00540b98  8b442418             mov eax, dword ptr [esp + 0x18]
// 00540b9c  8b4804               mov ecx, dword ptr [eax + 4]
// 00540b9f  8b542420             mov edx, dword ptr [esp + 0x20]
// 00540ba3  8911                 mov dword ptr [ecx], edx
// 00540ba5  8b442420             mov eax, dword ptr [esp + 0x20]
// 00540ba9  8b4804               mov ecx, dword ptr [eax + 4]
// 00540bac  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00540bb0  8911                 mov dword ptr [ecx], edx
// 00540bb2  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00540bb6  8b4804               mov ecx, dword ptr [eax + 4]
// 00540bb9  8b542418             mov edx, dword ptr [esp + 0x18]
// 00540bbd  8911                 mov dword ptr [ecx], edx
// 00540bbf  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00540bc3  8b542420             mov edx, dword ptr [esp + 0x20]
// 00540bc7  8b5204               mov edx, dword ptr [edx + 4]
// 00540bca  8b4804               mov ecx, dword ptr [eax + 4]
// 00540bcd  895004               mov dword ptr [eax + 4], edx
// 00540bd0  8b442418             mov eax, dword ptr [esp + 0x18]
// 00540bd4  8b5004               mov edx, dword ptr [eax + 4]
// 00540bd7  8b442420             mov eax, dword ptr [esp + 0x20]
// 00540bdb  895004               mov dword ptr [eax + 4], edx
// 00540bde  8b542418             mov edx, dword ptr [esp + 0x18]
// 00540be2  894a04               mov dword ptr [edx + 4], ecx
// 00540be5  5e                   pop esi
// 00540be6  c22400               ret 0x24
// standard library list<ptr> (function ?_Splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@00I_N@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
