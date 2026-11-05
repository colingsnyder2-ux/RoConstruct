// from server: 100% by auto
// roc 2010-06 0064cb90  unit: RBX::VWidget::?$NonFactoryProduct  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0064cb90
//
// 0064cb90  56                   push esi
// 0064cb91  8b742410             mov esi, dword ptr [esp + 0x10]
// 0064cb95  3bce                 cmp ecx, esi
// 0064cb97  740f                 je 0x64cba8
// 0064cb99  57                   push edi
// 0064cb9a  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0064cb9e  57                   push edi
// 0064cb9f  e84cf3ffff           call 0x64bef0
// 0064cba4  297e18               sub dword ptr [esi + 0x18], edi
// 0064cba7  5f                   pop edi
// 0064cba8  8b442418             mov eax, dword ptr [esp + 0x18]
// 0064cbac  8b4804               mov ecx, dword ptr [eax + 4]
// 0064cbaf  8b542420             mov edx, dword ptr [esp + 0x20]
// 0064cbb3  8911                 mov dword ptr [ecx], edx
// 0064cbb5  8b442420             mov eax, dword ptr [esp + 0x20]
// 0064cbb9  8b4804               mov ecx, dword ptr [eax + 4]
// 0064cbbc  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0064cbc0  8911                 mov dword ptr [ecx], edx
// 0064cbc2  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0064cbc6  8b4804               mov ecx, dword ptr [eax + 4]
// 0064cbc9  8b542418             mov edx, dword ptr [esp + 0x18]
// 0064cbcd  8911                 mov dword ptr [ecx], edx
// 0064cbcf  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0064cbd3  8b542420             mov edx, dword ptr [esp + 0x20]
// 0064cbd7  8b5204               mov edx, dword ptr [edx + 4]
// 0064cbda  8b4804               mov ecx, dword ptr [eax + 4]
// 0064cbdd  895004               mov dword ptr [eax + 4], edx
// 0064cbe0  8b442418             mov eax, dword ptr [esp + 0x18]
// 0064cbe4  8b5004               mov edx, dword ptr [eax + 4]
// 0064cbe7  8b442420             mov eax, dword ptr [esp + 0x20]
// 0064cbeb  895004               mov dword ptr [eax + 4], edx
// 0064cbee  8b542418             mov edx, dword ptr [esp + 0x18]
// 0064cbf2  894a04               mov dword ptr [edx + 4], ecx
// 0064cbf5  5e                   pop esi
// 0064cbf6  c22400               ret 0x24
// standard library list<ptr> (function ?_Splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@00I_N@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
