// from server: 100% by auto
// roc 2007-08 00546a60  unit: RBX::MD5HasherImpl  size: 211 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00546a60
//
// 00546a60  53                   push ebx
// 00546a61  55                   push ebp
// 00546a62  56                   push esi
// 00546a63  57                   push edi
// 00546a64  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00546a68  85ff                 test edi, edi
// 00546a6a  8bd9                 mov ebx, ecx
// 00546a6c  8b4304               mov eax, dword ptr [ebx + 4]
// 00546a6f  8b28                 mov ebp, dword ptr [eax]
// 00546a71  7404                 je 0x546a77
// 00546a73  3bfb                 cmp edi, ebx
// 00546a75  7406                 je 0x546a7d
// 00546a77  ff15d8e67700         call dword ptr [0x77e6d8]
// 00546a7d  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00546a81  3bf5                 cmp esi, ebp
// 00546a83  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00546a87  7539                 jne 0x546ac2
// 00546a89  85ed                 test ebp, ebp
// 00546a8b  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00546a8e  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00546a92  7404                 je 0x546a98
// 00546a94  3beb                 cmp ebp, ebx
// 00546a96  7406                 je 0x546a9e
// 00546a98  ff15d8e67700         call dword ptr [0x77e6d8]
// 00546a9e  8b542424             mov edx, dword ptr [esp + 0x24]
// 00546aa2  3b54241c             cmp edx, dword ptr [esp + 0x1c]
// 00546aa6  751a                 jne 0x546ac2
// 00546aa8  8bcb                 mov ecx, ebx
// 00546aaa  e801fbffff           call 0x5465b0
// 00546aaf  8b442414             mov eax, dword ptr [esp + 0x14]
// 00546ab3  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00546ab6  5f                   pop edi
// 00546ab7  5e                   pop esi
// 00546ab8  5d                   pop ebp
// 00546ab9  8918                 mov dword ptr [eax], ebx
// 00546abb  894804               mov dword ptr [eax + 4], ecx
// 00546abe  5b                   pop ebx
// 00546abf  c21400               ret 0x14
// 00546ac2  85ff                 test edi, edi
// 00546ac4  7404                 je 0x546aca
// 00546ac6  3bfd                 cmp edi, ebp
// 00546ac8  7406                 je 0x546ad0
// 00546aca  ff15d8e67700         call dword ptr [0x77e6d8]
// 00546ad0  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00546ad4  3bf1                 cmp esi, ecx
// 00546ad6  744b                 je 0x546b23
// 00546ad8  85ff                 test edi, edi
// 00546ada  8974241c             mov dword ptr [esp + 0x1c], esi
// 00546ade  7506                 jne 0x546ae6
// 00546ae0  ff15d8e67700         call dword ptr [0x77e6d8]
// 00546ae6  3b7704               cmp esi, dword ptr [edi + 4]
// 00546ae9  7506                 jne 0x546af1
// 00546aeb  ff15d8e67700         call dword ptr [0x77e6d8]
// 00546af1  3b7304               cmp esi, dword ptr [ebx + 4]
// 00546af4  8b2e                 mov ebp, dword ptr [esi]
// 00546af6  7423                 je 0x546b1b
// 00546af8  8b5604               mov edx, dword ptr [esi + 4]
// 00546afb  892a                 mov dword ptr [edx], ebp
// 00546afd  8b4e04               mov ecx, dword ptr [esi + 4]
// 00546b00  8b06                 mov eax, dword ptr [esi]
// 00546b02  894804               mov dword ptr [eax + 4], ecx
// 00546b05  8d4e08               lea ecx, [esi + 8]
// 00546b08  ff15ace67700         call dword ptr [0x77e6ac]
// 00546b0e  56                   push esi
// 00546b0f  e84e910e00           call 0x62fc62
// 00546b14  83c404               add esp, 4
// 00546b17  834308ff             add dword ptr [ebx + 8], -1
// 00546b1b  8bf5                 mov esi, ebp
// 00546b1d  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00546b21  eb9f                 jmp 0x546ac2
// 00546b23  8b442414             mov eax, dword ptr [esp + 0x14]
// 00546b27  5f                   pop edi
// 00546b28  5e                   pop esi
// 00546b29  8928                 mov dword ptr [eax], ebp
// 00546b2b  5d                   pop ebp
// 00546b2c  894804               mov dword ptr [eax + 4], ecx
// 00546b2f  5b                   pop ebx
// 00546b30  c21400               ret 0x14
// standard library list<string> (function ?erase@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE?AV?$_Iterator@$00@12@V312@0@Z)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
