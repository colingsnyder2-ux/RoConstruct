// from server: 100% by auto
// roc 2010-06 00891f90  unit: CXTColorWnd  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00891f90
//
// 00891f90  83ec14               sub esp, 0x14
// 00891f93  dd442418             fld qword ptr [esp + 0x18]
// 00891f97  53                   push ebx
// 00891f98  56                   push esi
// 00891f99  57                   push edi
// 00891f9a  8bf1                 mov esi, ecx
// 00891f9c  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00891f9f  dd5e60               fstp qword ptr [esi + 0x60]
// 00891fa2  8d442410             lea eax, [esp + 0x10]
// 00891fa6  50                   push eax
// 00891fa7  51                   push ecx
// 00891fa8  ff155cbc9e00         call dword ptr [0x9ebc5c]
// 00891fae  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00891fb2  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00891fb6  8bd7                 mov edx, edi
// 00891fb8  2bd3                 sub edx, ebx
// 00891fba  8954240c             mov dword ptr [esp + 0xc], edx
// 00891fbe  db44240c             fild dword ptr [esp + 0xc]
// 00891fc2  dc4c2424             fmul qword ptr [esp + 0x24]
// 00891fc6  e8656ef1ff           call 0x7a8e30
// 00891fcb  6a00                 push 0
// 00891fcd  2bf8                 sub edi, eax
// 00891fcf  8b4620               mov eax, dword ptr [esi + 0x20]
// 00891fd2  6a00                 push 0
// 00891fd4  2bfb                 sub edi, ebx
// 00891fd6  50                   push eax
// 00891fd7  897e74               mov dword ptr [esi + 0x74], edi
// 00891fda  ff1578ba9e00         call dword ptr [0x9eba78]
// 00891fe0  5f                   pop edi
// 00891fe1  5e                   pop esi
// 00891fe2  5b                   pop ebx
// 00891fe3  83c414               add esp, 0x14
// 00891fe6  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTColorPageCustom.cpp (function ?SetSaturation@CXTColorWnd@@QAEXN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageCustom.cpp
