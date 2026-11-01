// from server: 100% by auto
// roc 2009-06 00802b90  unit: CSpinButtonCtrl  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00802b90
//
// 00802b90  56                   push esi
// 00802b91  8bf1                 mov esi, ecx
// 00802b93  e88867f1ff           call 0x719320
// 00802b98  d9ee                 fldz 
// 00802b9a  dd5658               fst qword ptr [esi + 0x58]
// 00802b9d  33c0                 xor eax, eax
// 00802b9f  dd5660               fst qword ptr [esi + 0x60]
// 00802ba2  33c9                 xor ecx, ecx
// 00802ba4  894670               mov dword ptr [esi + 0x70], eax
// 00802ba7  dd5e68               fstp qword ptr [esi + 0x68]
// 00802baa  c70684ae9000         mov dword ptr [esi], 0x90ae84
// 00802bb0  894e74               mov dword ptr [esi + 0x74], ecx
// 00802bb3  c6465401             mov byte ptr [esi + 0x54], 1
// 00802bb7  8bc6                 mov eax, esi
// 00802bb9  5e                   pop esi
// 00802bba  c3                   ret 
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ??0CXTPColorBase@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
