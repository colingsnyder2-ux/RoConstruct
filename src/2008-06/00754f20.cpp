// from server: 100% by auto
// roc 2008-06 00754f20  unit: CXTPDockingPaneBase  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00754f20
//
// 00754f20  8b5104               mov edx, dword ptr [ecx + 4]
// 00754f23  85d2                 test edx, edx
// 00754f25  7505                 jne 0x754f2c
// 00754f27  e818baf4ff           call 0x6a0944
// 00754f2c  8b02                 mov eax, dword ptr [edx]
// 00754f2e  56                   push esi
// 00754f2f  8b7208               mov esi, dword ptr [edx + 8]
// 00754f32  894104               mov dword ptr [ecx + 4], eax
// 00754f35  85c0                 test eax, eax
// 00754f37  7411                 je 0x754f4a
// 00754f39  52                   push edx
// 00754f3a  c7400400000000       mov dword ptr [eax + 4], 0
// 00754f41  e82aba0000           call 0x760970
// 00754f46  8bc6                 mov eax, esi
// 00754f48  5e                   pop esi
// 00754f49  c3                   ret 
// 00754f4a  52                   push edx
// 00754f4b  c7410800000000       mov dword ptr [ecx + 8], 0
// 00754f52  e819ba0000           call 0x760970
// 00754f57  8bc6                 mov eax, esi
// 00754f59  5e                   pop esi
// 00754f5a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?RemoveHead@?$CList@PAVCMFCPropertyGridProperty@@PAV1@@@QAEPAVCMFCPropertyGridProperty@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
