// from server: 100% by auto
// roc 2009-12 008ddd40  unit: CXTColorWnd  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ddd40
//
// 008ddd40  83ec14               sub esp, 0x14
// 008ddd43  dd442418             fld qword ptr [esp + 0x18]
// 008ddd47  53                   push ebx
// 008ddd48  56                   push esi
// 008ddd49  57                   push edi
// 008ddd4a  8bf1                 mov esi, ecx
// 008ddd4c  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 008ddd4f  dd5e60               fstp qword ptr [esi + 0x60]
// 008ddd52  8d442410             lea eax, [esp + 0x10]
// 008ddd56  50                   push eax
// 008ddd57  51                   push ecx
// 008ddd58  ff1550cc9800         call dword ptr [0x98cc50]
// 008ddd5e  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 008ddd62  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 008ddd66  8bd7                 mov edx, edi
// 008ddd68  2bd3                 sub edx, ebx
// 008ddd6a  8954240c             mov dword ptr [esp + 0xc], edx
// 008ddd6e  db44240c             fild dword ptr [esp + 0xc]
// 008ddd72  dc4c2424             fmul qword ptr [esp + 0x24]
// 008ddd76  e8756ff1ff           call 0x7f4cf0
// 008ddd7b  6a00                 push 0
// 008ddd7d  2bf8                 sub edi, eax
// 008ddd7f  8b4620               mov eax, dword ptr [esi + 0x20]
// 008ddd82  6a00                 push 0
// 008ddd84  2bfb                 sub edi, ebx
// 008ddd86  50                   push eax
// 008ddd87  897e74               mov dword ptr [esi + 0x74], edi
// 008ddd8a  ff15e8cb9800         call dword ptr [0x98cbe8]
// 008ddd90  5f                   pop edi
// 008ddd91  5e                   pop esi
// 008ddd92  5b                   pop ebx
// 008ddd93  83c414               add esp, 0x14
// 008ddd96  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?SetSaturation@CXTPColorWnd@@QAEXN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
