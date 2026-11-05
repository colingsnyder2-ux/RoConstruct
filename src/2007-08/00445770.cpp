// from server: 100% by auto
// roc 2007-08 00445770  unit: VCRenderSettings::?$FactoryProduct  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00445770
//
// 00445770  55                   push ebp
// 00445771  56                   push esi
// 00445772  8b742410             mov esi, dword ptr [esp + 0x10]
// 00445776  85f6                 test esi, esi
// 00445778  8be9                 mov ebp, ecx
// 0044577a  7406                 je 0x445782
// 0044577c  3b742418             cmp esi, dword ptr [esp + 0x18]
// 00445780  7406                 je 0x445788
// 00445782  ff15d8e67700         call dword ptr [0x77e6d8]
// 00445788  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0044578c  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00445790  3bca                 cmp ecx, edx
// 00445792  744b                 je 0x4457df
// 00445794  8b4508               mov eax, dword ptr [ebp + 8]
// 00445797  53                   push ebx
// 00445798  57                   push edi
// 00445799  c644242000           mov byte ptr [esp + 0x20], 0
// 0044579e  8b742420             mov esi, dword ptr [esp + 0x20]
// 004457a2  56                   push esi
// 004457a3  8b742418             mov esi, dword ptr [esp + 0x18]
// 004457a7  56                   push esi
// 004457a8  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004457ac  56                   push esi
// 004457ad  51                   push ecx
// 004457ae  50                   push eax
// 004457af  52                   push edx
// 004457b0  e80bf8ffff           call 0x444fc0
// 004457b5  8b5d08               mov ebx, dword ptr [ebp + 8]
// 004457b8  8bf8                 mov edi, eax
// 004457ba  83c418               add esp, 0x18
// 004457bd  3bfb                 cmp edi, ebx
// 004457bf  8bf7                 mov esi, edi
// 004457c1  740f                 je 0x4457d2
// 004457c3  8bce                 mov ecx, esi
// 004457c5  ff15ace67700         call dword ptr [0x77e6ac]
// 004457cb  83c61c               add esi, 0x1c
// 004457ce  3bf3                 cmp esi, ebx
// 004457d0  75f1                 jne 0x4457c3
// 004457d2  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004457d6  8b742418             mov esi, dword ptr [esp + 0x18]
// 004457da  897d08               mov dword ptr [ebp + 8], edi
// 004457dd  5f                   pop edi
// 004457de  5b                   pop ebx
// 004457df  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004457e3  8930                 mov dword ptr [eax], esi
// 004457e5  5e                   pop esi
// 004457e6  894804               mov dword ptr [eax + 4], ecx
// 004457e9  5d                   pop ebp
// 004457ea  c21400               ret 0x14
// standard library vector<string> (function ?erase@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE?AV?$_Vector_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@V32@0@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
