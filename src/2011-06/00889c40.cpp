// from server: 100% by auto
// roc 2011-06 00889c40  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00889c40
//
// 00889c40  56                   push esi
// 00889c41  8bf1                 mov esi, ecx
// 00889c43  e888f90400           call 0x8d95d0
// 00889c48  6a00                 push 0
// 00889c4a  6a04                 push 4
// 00889c4c  6a02                 push 2
// 00889c4e  6a02                 push 2
// 00889c50  8d4604               lea eax, [esi + 4]
// 00889c53  50                   push eax
// 00889c54  c7062403ad00         mov dword ptr [esi], 0xad0324
// 00889c5a  ff15c81ba400         call dword ptr [0xa41bc8]
// 00889c60  c7066c03ad00         mov dword ptr [esi], 0xad036c
// 00889c66  c7462401000000       mov dword ptr [esi + 0x24], 1
// 00889c6d  c7462800000000       mov dword ptr [esi + 0x28], 0
// 00889c74  8bc6                 mov eax, esi
// 00889c76  5e                   pop esi
// 00889c77  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ??0CAppearanceSetPropertyPageFlat@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
