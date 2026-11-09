// from server: 100% by auto
// roc 2010-06 007b4690  unit: CXTPControlComboBoxList  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b4690
//
// 007b4690  83ec10               sub esp, 0x10
// 007b4693  56                   push esi
// 007b4694  57                   push edi
// 007b4695  8bf1                 mov esi, ecx
// 007b4697  e884f40200           call 0x7e3b20
// 007b469c  6a05                 push 5
// 007b469e  8bc8                 mov ecx, eax
// 007b46a0  e80bec0200           call 0x7e32b0
// 007b46a5  56                   push esi
// 007b46a6  8d4c240c             lea ecx, [esp + 0xc]
// 007b46aa  8bf8                 mov edi, eax
// 007b46ac  e85fac0400           call 0x7ff310
// 007b46b1  57                   push edi
// 007b46b2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007b46b6  50                   push eax
// 007b46b7  8bcf                 mov ecx, edi
// 007b46b9  e88040ffff           call 0x7a873e
// 007b46be  8b4704               mov eax, dword ptr [edi + 4]
// 007b46c1  6a00                 push 0
// 007b46c3  50                   push eax
// 007b46c4  6a0f                 push 0xf
// 007b46c6  8bce                 mov ecx, esi
// 007b46c8  e85334ffff           call 0x7a7b20
// 007b46cd  5f                   pop edi
// 007b46ce  5e                   pop esi
// 007b46cf  83c410               add esp, 0x10
// 007b46d2  c21400               ret 0x14
// library xtp-13.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?DrawCommandBar@CXTPControlComboBoxList@@MAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlComboBox.cpp
