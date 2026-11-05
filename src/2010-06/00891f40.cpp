// from server: 100% by auto
// roc 2010-06 00891f40  unit: CXTColorWnd  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00891f40
//
// 00891f40  83ec14               sub esp, 0x14
// 00891f43  dd442418             fld qword ptr [esp + 0x18]
// 00891f47  56                   push esi
// 00891f48  8bf1                 mov esi, ecx
// 00891f4a  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00891f4d  dd5e68               fstp qword ptr [esi + 0x68]
// 00891f50  8d442408             lea eax, [esp + 8]
// 00891f54  50                   push eax
// 00891f55  51                   push ecx
// 00891f56  ff155cbc9e00         call dword ptr [0x9ebc5c]
// 00891f5c  8b542410             mov edx, dword ptr [esp + 0x10]
// 00891f60  2b542408             sub edx, dword ptr [esp + 8]
// 00891f64  89542404             mov dword ptr [esp + 4], edx
// 00891f68  db442404             fild dword ptr [esp + 4]
// 00891f6c  dc4c241c             fmul qword ptr [esp + 0x1c]
// 00891f70  e8bb6ef1ff           call 0x7a8e30
// 00891f75  6a00                 push 0
// 00891f77  894670               mov dword ptr [esi + 0x70], eax
// 00891f7a  8b4620               mov eax, dword ptr [esi + 0x20]
// 00891f7d  6a00                 push 0
// 00891f7f  50                   push eax
// 00891f80  ff1578ba9e00         call dword ptr [0x9eba78]
// 00891f86  5e                   pop esi
// 00891f87  83c414               add esp, 0x14
// 00891f8a  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTColorPageCustom.cpp (function ?SetHue@CXTColorWnd@@QAEXN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageCustom.cpp
