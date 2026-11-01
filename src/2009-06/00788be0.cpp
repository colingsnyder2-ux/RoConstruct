// from server: 100% by auto
// roc 2009-06 00788be0  unit: CXTPToolTipContextToolTip  size: 215 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00788be0
//
// 00788be0  56                   push esi
// 00788be1  8bf1                 mov esi, ecx
// 00788be3  8d8edc000000         lea ecx, [esi + 0xdc]
// 00788be9  85c9                 test ecx, ecx
// 00788beb  740b                 je 0x788bf8
// 00788bed  83790400             cmp dword ptr [ecx + 4], 0
// 00788bf1  7405                 je 0x788bf8
// 00788bf3  e8fe03f9ff           call 0x718ff6
// 00788bf8  8d8ee4000000         lea ecx, [esi + 0xe4]
// 00788bfe  85c9                 test ecx, ecx
// 00788c00  740b                 je 0x788c0d
// 00788c02  83790400             cmp dword ptr [ecx + 4], 0
// 00788c06  7405                 je 0x788c0d
// 00788c08  e8e903f9ff           call 0x718ff6
// 00788c0d  8d8eec000000         lea ecx, [esi + 0xec]
// 00788c13  85c9                 test ecx, ecx
// 00788c15  740b                 je 0x788c22
// 00788c17  83790400             cmp dword ptr [ecx + 4], 0
// 00788c1b  7405                 je 0x788c22
// 00788c1d  e8d403f9ff           call 0x718ff6
// 00788c22  8d8ef4000000         lea ecx, [esi + 0xf4]
// 00788c28  85c9                 test ecx, ecx
// 00788c2a  740b                 je 0x788c37
// 00788c2c  83790400             cmp dword ptr [ecx + 4], 0
// 00788c30  7405                 je 0x788c37
// 00788c32  e8bf03f9ff           call 0x718ff6
// 00788c37  8d8efc000000         lea ecx, [esi + 0xfc]
// 00788c3d  85c9                 test ecx, ecx
// 00788c3f  740b                 je 0x788c4c
// 00788c41  83790400             cmp dword ptr [ecx + 4], 0
// 00788c45  7405                 je 0x788c4c
// 00788c47  e8aa03f9ff           call 0x718ff6
// 00788c4c  8d8e04010000         lea ecx, [esi + 0x104]
// 00788c52  85c9                 test ecx, ecx
// 00788c54  740b                 je 0x788c61
// 00788c56  83790400             cmp dword ptr [ecx + 4], 0
// 00788c5a  7405                 je 0x788c61
// 00788c5c  e89503f9ff           call 0x718ff6
// 00788c61  8d8e0c010000         lea ecx, [esi + 0x10c]
// 00788c67  85c9                 test ecx, ecx
// 00788c69  740b                 je 0x788c76
// 00788c6b  83790400             cmp dword ptr [ecx + 4], 0
// 00788c6f  7405                 je 0x788c76
// 00788c71  e88003f9ff           call 0x718ff6
// 00788c76  8d8e14010000         lea ecx, [esi + 0x114]
// 00788c7c  85c9                 test ecx, ecx
// 00788c7e  740b                 je 0x788c8b
// 00788c80  83790400             cmp dword ptr [ecx + 4], 0
// 00788c84  7405                 je 0x788c8b
// 00788c86  e86b03f9ff           call 0x718ff6
// 00788c8b  8d8e1c010000         lea ecx, [esi + 0x11c]
// 00788c91  85c9                 test ecx, ecx
// 00788c93  740b                 je 0x788ca0
// 00788c95  83790400             cmp dword ptr [ecx + 4], 0
// 00788c99  7405                 je 0x788ca0
// 00788c9b  e85603f9ff           call 0x718ff6
// 00788ca0  8d8e24010000         lea ecx, [esi + 0x124]
// 00788ca6  5e                   pop esi
// 00788ca7  85c9                 test ecx, ecx
// 00788ca9  740b                 je 0x788cb6
// 00788cab  83790400             cmp dword ptr [ecx + 4], 0
// 00788caf  7405                 je 0x788cb6
// 00788cb1  e94003f9ff           jmp 0x718ff6
// 00788cb6  c3                   ret 
// library xtp-15.2.1/Source\Controls\Util\XTPGlobal.cpp (function ?FreeSysFonts@CXTPAuxData@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Util/XTPGlobal.cpp
