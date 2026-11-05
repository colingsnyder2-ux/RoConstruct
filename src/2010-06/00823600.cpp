// from server: 100% by auto
// roc 2010-06 00823600  unit: PAVCXTPCommandBar::?$CArray  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00823600
//
// 00823600  837c240400           cmp dword ptr [esp + 4], 0
// 00823605  56                   push esi
// 00823606  8bf1                 mov esi, ecx
// 00823608  7423                 je 0x82362d
// 0082360a  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0082360e  7532                 jne 0x823642
// 00823610  ff1594a39e00         call dword ptr [0x9ea394]
// 00823616  50                   push eax
// 00823617  6a00                 push 0
// 00823619  6890348200           push 0x823490
// 0082361e  6a07                 push 7
// 00823620  ff15a0ba9e00         call dword ptr [0x9ebaa0]
// 00823626  89461c               mov dword ptr [esi + 0x1c], eax
// 00823629  5e                   pop esi
// 0082362a  c20400               ret 4
// 0082362d  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00823630  85c0                 test eax, eax
// 00823632  740e                 je 0x823642
// 00823634  50                   push eax
// 00823635  ff159cba9e00         call dword ptr [0x9eba9c]
// 0082363b  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00823642  5e                   pop esi
// 00823643  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPMouseManager.cpp (function ?SetupHook@CXTPMouseManager@@AAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPMouseManager.cpp
