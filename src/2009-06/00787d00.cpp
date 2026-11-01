// from server: 100% by auto
// roc 2009-06 00787d00  unit: CXTPToolTipContext  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00787d00
//
// 00787d00  837c240400           cmp dword ptr [esp + 4], 0
// 00787d05  56                   push esi
// 00787d06  8bf1                 mov esi, ecx
// 00787d08  7437                 je 0x787d41
// 00787d0a  833d2022a50000       cmp dword ptr [0xa52220], 0
// 00787d11  755a                 jne 0x787d6d
// 00787d13  833d2422a50000       cmp dword ptr [0xa52224], 0
// 00787d1a  7551                 jne 0x787d6d
// 00787d1c  ff15ece18900         call dword ptr [0x89e1ec]
// 00787d22  50                   push eax
// 00787d23  6a00                 push 0
// 00787d25  68507c7800           push 0x787c50
// 00787d2a  6a07                 push 7
// 00787d2c  ff15c4ee8900         call dword ptr [0x89eec4]
// 00787d32  89352422a500         mov dword ptr [0xa52224], esi
// 00787d38  a32022a500           mov dword ptr [0xa52220], eax
// 00787d3d  5e                   pop esi
// 00787d3e  c20400               ret 4
// 00787d41  a12022a500           mov eax, dword ptr [0xa52220]
// 00787d46  85c0                 test eax, eax
// 00787d48  7423                 je 0x787d6d
// 00787d4a  39352422a500         cmp dword ptr [0xa52224], esi
// 00787d50  751b                 jne 0x787d6d
// 00787d52  50                   push eax
// 00787d53  ff15c0ee8900         call dword ptr [0x89eec0]
// 00787d59  c7052022a50000000000 mov dword ptr [0xa52220], 0
// 00787d63  c7052422a50000000000 mov dword ptr [0xa52224], 0
// 00787d6d  5e                   pop esi
// 00787d6e  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?HookMouseMove@CXTPToolTipContextToolTip@@IAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
