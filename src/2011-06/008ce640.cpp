// from server: 100% by auto
// roc 2011-06 008ce640  unit: CXTPDockingPaneContext  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008ce640
//
// 008ce640  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008ce644  8b01                 mov eax, dword ptr [ecx]
// 008ce646  8b5018               mov edx, dword ptr [eax + 0x18]
// 008ce649  56                   push esi
// 008ce64a  ffd2                 call edx
// 008ce64c  8bf0                 mov esi, eax
// 008ce64e  85f6                 test esi, esi
// 008ce650  747e                 je 0x8ce6d0
// 008ce652  e88913ffff           call 0x8bf9e0
// 008ce657  50                   push eax
// 008ce658  8bce                 mov ecx, esi
// 008ce65a  e887bff3ff           call 0x80a5e6
// 008ce65f  85c0                 test eax, eax
// 008ce661  746d                 je 0x8ce6d0
// 008ce663  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008ce667  8b01                 mov eax, dword ptr [ecx]
// 008ce669  8b5018               mov edx, dword ptr [eax + 0x18]
// 008ce66c  53                   push ebx
// 008ce66d  ffd2                 call edx
// 008ce66f  8bd8                 mov ebx, eax
// 008ce671  85db                 test ebx, ebx
// 008ce673  7454                 je 0x8ce6c9
// 008ce675  e86613ffff           call 0x8bf9e0
// 008ce67a  50                   push eax
// 008ce67b  8bcb                 mov ecx, ebx
// 008ce67d  e864bff3ff           call 0x80a5e6
// 008ce682  85c0                 test eax, eax
// 008ce684  7443                 je 0x8ce6c9
// 008ce686  8b4620               mov eax, dword ptr [esi + 0x20]
// 008ce689  57                   push edi
// 008ce68a  8b3d581ba400         mov edi, dword ptr [0xa41b58]
// 008ce690  6a02                 push 2
// 008ce692  50                   push eax
// 008ce693  ffd7                 call edi
// 008ce695  8bf0                 mov esi, eax
// 008ce697  85f6                 test esi, esi
// 008ce699  741b                 je 0x8ce6b6
// 008ce69b  eb03                 jmp 0x8ce6a0
// 008ce69d  8d4900               lea ecx, [ecx]
// 008ce6a0  8bcb                 mov ecx, ebx
// 008ce6a2  e8e93bb4ff           call 0x412290
// 008ce6a7  3bf0                 cmp esi, eax
// 008ce6a9  7416                 je 0x8ce6c1
// 008ce6ab  6a02                 push 2
// 008ce6ad  56                   push esi
// 008ce6ae  ffd7                 call edi
// 008ce6b0  8bf0                 mov esi, eax
// 008ce6b2  85f6                 test esi, esi
// 008ce6b4  75ea                 jne 0x8ce6a0
// 008ce6b6  5f                   pop edi
// 008ce6b7  5b                   pop ebx
// 008ce6b8  b801000000           mov eax, 1
// 008ce6bd  5e                   pop esi
// 008ce6be  c20800               ret 8
// 008ce6c1  5f                   pop edi
// 008ce6c2  5b                   pop ebx
// 008ce6c3  33c0                 xor eax, eax
// 008ce6c5  5e                   pop esi
// 008ce6c6  c20800               ret 8
// 008ce6c9  5b                   pop ebx
// 008ce6ca  33c0                 xor eax, eax
// 008ce6cc  5e                   pop esi
// 008ce6cd  c20800               ret 8
// 008ce6d0  b801000000           mov eax, 1
// 008ce6d5  5e                   pop esi
// 008ce6d6  c20800               ret 8
// library xtp-15.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneContext.cpp (function ?IsBehind@CXTPDockingPaneContext@@IAEHPAVCXTPDockingPaneBase@@0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/DockingPane/XTPDockingPaneContext.cpp
