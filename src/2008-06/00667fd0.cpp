// from server: 100% by auto
// roc 2008-06 00667fd0  unit: RBX::HUMAN::GettingUp  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00667fd0
//
// 00667fd0  8b5118               mov edx, dword ptr [ecx + 0x18]
// 00667fd3  8b4204               mov eax, dword ptr [edx + 4]
// 00667fd6  80781500             cmp byte ptr [eax + 0x15], 0
// 00667fda  751c                 jne 0x667ff8
// 00667fdc  56                   push esi
// 00667fdd  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00667fe1  8b36                 mov esi, dword ptr [esi]
// 00667fe3  39700c               cmp dword ptr [eax + 0xc], esi
// 00667fe6  7305                 jae 0x667fed
// 00667fe8  8b4008               mov eax, dword ptr [eax + 8]
// 00667feb  eb04                 jmp 0x667ff1
// 00667fed  8bd0                 mov edx, eax
// 00667fef  8b00                 mov eax, dword ptr [eax]
// 00667ff1  80781500             cmp byte ptr [eax + 0x15], 0
// 00667ff5  74ec                 je 0x667fe3
// 00667ff7  5e                   pop esi
// 00667ff8  8b442404             mov eax, dword ptr [esp + 4]
// 00667ffc  8b09                 mov ecx, dword ptr [ecx]
// 00667ffe  895004               mov dword ptr [eax + 4], edx
// 00668001  8908                 mov dword ptr [eax], ecx
// 00668003  c20800               ret 8
// standard library map_ptr<ptr> (function ?lower_bound@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@ABQAUK@@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
