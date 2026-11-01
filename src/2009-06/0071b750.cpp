// from server: 100% by auto
// roc 2009-06 0071b750  unit: CXTPControlComboBoxList  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071b750
//
// 0071b750  83ec10               sub esp, 0x10
// 0071b753  56                   push esi
// 0071b754  57                   push edi
// 0071b755  8bf1                 mov esi, ecx
// 0071b757  e8c4930300           call 0x754b20
// 0071b75c  6a05                 push 5
// 0071b75e  8bc8                 mov ecx, eax
// 0071b760  e83b8b0300           call 0x7542a0
// 0071b765  56                   push esi
// 0071b766  8d4c240c             lea ecx, [esp + 0xc]
// 0071b76a  8bf8                 mov edi, eax
// 0071b76c  e85f4d0500           call 0x7704d0
// 0071b771  57                   push edi
// 0071b772  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0071b776  50                   push eax
// 0071b777  8bcf                 mov ecx, edi
// 0071b779  e852e0ffff           call 0x7197d0
// 0071b77e  8b4704               mov eax, dword ptr [edi + 4]
// 0071b781  6a00                 push 0
// 0071b783  50                   push eax
// 0071b784  6a0f                 push 0xf
// 0071b786  8bce                 mov ecx, esi
// 0071b788  e82bd4ffff           call 0x718bb8
// 0071b78d  5f                   pop edi
// 0071b78e  5e                   pop esi
// 0071b78f  83c410               add esp, 0x10
// 0071b792  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?DrawCommandBar@CXTPControlComboBoxList@@MAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBox.cpp
