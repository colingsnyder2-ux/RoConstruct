// from server: 100% by auto
// roc 2009-12 008dd680  unit: CSpinButtonCtrl  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008dd680
//
// 008dd680  56                   push esi
// 008dd681  8bf1                 mov esi, ecx
// 008dd683  e8c06af1ff           call 0x7f4148
// 008dd688  d9ee                 fldz 
// 008dd68a  dd5658               fst qword ptr [esi + 0x58]
// 008dd68d  33c0                 xor eax, eax
// 008dd68f  dd5660               fst qword ptr [esi + 0x60]
// 008dd692  33c9                 xor ecx, ecx
// 008dd694  894670               mov dword ptr [esi + 0x70], eax
// 008dd697  dd5e68               fstp qword ptr [esi + 0x68]
// 008dd69a  c706f4b2a000         mov dword ptr [esi], 0xa0b2f4
// 008dd6a0  894e74               mov dword ptr [esi + 0x74], ecx
// 008dd6a3  c6465401             mov byte ptr [esi + 0x54], 1
// 008dd6a7  8bc6                 mov eax, esi
// 008dd6a9  5e                   pop esi
// 008dd6aa  c3                   ret 
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ??0CXTPColorBase@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
