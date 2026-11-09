// from server: 100% by auto
// roc 2009-12 00425780  unit: MainLogManager  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00425780
//
// 00425780  56                   push esi
// 00425781  8b742410             mov esi, dword ptr [esp + 0x10]
// 00425785  3bce                 cmp ecx, esi
// 00425787  740f                 je 0x425798
// 00425789  57                   push edi
// 0042578a  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0042578e  57                   push edi
// 0042578f  e83cecffff           call 0x4243d0
// 00425794  297e18               sub dword ptr [esi + 0x18], edi
// 00425797  5f                   pop edi
// 00425798  8b442418             mov eax, dword ptr [esp + 0x18]
// 0042579c  8b4804               mov ecx, dword ptr [eax + 4]
// 0042579f  8b542420             mov edx, dword ptr [esp + 0x20]
// 004257a3  8911                 mov dword ptr [ecx], edx
// 004257a5  8b442420             mov eax, dword ptr [esp + 0x20]
// 004257a9  8b4804               mov ecx, dword ptr [eax + 4]
// 004257ac  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004257b0  8911                 mov dword ptr [ecx], edx
// 004257b2  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004257b6  8b4804               mov ecx, dword ptr [eax + 4]
// 004257b9  8b542418             mov edx, dword ptr [esp + 0x18]
// 004257bd  8911                 mov dword ptr [ecx], edx
// 004257bf  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004257c3  8b542420             mov edx, dword ptr [esp + 0x20]
// 004257c7  8b5204               mov edx, dword ptr [edx + 4]
// 004257ca  8b4804               mov ecx, dword ptr [eax + 4]
// 004257cd  895004               mov dword ptr [eax + 4], edx
// 004257d0  8b442418             mov eax, dword ptr [esp + 0x18]
// 004257d4  8b5004               mov edx, dword ptr [eax + 4]
// 004257d7  8b442420             mov eax, dword ptr [esp + 0x20]
// 004257db  895004               mov dword ptr [eax + 4], edx
// 004257de  8b542418             mov edx, dword ptr [esp + 0x18]
// 004257e2  894a04               mov dword ptr [edx + 4], ecx
// 004257e5  5e                   pop esi
// 004257e6  c22400               ret 0x24
// standard library list<ptr> (function ?_Splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@00I_N@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
