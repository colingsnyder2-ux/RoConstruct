// from server: 100% by auto
// roc 2011-06 008bfbb0  unit: CXTPDockingPaneMiniWnd  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008bfbb0
//
// 008bfbb0  8bc1                 mov eax, ecx
// 008bfbb2  83b828ffffff00       cmp dword ptr [eax - 0xd8], 0
// 008bfbb9  56                   push esi
// 008bfbba  57                   push edi
// 008bfbbb  7533                 jne 0x8bfbf0
// 008bfbbd  8b781c               mov edi, dword ptr [eax + 0x1c]
// 008bfbc0  8bb008ffffff         mov esi, dword ptr [eax - 0xf8]
// 008bfbc6  8d8808ffffff         lea ecx, [eax - 0xf8]
// 008bfbcc  83c01c               add eax, 0x1c
// 008bfbcf  83ec10               sub esp, 0x10
// 008bfbd2  8bd4                 mov edx, esp
// 008bfbd4  893a                 mov dword ptr [edx], edi
// 008bfbd6  8b7804               mov edi, dword ptr [eax + 4]
// 008bfbd9  897a04               mov dword ptr [edx + 4], edi
// 008bfbdc  8b7808               mov edi, dword ptr [eax + 8]
// 008bfbdf  8b400c               mov eax, dword ptr [eax + 0xc]
// 008bfbe2  897a08               mov dword ptr [edx + 8], edi
// 008bfbe5  89420c               mov dword ptr [edx + 0xc], eax
// 008bfbe8  8b96a8010000         mov edx, dword ptr [esi + 0x1a8]
// 008bfbee  ffd2                 call edx
// 008bfbf0  5f                   pop edi
// 008bfbf1  5e                   pop esi
// 008bfbf2  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneMiniWnd.cpp (function ?CreateContainer@CXTPDockingPaneMiniWnd@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/DockingPane/XTPDockingPaneMiniWnd.cpp
