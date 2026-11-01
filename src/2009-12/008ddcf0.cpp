// from server: 100% by auto
// roc 2009-12 008ddcf0  unit: CXTColorWnd  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ddcf0
//
// 008ddcf0  83ec14               sub esp, 0x14
// 008ddcf3  dd442418             fld qword ptr [esp + 0x18]
// 008ddcf7  56                   push esi
// 008ddcf8  8bf1                 mov esi, ecx
// 008ddcfa  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 008ddcfd  dd5e68               fstp qword ptr [esi + 0x68]
// 008ddd00  8d442408             lea eax, [esp + 8]
// 008ddd04  50                   push eax
// 008ddd05  51                   push ecx
// 008ddd06  ff1550cc9800         call dword ptr [0x98cc50]
// 008ddd0c  8b542410             mov edx, dword ptr [esp + 0x10]
// 008ddd10  2b542408             sub edx, dword ptr [esp + 8]
// 008ddd14  89542404             mov dword ptr [esp + 4], edx
// 008ddd18  db442404             fild dword ptr [esp + 4]
// 008ddd1c  dc4c241c             fmul qword ptr [esp + 0x1c]
// 008ddd20  e8cb6ff1ff           call 0x7f4cf0
// 008ddd25  6a00                 push 0
// 008ddd27  894670               mov dword ptr [esi + 0x70], eax
// 008ddd2a  8b4620               mov eax, dword ptr [esi + 0x20]
// 008ddd2d  6a00                 push 0
// 008ddd2f  50                   push eax
// 008ddd30  ff15e8cb9800         call dword ptr [0x98cbe8]
// 008ddd36  5e                   pop esi
// 008ddd37  83c414               add esp, 0x14
// 008ddd3a  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?SetHue@CXTPColorWnd@@QAEXN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
