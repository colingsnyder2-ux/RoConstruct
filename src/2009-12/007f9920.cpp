// from server: 100% by auto
// roc 2009-12 007f9920  unit: CXTPControlComboBoxList  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f9920
//
// 007f9920  83ec10               sub esp, 0x10
// 007f9923  56                   push esi
// 007f9924  57                   push edi
// 007f9925  8bf1                 mov esi, ecx
// 007f9927  e8a4600300           call 0x82f9d0
// 007f992c  6a05                 push 5
// 007f992e  8bc8                 mov ecx, eax
// 007f9930  e8cb570300           call 0x82f100
// 007f9935  56                   push esi
// 007f9936  8d4c240c             lea ecx, [esp + 0xc]
// 007f993a  8bf8                 mov edi, eax
// 007f993c  e88f190500           call 0x84b2d0
// 007f9941  57                   push edi
// 007f9942  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007f9946  50                   push eax
// 007f9947  8bcf                 mov ecx, edi
// 007f9949  e8b0acffff           call 0x7f45fe
// 007f994e  8b4704               mov eax, dword ptr [edi + 4]
// 007f9951  6a00                 push 0
// 007f9953  50                   push eax
// 007f9954  6a0f                 push 0xf
// 007f9956  8bce                 mov ecx, esi
// 007f9958  e883a0ffff           call 0x7f39e0
// 007f995d  5f                   pop edi
// 007f995e  5e                   pop esi
// 007f995f  83c410               add esp, 0x10
// 007f9962  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?DrawCommandBar@CXTPControlComboBoxList@@MAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBox.cpp
