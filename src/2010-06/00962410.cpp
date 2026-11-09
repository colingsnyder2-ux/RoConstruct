// from server: 100% by auto
// roc 2010-06 00962410  unit: RBX::SceneUpdater  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00962410
//
// 00962410  56                   push esi
// 00962411  8b742410             mov esi, dword ptr [esp + 0x10]
// 00962415  3bce                 cmp ecx, esi
// 00962417  740f                 je 0x962428
// 00962419  57                   push edi
// 0096241a  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0096241e  57                   push edi
// 0096241f  e88cecffff           call 0x9610b0
// 00962424  297e18               sub dword ptr [esi + 0x18], edi
// 00962427  5f                   pop edi
// 00962428  8b442418             mov eax, dword ptr [esp + 0x18]
// 0096242c  8b4804               mov ecx, dword ptr [eax + 4]
// 0096242f  8b542420             mov edx, dword ptr [esp + 0x20]
// 00962433  8911                 mov dword ptr [ecx], edx
// 00962435  8b442420             mov eax, dword ptr [esp + 0x20]
// 00962439  8b4804               mov ecx, dword ptr [eax + 4]
// 0096243c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00962440  8911                 mov dword ptr [ecx], edx
// 00962442  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00962446  8b4804               mov ecx, dword ptr [eax + 4]
// 00962449  8b542418             mov edx, dword ptr [esp + 0x18]
// 0096244d  8911                 mov dword ptr [ecx], edx
// 0096244f  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00962453  8b542420             mov edx, dword ptr [esp + 0x20]
// 00962457  8b5204               mov edx, dword ptr [edx + 4]
// 0096245a  8b4804               mov ecx, dword ptr [eax + 4]
// 0096245d  895004               mov dword ptr [eax + 4], edx
// 00962460  8b442418             mov eax, dword ptr [esp + 0x18]
// 00962464  8b5004               mov edx, dword ptr [eax + 4]
// 00962467  8b442420             mov eax, dword ptr [esp + 0x20]
// 0096246b  895004               mov dword ptr [eax + 4], edx
// 0096246e  8b542418             mov edx, dword ptr [esp + 0x18]
// 00962472  894a04               mov dword ptr [edx + 4], ecx
// 00962475  5e                   pop esi
// 00962476  c22400               ret 0x24
// standard library list<ptr> (function ?_Splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@00I_N@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
