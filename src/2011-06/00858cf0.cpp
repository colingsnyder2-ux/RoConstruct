// from server: 100% by auto
// roc 2011-06 00858cf0  unit: CXTPControls  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00858cf0
//
// 00858cf0  8b442408             mov eax, dword ptr [esp + 8]
// 00858cf4  56                   push esi
// 00858cf5  57                   push edi
// 00858cf6  8bf1                 mov esi, ecx
// 00858cf8  85c0                 test eax, eax
// 00858cfa  7c05                 jl 0x858d01
// 00858cfc  3b462c               cmp eax, dword ptr [esi + 0x2c]
// 00858cff  7c03                 jl 0x858d04
// 00858d01  8b462c               mov eax, dword ptr [esi + 0x2c]
// 00858d04  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00858d08  6a01                 push 1
// 00858d0a  57                   push edi
// 00858d0b  50                   push eax
// 00858d0c  8d4e24               lea ecx, [esi + 0x24]
// 00858d0f  e83cf8ffff           call 0x858550
// 00858d14  8b06                 mov eax, dword ptr [esi]
// 00858d16  8b5068               mov edx, dword ptr [eax + 0x68]
// 00858d19  57                   push edi
// 00858d1a  8bce                 mov ecx, esi
// 00858d1c  ffd2                 call edx
// 00858d1e  8bc7                 mov eax, edi
// 00858d20  5f                   pop edi
// 00858d21  5e                   pop esi
// 00858d22  c20800               ret 8
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPControls.cpp (function ?InsertAt@CXTPControls@@QAEPAVCXTPControl@@PAV2@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPControls.cpp
