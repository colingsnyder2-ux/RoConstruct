// from server: 100% by auto
// roc 2009-12 0057de90  unit: Ogre::RbxSceneUpdater  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057de90
//
// 0057de90  56                   push esi
// 0057de91  8b742410             mov esi, dword ptr [esp + 0x10]
// 0057de95  3bce                 cmp ecx, esi
// 0057de97  740f                 je 0x57dea8
// 0057de99  57                   push edi
// 0057de9a  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0057de9e  57                   push edi
// 0057de9f  e8acd71000           call 0x68b650
// 0057dea4  297e18               sub dword ptr [esi + 0x18], edi
// 0057dea7  5f                   pop edi
// 0057dea8  8b442418             mov eax, dword ptr [esp + 0x18]
// 0057deac  8b4804               mov ecx, dword ptr [eax + 4]
// 0057deaf  8b542420             mov edx, dword ptr [esp + 0x20]
// 0057deb3  8911                 mov dword ptr [ecx], edx
// 0057deb5  8b442420             mov eax, dword ptr [esp + 0x20]
// 0057deb9  8b4804               mov ecx, dword ptr [eax + 4]
// 0057debc  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0057dec0  8911                 mov dword ptr [ecx], edx
// 0057dec2  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0057dec6  8b4804               mov ecx, dword ptr [eax + 4]
// 0057dec9  8b542418             mov edx, dword ptr [esp + 0x18]
// 0057decd  8911                 mov dword ptr [ecx], edx
// 0057decf  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0057ded3  8b542420             mov edx, dword ptr [esp + 0x20]
// 0057ded7  8b5204               mov edx, dword ptr [edx + 4]
// 0057deda  8b4804               mov ecx, dword ptr [eax + 4]
// 0057dedd  895004               mov dword ptr [eax + 4], edx
// 0057dee0  8b442418             mov eax, dword ptr [esp + 0x18]
// 0057dee4  8b5004               mov edx, dword ptr [eax + 4]
// 0057dee7  8b442420             mov eax, dword ptr [esp + 0x20]
// 0057deeb  895004               mov dword ptr [eax + 4], edx
// 0057deee  8b542418             mov edx, dword ptr [esp + 0x18]
// 0057def2  894a04               mov dword ptr [edx + 4], ecx
// 0057def5  5e                   pop esi
// 0057def6  c22400               ret 0x24
// standard library list<ptr> (function ?_Splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@00I_N@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
