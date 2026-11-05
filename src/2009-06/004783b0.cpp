// from server: 100% by auto
// roc 2009-06 004783b0  unit: Ogre::RbxMeshLoader  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004783b0
//
// 004783b0  56                   push esi
// 004783b1  8b742410             mov esi, dword ptr [esp + 0x10]
// 004783b5  3bce                 cmp ecx, esi
// 004783b7  740f                 je 0x4783c8
// 004783b9  57                   push edi
// 004783ba  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004783be  57                   push edi
// 004783bf  e80c991f00           call 0x671cd0
// 004783c4  297e18               sub dword ptr [esi + 0x18], edi
// 004783c7  5f                   pop edi
// 004783c8  8b442418             mov eax, dword ptr [esp + 0x18]
// 004783cc  8b4804               mov ecx, dword ptr [eax + 4]
// 004783cf  8b542420             mov edx, dword ptr [esp + 0x20]
// 004783d3  8911                 mov dword ptr [ecx], edx
// 004783d5  8b442420             mov eax, dword ptr [esp + 0x20]
// 004783d9  8b4804               mov ecx, dword ptr [eax + 4]
// 004783dc  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004783e0  8911                 mov dword ptr [ecx], edx
// 004783e2  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004783e6  8b4804               mov ecx, dword ptr [eax + 4]
// 004783e9  8b542418             mov edx, dword ptr [esp + 0x18]
// 004783ed  8911                 mov dword ptr [ecx], edx
// 004783ef  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004783f3  8b542420             mov edx, dword ptr [esp + 0x20]
// 004783f7  8b5204               mov edx, dword ptr [edx + 4]
// 004783fa  8b4804               mov ecx, dword ptr [eax + 4]
// 004783fd  895004               mov dword ptr [eax + 4], edx
// 00478400  8b442418             mov eax, dword ptr [esp + 0x18]
// 00478404  8b5004               mov edx, dword ptr [eax + 4]
// 00478407  8b442420             mov eax, dword ptr [esp + 0x20]
// 0047840b  895004               mov dword ptr [eax + 4], edx
// 0047840e  8b542418             mov edx, dword ptr [esp + 0x18]
// 00478412  894a04               mov dword ptr [edx + 4], ecx
// 00478415  5e                   pop esi
// 00478416  c22400               ret 0x24
// standard library list<ptr> (function ?_Splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@00I_N@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
