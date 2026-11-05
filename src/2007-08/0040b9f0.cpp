// from server: 100% by auto
// roc 2007-08 0040b9f0  unit: CBrowserView  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040b9f0
//
// 0040b9f0  83ec08               sub esp, 8
// 0040b9f3  53                   push ebx
// 0040b9f4  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0040b9f8  85db                 test ebx, ebx
// 0040b9fa  55                   push ebp
// 0040b9fb  56                   push esi
// 0040b9fc  8b742420             mov esi, dword ptr [esp + 0x20]
// 0040ba00  57                   push edi
// 0040ba01  8bf9                 mov edi, ecx
// 0040ba03  895c2410             mov dword ptr [esp + 0x10], ebx
// 0040ba07  7506                 jne 0x40ba0f
// 0040ba09  ff15d8e67700         call dword ptr [0x77e6d8]
// 0040ba0f  3b7304               cmp esi, dword ptr [ebx + 4]
// 0040ba12  7506                 jne 0x40ba1a
// 0040ba14  ff15d8e67700         call dword ptr [0x77e6d8]
// 0040ba1a  3b7704               cmp esi, dword ptr [edi + 4]
// 0040ba1d  8b2e                 mov ebp, dword ptr [esi]
// 0040ba1f  7425                 je 0x40ba46
// 0040ba21  8b4604               mov eax, dword ptr [esi + 4]
// 0040ba24  8bcd                 mov ecx, ebp
// 0040ba26  8908                 mov dword ptr [eax], ecx
// 0040ba28  8b16                 mov edx, dword ptr [esi]
// 0040ba2a  8b4604               mov eax, dword ptr [esi + 4]
// 0040ba2d  8d4e08               lea ecx, [esi + 8]
// 0040ba30  894204               mov dword ptr [edx + 4], eax
// 0040ba33  ff15ace67700         call dword ptr [0x77e6ac]
// 0040ba39  56                   push esi
// 0040ba3a  e823422200           call 0x62fc62
// 0040ba3f  83c404               add esp, 4
// 0040ba42  834708ff             add dword ptr [edi + 8], -1
// 0040ba46  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0040ba4a  5f                   pop edi
// 0040ba4b  5e                   pop esi
// 0040ba4c  896804               mov dword ptr [eax + 4], ebp
// 0040ba4f  5d                   pop ebp
// 0040ba50  8918                 mov dword ptr [eax], ebx
// 0040ba52  5b                   pop ebx
// 0040ba53  83c408               add esp, 8
// 0040ba56  c20c00               ret 0xc
// standard library list<string> (function ?erase@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE?AV?$_Iterator@$00@12@V312@@Z)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
