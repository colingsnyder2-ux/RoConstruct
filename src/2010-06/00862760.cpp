// from server: 100% by auto
// roc 2010-06 00862760  unit: CXTPDockingPaneMiniWnd  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00862760
//
// 00862760  8bc1                 mov eax, ecx
// 00862762  83b828ffffff00       cmp dword ptr [eax - 0xd8], 0
// 00862769  56                   push esi
// 0086276a  57                   push edi
// 0086276b  7533                 jne 0x8627a0
// 0086276d  8b781c               mov edi, dword ptr [eax + 0x1c]
// 00862770  8bb008ffffff         mov esi, dword ptr [eax - 0xf8]
// 00862776  8d8808ffffff         lea ecx, [eax - 0xf8]
// 0086277c  83c01c               add eax, 0x1c
// 0086277f  83ec10               sub esp, 0x10
// 00862782  8bd4                 mov edx, esp
// 00862784  893a                 mov dword ptr [edx], edi
// 00862786  8b7804               mov edi, dword ptr [eax + 4]
// 00862789  897a04               mov dword ptr [edx + 4], edi
// 0086278c  8b7808               mov edi, dword ptr [eax + 8]
// 0086278f  8b400c               mov eax, dword ptr [eax + 0xc]
// 00862792  897a08               mov dword ptr [edx + 8], edi
// 00862795  89420c               mov dword ptr [edx + 0xc], eax
// 00862798  8b96a8010000         mov edx, dword ptr [esi + 0x1a8]
// 0086279e  ffd2                 call edx
// 008627a0  5f                   pop edi
// 008627a1  5e                   pop esi
// 008627a2  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneMiniWnd.cpp (function ?CreateContainer@CXTPDockingPaneMiniWnd@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/DockingPane/XTPDockingPaneMiniWnd.cpp
