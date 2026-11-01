// from server: 100% by auto
// roc 2009-12 00863be0  unit: CXTPToolTipContextToolTip  size: 215 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00863be0
//
// 00863be0  56                   push esi
// 00863be1  8bf1                 mov esi, ecx
// 00863be3  8d8edc000000         lea ecx, [esi + 0xdc]
// 00863be9  85c9                 test ecx, ecx
// 00863beb  740b                 je 0x863bf8
// 00863bed  83790400             cmp dword ptr [ecx + 4], 0
// 00863bf1  7405                 je 0x863bf8
// 00863bf3  e82602f9ff           call 0x7f3e1e
// 00863bf8  8d8ee4000000         lea ecx, [esi + 0xe4]
// 00863bfe  85c9                 test ecx, ecx
// 00863c00  740b                 je 0x863c0d
// 00863c02  83790400             cmp dword ptr [ecx + 4], 0
// 00863c06  7405                 je 0x863c0d
// 00863c08  e81102f9ff           call 0x7f3e1e
// 00863c0d  8d8eec000000         lea ecx, [esi + 0xec]
// 00863c13  85c9                 test ecx, ecx
// 00863c15  740b                 je 0x863c22
// 00863c17  83790400             cmp dword ptr [ecx + 4], 0
// 00863c1b  7405                 je 0x863c22
// 00863c1d  e8fc01f9ff           call 0x7f3e1e
// 00863c22  8d8ef4000000         lea ecx, [esi + 0xf4]
// 00863c28  85c9                 test ecx, ecx
// 00863c2a  740b                 je 0x863c37
// 00863c2c  83790400             cmp dword ptr [ecx + 4], 0
// 00863c30  7405                 je 0x863c37
// 00863c32  e8e701f9ff           call 0x7f3e1e
// 00863c37  8d8efc000000         lea ecx, [esi + 0xfc]
// 00863c3d  85c9                 test ecx, ecx
// 00863c3f  740b                 je 0x863c4c
// 00863c41  83790400             cmp dword ptr [ecx + 4], 0
// 00863c45  7405                 je 0x863c4c
// 00863c47  e8d201f9ff           call 0x7f3e1e
// 00863c4c  8d8e04010000         lea ecx, [esi + 0x104]
// 00863c52  85c9                 test ecx, ecx
// 00863c54  740b                 je 0x863c61
// 00863c56  83790400             cmp dword ptr [ecx + 4], 0
// 00863c5a  7405                 je 0x863c61
// 00863c5c  e8bd01f9ff           call 0x7f3e1e
// 00863c61  8d8e0c010000         lea ecx, [esi + 0x10c]
// 00863c67  85c9                 test ecx, ecx
// 00863c69  740b                 je 0x863c76
// 00863c6b  83790400             cmp dword ptr [ecx + 4], 0
// 00863c6f  7405                 je 0x863c76
// 00863c71  e8a801f9ff           call 0x7f3e1e
// 00863c76  8d8e14010000         lea ecx, [esi + 0x114]
// 00863c7c  85c9                 test ecx, ecx
// 00863c7e  740b                 je 0x863c8b
// 00863c80  83790400             cmp dword ptr [ecx + 4], 0
// 00863c84  7405                 je 0x863c8b
// 00863c86  e89301f9ff           call 0x7f3e1e
// 00863c8b  8d8e1c010000         lea ecx, [esi + 0x11c]
// 00863c91  85c9                 test ecx, ecx
// 00863c93  740b                 je 0x863ca0
// 00863c95  83790400             cmp dword ptr [ecx + 4], 0
// 00863c99  7405                 je 0x863ca0
// 00863c9b  e87e01f9ff           call 0x7f3e1e
// 00863ca0  8d8e24010000         lea ecx, [esi + 0x124]
// 00863ca6  5e                   pop esi
// 00863ca7  85c9                 test ecx, ecx
// 00863ca9  740b                 je 0x863cb6
// 00863cab  83790400             cmp dword ptr [ecx + 4], 0
// 00863caf  7405                 je 0x863cb6
// 00863cb1  e96801f9ff           jmp 0x7f3e1e
// 00863cb6  c3                   ret 
// library xtp-15.2.1/Source\Controls\Util\XTPGlobal.cpp (function ?FreeSysFonts@CXTPAuxData@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Util/XTPGlobal.cpp
