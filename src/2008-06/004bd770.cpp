// from server: 100% by auto
// roc 2008-06 004bd770  unit: ProfiledRakPeer  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bd770
//
// 004bd770  56                   push esi
// 004bd771  8db1b4020000         lea esi, [ecx + 0x2b4]
// 004bd777  8b06                 mov eax, dword ptr [esi]
// 004bd779  3b460c               cmp eax, dword ptr [esi + 0xc]
// 004bd77c  7443                 je 0x4bd7c1
// 004bd77e  8a8020010000         mov al, byte ptr [eax + 0x120]
// 004bd784  84c0                 test al, al
// 004bd786  7439                 je 0x4bd7c1
// 004bd788  8b06                 mov eax, dword ptr [esi]
// 004bd78a  8b8824010000         mov ecx, dword ptr [eax + 0x124]
// 004bd790  890e                 mov dword ptr [esi], ecx
// 004bd792  85c0                 test eax, eax
// 004bd794  742b                 je 0x4bd7c1
// 004bd796  8b4010               mov eax, dword ptr [eax + 0x10]
// 004bd799  85c0                 test eax, eax
// 004bd79b  7409                 je 0x4bd7a6
// 004bd79d  50                   push eax
// 004bd79e  e8d72e1e00           call 0x6a067a
// 004bd7a3  83c404               add esp, 4
// 004bd7a6  8b5608               mov edx, dword ptr [esi + 8]
// 004bd7a9  ff4610               inc dword ptr [esi + 0x10]
// 004bd7ac  c6822001000000       mov byte ptr [edx + 0x120], 0
// 004bd7b3  8b4608               mov eax, dword ptr [esi + 8]
// 004bd7b6  8b8824010000         mov ecx, dword ptr [eax + 0x124]
// 004bd7bc  894e08               mov dword ptr [esi + 8], ecx
// 004bd7bf  ebb6                 jmp 0x4bd777
// 004bd7c1  8bce                 mov ecx, esi
// 004bd7c3  5e                   pop esi
// 004bd7c4  e937ebffff           jmp 0x4bc300
// library openrbx-raknet/RakPeer.cpp (function ?ClearRequestedConnectionList@RakPeer@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
