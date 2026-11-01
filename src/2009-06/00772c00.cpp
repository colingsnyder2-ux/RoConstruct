// from server: 100% by auto
// roc 2009-06 00772c00  unit: CXTPPrintingDialog  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00772c00
//
// 00772c00  56                   push esi
// 00772c01  8bf1                 mov esi, ecx
// 00772c03  e82c980d00           call 0x84c434
// 00772c08  33c0                 xor eax, eax
// 00772c0a  894664               mov dword ptr [esi + 0x64], eax
// 00772c0d  894668               mov dword ptr [esi + 0x68], eax
// 00772c10  894660               mov dword ptr [esi + 0x60], eax
// 00772c13  89465c               mov dword ptr [esi + 0x5c], eax
// 00772c16  c70604b88f00         mov dword ptr [esi], 0x8fb804
// 00772c1c  8bc6                 mov eax, esi
// 00772c1e  5e                   pop esi
// 00772c1f  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ??0CXTPPropertyGridToolBar@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
