// from server: 100% by auto
// roc 2010-06 007fb300  unit: CXTPControls  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007fb300
//
// 007fb300  8b442408             mov eax, dword ptr [esp + 8]
// 007fb304  56                   push esi
// 007fb305  57                   push edi
// 007fb306  8bf1                 mov esi, ecx
// 007fb308  85c0                 test eax, eax
// 007fb30a  7c05                 jl 0x7fb311
// 007fb30c  3b462c               cmp eax, dword ptr [esi + 0x2c]
// 007fb30f  7c03                 jl 0x7fb314
// 007fb311  8b462c               mov eax, dword ptr [esi + 0x2c]
// 007fb314  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007fb318  6a01                 push 1
// 007fb31a  57                   push edi
// 007fb31b  50                   push eax
// 007fb31c  8d4e24               lea ecx, [esi + 0x24]
// 007fb31f  e89c06fbff           call 0x7ab9c0
// 007fb324  8b06                 mov eax, dword ptr [esi]
// 007fb326  8b5068               mov edx, dword ptr [eax + 0x68]
// 007fb329  57                   push edi
// 007fb32a  8bce                 mov ecx, esi
// 007fb32c  ffd2                 call edx
// 007fb32e  8bc7                 mov eax, edi
// 007fb330  5f                   pop edi
// 007fb331  5e                   pop esi
// 007fb332  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPControls.cpp (function ?InsertAt@CXTPControls@@QAEPAVCXTPControl@@PAV2@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPControls.cpp
