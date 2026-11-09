// from server: 100% by auto
// roc 2010-06 008918d0  unit: CSpinButtonCtrl  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008918d0
//
// 008918d0  56                   push esi
// 008918d1  8bf1                 mov esi, ecx
// 008918d3  e8b069f1ff           call 0x7a8288
// 008918d8  d9ee                 fldz 
// 008918da  dd5658               fst qword ptr [esi + 0x58]
// 008918dd  33c0                 xor eax, eax
// 008918df  dd5660               fst qword ptr [esi + 0x60]
// 008918e2  33c9                 xor ecx, ecx
// 008918e4  894670               mov dword ptr [esi + 0x70], eax
// 008918e7  dd5e68               fstp qword ptr [esi + 0x68]
// 008918ea  c706ecf5a600         mov dword ptr [esi], 0xa6f5ec
// 008918f0  894e74               mov dword ptr [esi + 0x74], ecx
// 008918f3  c6465401             mov byte ptr [esi + 0x54], 1
// 008918f7  8bc6                 mov eax, esi
// 008918f9  5e                   pop esi
// 008918fa  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTColorPageCustom.cpp (function ??0CXTColorBase@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageCustom.cpp
