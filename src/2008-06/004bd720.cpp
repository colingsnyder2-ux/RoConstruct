// from server: 100% by auto
// roc 2008-06 004bd720  unit: ProfiledRakPeer  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bd720
//
// 004bd720  56                   push esi
// 004bd721  8db1e4060000         lea esi, [ecx + 0x6e4]
// 004bd727  8b06                 mov eax, dword ptr [esi]
// 004bd729  3b460c               cmp eax, dword ptr [esi + 0xc]
// 004bd72c  7437                 je 0x4bd765
// 004bd72e  8a4038               mov al, byte ptr [eax + 0x38]
// 004bd731  84c0                 test al, al
// 004bd733  7430                 je 0x4bd765
// 004bd735  8b06                 mov eax, dword ptr [esi]
// 004bd737  8b483c               mov ecx, dword ptr [eax + 0x3c]
// 004bd73a  890e                 mov dword ptr [esi], ecx
// 004bd73c  85c0                 test eax, eax
// 004bd73e  7425                 je 0x4bd765
// 004bd740  8b4030               mov eax, dword ptr [eax + 0x30]
// 004bd743  85c0                 test eax, eax
// 004bd745  7409                 je 0x4bd750
// 004bd747  50                   push eax
// 004bd748  e82d2f1e00           call 0x6a067a
// 004bd74d  83c404               add esp, 4
// 004bd750  8b5608               mov edx, dword ptr [esi + 8]
// 004bd753  ff4610               inc dword ptr [esi + 0x10]
// 004bd756  c6423800             mov byte ptr [edx + 0x38], 0
// 004bd75a  8b4608               mov eax, dword ptr [esi + 8]
// 004bd75d  8b483c               mov ecx, dword ptr [eax + 0x3c]
// 004bd760  894e08               mov dword ptr [esi + 8], ecx
// 004bd763  ebc2                 jmp 0x4bd727
// 004bd765  8bce                 mov ecx, esi
// 004bd767  5e                   pop esi
// 004bd768  e923edffff           jmp 0x4bc490
// library openrbx-raknet/RakPeer.cpp (function ?ClearBufferedCommands@RakPeer@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
