// from server: 100% by auto
// roc 2010-06 00816ce0  unit: CXTPToolTipContext  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00816ce0
//
// 00816ce0  837c240400           cmp dword ptr [esp + 4], 0
// 00816ce5  56                   push esi
// 00816ce6  8bf1                 mov esi, ecx
// 00816ce8  7437                 je 0x816d21
// 00816cea  833da85dc20000       cmp dword ptr [0xc25da8], 0
// 00816cf1  755a                 jne 0x816d4d
// 00816cf3  833dac5dc20000       cmp dword ptr [0xc25dac], 0
// 00816cfa  7551                 jne 0x816d4d
// 00816cfc  ff1594a39e00         call dword ptr [0x9ea394]
// 00816d02  50                   push eax
// 00816d03  6a00                 push 0
// 00816d05  68306c8100           push 0x816c30
// 00816d0a  6a07                 push 7
// 00816d0c  ff15a0ba9e00         call dword ptr [0x9ebaa0]
// 00816d12  8935ac5dc200         mov dword ptr [0xc25dac], esi
// 00816d18  a3a85dc200           mov dword ptr [0xc25da8], eax
// 00816d1d  5e                   pop esi
// 00816d1e  c20400               ret 4
// 00816d21  a1a85dc200           mov eax, dword ptr [0xc25da8]
// 00816d26  85c0                 test eax, eax
// 00816d28  7423                 je 0x816d4d
// 00816d2a  3935ac5dc200         cmp dword ptr [0xc25dac], esi
// 00816d30  751b                 jne 0x816d4d
// 00816d32  50                   push eax
// 00816d33  ff159cba9e00         call dword ptr [0x9eba9c]
// 00816d39  c705a85dc20000000000 mov dword ptr [0xc25da8], 0
// 00816d43  c705ac5dc20000000000 mov dword ptr [0xc25dac], 0
// 00816d4d  5e                   pop esi
// 00816d4e  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPToolTipContext.cpp (function ?HookMouseMove@CXTPToolTipContextToolTip@@IAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPToolTipContext.cpp
