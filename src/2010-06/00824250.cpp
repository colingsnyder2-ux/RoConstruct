// from server: 100% by auto
// roc 2010-06 00824250  unit: CXTPNewToolbarDlg  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00824250
//
// 00824250  56                   push esi
// 00824251  8bf1                 mov esi, ecx
// 00824253  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00824256  85c9                 test ecx, ecx
// 00824258  7506                 jne 0x824260
// 0082425a  33c0                 xor eax, eax
// 0082425c  5e                   pop esi
// 0082425d  c20800               ret 8
// 00824260  8b4614               mov eax, dword ptr [esi + 0x14]
// 00824263  85c0                 test eax, eax
// 00824265  750a                 jne 0x824271
// 00824267  8b81a0000000         mov eax, dword ptr [ecx + 0xa0]
// 0082426d  85c0                 test eax, eax
// 0082426f  74e9                 je 0x82425a
// 00824271  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00824275  894e04               mov dword ptr [esi + 4], ecx
// 00824278  8b4020               mov eax, dword ptr [eax + 0x20]
// 0082427b  57                   push edi
// 0082427c  50                   push eax
// 0082427d  8906                 mov dword ptr [esi], eax
// 0082427f  ff1580bc9e00         call dword ptr [0x9ebc80]
// 00824285  8b542410             mov edx, dword ptr [esp + 0x10]
// 00824289  8d4618               lea eax, [esi + 0x18]
// 0082428c  50                   push eax
// 0082428d  c7460800000000       mov dword ptr [esi + 8], 0
// 00824294  c7461000000000       mov dword ptr [esi + 0x10], 0
// 0082429b  89560c               mov dword ptr [esi + 0xc], edx
// 0082429e  ff1574bc9e00         call dword ptr [0x9ebc74]
// 008242a4  8bce                 mov ecx, esi
// 008242a6  e875fcffff           call 0x823f20
// 008242ab  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 008242ae  8bf8                 mov edi, eax
// 008242b0  85c9                 test ecx, ecx
// 008242b2  740a                 je 0x8242be
// 008242b4  8b11                 mov edx, dword ptr [ecx]
// 008242b6  8b8274010000         mov eax, dword ptr [edx + 0x174]
// 008242bc  ffd0                 call eax
// 008242be  ff158cbc9e00         call dword ptr [0x9ebc8c]
// 008242c4  e89539f8ff           call 0x7a7c5e
// 008242c9  68007f0000           push 0x7f00
// 008242ce  6a00                 push 0
// 008242d0  ff15ccbb9e00         call dword ptr [0x9ebbcc]
// 008242d6  50                   push eax
// 008242d7  ff15b4bb9e00         call dword ptr [0x9ebbb4]
// 008242dd  8bc7                 mov eax, edi
// 008242df  5f                   pop edi
// 008242e0  5e                   pop esi
// 008242e1  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPCustomizeTools.cpp (function ?DoDragDrop@CXTPCustomizeDropSource@@QAEKPAVCXTPControl@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPCustomizeTools.cpp
