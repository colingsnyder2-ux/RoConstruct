// from server: 100% by auto
// roc 2010-06 00425bb0  unit: MainLogManager  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00425bb0
//
// 00425bb0  56                   push esi
// 00425bb1  8b742410             mov esi, dword ptr [esp + 0x10]
// 00425bb5  3bce                 cmp ecx, esi
// 00425bb7  740f                 je 0x425bc8
// 00425bb9  57                   push edi
// 00425bba  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00425bbe  57                   push edi
// 00425bbf  e8bceaffff           call 0x424680
// 00425bc4  297e18               sub dword ptr [esi + 0x18], edi
// 00425bc7  5f                   pop edi
// 00425bc8  8b442418             mov eax, dword ptr [esp + 0x18]
// 00425bcc  8b4804               mov ecx, dword ptr [eax + 4]
// 00425bcf  8b542420             mov edx, dword ptr [esp + 0x20]
// 00425bd3  8911                 mov dword ptr [ecx], edx
// 00425bd5  8b442420             mov eax, dword ptr [esp + 0x20]
// 00425bd9  8b4804               mov ecx, dword ptr [eax + 4]
// 00425bdc  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00425be0  8911                 mov dword ptr [ecx], edx
// 00425be2  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00425be6  8b4804               mov ecx, dword ptr [eax + 4]
// 00425be9  8b542418             mov edx, dword ptr [esp + 0x18]
// 00425bed  8911                 mov dword ptr [ecx], edx
// 00425bef  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00425bf3  8b542420             mov edx, dword ptr [esp + 0x20]
// 00425bf7  8b5204               mov edx, dword ptr [edx + 4]
// 00425bfa  8b4804               mov ecx, dword ptr [eax + 4]
// 00425bfd  895004               mov dword ptr [eax + 4], edx
// 00425c00  8b442418             mov eax, dword ptr [esp + 0x18]
// 00425c04  8b5004               mov edx, dword ptr [eax + 4]
// 00425c07  8b442420             mov eax, dword ptr [esp + 0x20]
// 00425c0b  895004               mov dword ptr [eax + 4], edx
// 00425c0e  8b542418             mov edx, dword ptr [esp + 0x18]
// 00425c12  894a04               mov dword ptr [edx + 4], ecx
// 00425c15  5e                   pop esi
// 00425c16  c22400               ret 0x24
// standard library list<ptr> (function ?_Splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@00I_N@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
