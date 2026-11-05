// from server: 100% by auto
// roc 2007-03 005462d0  unit: seg_00540000  size: 211 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005462d0
//
// 005462d0  53                   push ebx
// 005462d1  55                   push ebp
// 005462d2  56                   push esi
// 005462d3  57                   push edi
// 005462d4  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005462d8  85ff                 test edi, edi
// 005462da  8bd9                 mov ebx, ecx
// 005462dc  8b4304               mov eax, dword ptr [ebx + 4]
// 005462df  8b28                 mov ebp, dword ptr [eax]
// 005462e1  7404                 je 0x5462e7
// 005462e3  3bfb                 cmp edi, ebx
// 005462e5  7406                 je 0x5462ed
// 005462e7  ff1544e97700         call dword ptr [0x77e944]
// 005462ed  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 005462f1  3bf5                 cmp esi, ebp
// 005462f3  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 005462f7  7539                 jne 0x546332
// 005462f9  85ed                 test ebp, ebp
// 005462fb  8b4b04               mov ecx, dword ptr [ebx + 4]
// 005462fe  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00546302  7404                 je 0x546308
// 00546304  3beb                 cmp ebp, ebx
// 00546306  7406                 je 0x54630e
// 00546308  ff1544e97700         call dword ptr [0x77e944]
// 0054630e  8b542424             mov edx, dword ptr [esp + 0x24]
// 00546312  3b54241c             cmp edx, dword ptr [esp + 0x1c]
// 00546316  751a                 jne 0x546332
// 00546318  8bcb                 mov ecx, ebx
// 0054631a  e831fcffff           call 0x545f50
// 0054631f  8b442414             mov eax, dword ptr [esp + 0x14]
// 00546323  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00546326  5f                   pop edi
// 00546327  5e                   pop esi
// 00546328  5d                   pop ebp
// 00546329  8918                 mov dword ptr [eax], ebx
// 0054632b  894804               mov dword ptr [eax + 4], ecx
// 0054632e  5b                   pop ebx
// 0054632f  c21400               ret 0x14
// 00546332  85ff                 test edi, edi
// 00546334  7404                 je 0x54633a
// 00546336  3bfd                 cmp edi, ebp
// 00546338  7406                 je 0x546340
// 0054633a  ff1544e97700         call dword ptr [0x77e944]
// 00546340  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00546344  3bf1                 cmp esi, ecx
// 00546346  744b                 je 0x546393
// 00546348  85ff                 test edi, edi
// 0054634a  8974241c             mov dword ptr [esp + 0x1c], esi
// 0054634e  7506                 jne 0x546356
// 00546350  ff1544e97700         call dword ptr [0x77e944]
// 00546356  3b7704               cmp esi, dword ptr [edi + 4]
// 00546359  7506                 jne 0x546361
// 0054635b  ff1544e97700         call dword ptr [0x77e944]
// 00546361  3b7304               cmp esi, dword ptr [ebx + 4]
// 00546364  8b2e                 mov ebp, dword ptr [esi]
// 00546366  7423                 je 0x54638b
// 00546368  8b5604               mov edx, dword ptr [esi + 4]
// 0054636b  892a                 mov dword ptr [edx], ebp
// 0054636d  8b4e04               mov ecx, dword ptr [esi + 4]
// 00546370  8b06                 mov eax, dword ptr [esi]
// 00546372  894804               mov dword ptr [eax + 4], ecx
// 00546375  8d4e08               lea ecx, [esi + 8]
// 00546378  ff158ce77700         call dword ptr [0x77e78c]
// 0054637e  56                   push esi
// 0054637f  e86c7d0d00           call 0x61e0f0
// 00546384  83c404               add esp, 4
// 00546387  834308ff             add dword ptr [ebx + 8], -1
// 0054638b  8bf5                 mov esi, ebp
// 0054638d  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00546391  eb9f                 jmp 0x546332
// 00546393  8b442414             mov eax, dword ptr [esp + 0x14]
// 00546397  5f                   pop edi
// 00546398  5e                   pop esi
// 00546399  8928                 mov dword ptr [eax], ebp
// 0054639b  5d                   pop ebp
// 0054639c  894804               mov dword ptr [eax + 4], ecx
// 0054639f  5b                   pop ebx
// 005463a0  c21400               ret 0x14
// standard library list<string> (function ?erase@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE?AV?$_Iterator@$00@12@V312@0@Z)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
