// from server: 100% by auto
// roc 2010-06 00801990  unit: CXTPPrintingDialog  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00801990
//
// 00801990  56                   push esi
// 00801991  8bf1                 mov esi, ecx
// 00801993  e84ab91700           call 0x97d2e2
// 00801998  33c0                 xor eax, eax
// 0080199a  894664               mov dword ptr [esi + 0x64], eax
// 0080199d  894668               mov dword ptr [esi + 0x68], eax
// 008019a0  894660               mov dword ptr [esi + 0x60], eax
// 008019a3  89465c               mov dword ptr [esi + 0x5c], eax
// 008019a6  c7066cffa500         mov dword ptr [esi], 0xa5ff6c
// 008019ac  8bc6                 mov eax, esi
// 008019ae  5e                   pop esi
// 008019af  c3                   ret 
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ??0CXTPPropertyGridToolBar@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
