// from server: 100% by auto
// roc 2009-12 0057d9b0  unit: std::Vlength_error::U?$error_info_injector::?$clone_impl  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057d9b0
//
// 0057d9b0  56                   push esi
// 0057d9b1  8b742410             mov esi, dword ptr [esp + 0x10]
// 0057d9b5  3bce                 cmp ecx, esi
// 0057d9b7  740f                 je 0x57d9c8
// 0057d9b9  57                   push edi
// 0057d9ba  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0057d9be  57                   push edi
// 0057d9bf  e83ce5ffff           call 0x57bf00
// 0057d9c4  297e18               sub dword ptr [esi + 0x18], edi
// 0057d9c7  5f                   pop edi
// 0057d9c8  8b442418             mov eax, dword ptr [esp + 0x18]
// 0057d9cc  8b4804               mov ecx, dword ptr [eax + 4]
// 0057d9cf  8b542420             mov edx, dword ptr [esp + 0x20]
// 0057d9d3  8911                 mov dword ptr [ecx], edx
// 0057d9d5  8b442420             mov eax, dword ptr [esp + 0x20]
// 0057d9d9  8b4804               mov ecx, dword ptr [eax + 4]
// 0057d9dc  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0057d9e0  8911                 mov dword ptr [ecx], edx
// 0057d9e2  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0057d9e6  8b4804               mov ecx, dword ptr [eax + 4]
// 0057d9e9  8b542418             mov edx, dword ptr [esp + 0x18]
// 0057d9ed  8911                 mov dword ptr [ecx], edx
// 0057d9ef  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0057d9f3  8b542420             mov edx, dword ptr [esp + 0x20]
// 0057d9f7  8b5204               mov edx, dword ptr [edx + 4]
// 0057d9fa  8b4804               mov ecx, dword ptr [eax + 4]
// 0057d9fd  895004               mov dword ptr [eax + 4], edx
// 0057da00  8b442418             mov eax, dword ptr [esp + 0x18]
// 0057da04  8b5004               mov edx, dword ptr [eax + 4]
// 0057da07  8b442420             mov eax, dword ptr [esp + 0x20]
// 0057da0b  895004               mov dword ptr [eax + 4], edx
// 0057da0e  8b542418             mov edx, dword ptr [esp + 0x18]
// 0057da12  894a04               mov dword ptr [edx + 4], ecx
// 0057da15  5e                   pop esi
// 0057da16  c22400               ret 0x24
// standard library list<ptr> (function ?_Splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@00I_N@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
