// from server: 100% by auto
// roc 2010-06 00817bc0  unit: CXTPToolTipContextToolTip  size: 215 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00817bc0
//
// 00817bc0  56                   push esi
// 00817bc1  8bf1                 mov esi, ecx
// 00817bc3  8d8edc000000         lea ecx, [esi + 0xdc]
// 00817bc9  85c9                 test ecx, ecx
// 00817bcb  740b                 je 0x817bd8
// 00817bcd  83790400             cmp dword ptr [ecx + 4], 0
// 00817bd1  7405                 je 0x817bd8
// 00817bd3  e88603f9ff           call 0x7a7f5e
// 00817bd8  8d8ee4000000         lea ecx, [esi + 0xe4]
// 00817bde  85c9                 test ecx, ecx
// 00817be0  740b                 je 0x817bed
// 00817be2  83790400             cmp dword ptr [ecx + 4], 0
// 00817be6  7405                 je 0x817bed
// 00817be8  e87103f9ff           call 0x7a7f5e
// 00817bed  8d8eec000000         lea ecx, [esi + 0xec]
// 00817bf3  85c9                 test ecx, ecx
// 00817bf5  740b                 je 0x817c02
// 00817bf7  83790400             cmp dword ptr [ecx + 4], 0
// 00817bfb  7405                 je 0x817c02
// 00817bfd  e85c03f9ff           call 0x7a7f5e
// 00817c02  8d8ef4000000         lea ecx, [esi + 0xf4]
// 00817c08  85c9                 test ecx, ecx
// 00817c0a  740b                 je 0x817c17
// 00817c0c  83790400             cmp dword ptr [ecx + 4], 0
// 00817c10  7405                 je 0x817c17
// 00817c12  e84703f9ff           call 0x7a7f5e
// 00817c17  8d8efc000000         lea ecx, [esi + 0xfc]
// 00817c1d  85c9                 test ecx, ecx
// 00817c1f  740b                 je 0x817c2c
// 00817c21  83790400             cmp dword ptr [ecx + 4], 0
// 00817c25  7405                 je 0x817c2c
// 00817c27  e83203f9ff           call 0x7a7f5e
// 00817c2c  8d8e04010000         lea ecx, [esi + 0x104]
// 00817c32  85c9                 test ecx, ecx
// 00817c34  740b                 je 0x817c41
// 00817c36  83790400             cmp dword ptr [ecx + 4], 0
// 00817c3a  7405                 je 0x817c41
// 00817c3c  e81d03f9ff           call 0x7a7f5e
// 00817c41  8d8e0c010000         lea ecx, [esi + 0x10c]
// 00817c47  85c9                 test ecx, ecx
// 00817c49  740b                 je 0x817c56
// 00817c4b  83790400             cmp dword ptr [ecx + 4], 0
// 00817c4f  7405                 je 0x817c56
// 00817c51  e80803f9ff           call 0x7a7f5e
// 00817c56  8d8e14010000         lea ecx, [esi + 0x114]
// 00817c5c  85c9                 test ecx, ecx
// 00817c5e  740b                 je 0x817c6b
// 00817c60  83790400             cmp dword ptr [ecx + 4], 0
// 00817c64  7405                 je 0x817c6b
// 00817c66  e8f302f9ff           call 0x7a7f5e
// 00817c6b  8d8e1c010000         lea ecx, [esi + 0x11c]
// 00817c71  85c9                 test ecx, ecx
// 00817c73  740b                 je 0x817c80
// 00817c75  83790400             cmp dword ptr [ecx + 4], 0
// 00817c79  7405                 je 0x817c80
// 00817c7b  e8de02f9ff           call 0x7a7f5e
// 00817c80  8d8e24010000         lea ecx, [esi + 0x124]
// 00817c86  5e                   pop esi
// 00817c87  85c9                 test ecx, ecx
// 00817c89  740b                 je 0x817c96
// 00817c8b  83790400             cmp dword ptr [ecx + 4], 0
// 00817c8f  7405                 je 0x817c96
// 00817c91  e9c802f9ff           jmp 0x7a7f5e
// 00817c96  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTGlobal.cpp (function ?FreeSysFonts@CXTAuxData@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTGlobal.cpp
