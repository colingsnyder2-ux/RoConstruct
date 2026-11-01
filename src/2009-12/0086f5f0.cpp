// from server: 100% by auto
// roc 2009-12 0086f5f0  unit: PAVCXTPCommandBar::?$CArray  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086f5f0
//
// 0086f5f0  837c240400           cmp dword ptr [esp + 4], 0
// 0086f5f5  56                   push esi
// 0086f5f6  8bf1                 mov esi, ecx
// 0086f5f8  7423                 je 0x86f61d
// 0086f5fa  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0086f5fe  7532                 jne 0x86f632
// 0086f600  ff1524b29800         call dword ptr [0x98b224]
// 0086f606  50                   push eax
// 0086f607  6a00                 push 0
// 0086f609  6880f48600           push 0x86f480
// 0086f60e  6a07                 push 7
// 0086f610  ff15d0ca9800         call dword ptr [0x98cad0]
// 0086f616  89461c               mov dword ptr [esi + 0x1c], eax
// 0086f619  5e                   pop esi
// 0086f61a  c20400               ret 4
// 0086f61d  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0086f620  85c0                 test eax, eax
// 0086f622  740e                 je 0x86f632
// 0086f624  50                   push eax
// 0086f625  ff15ccca9800         call dword ptr [0x98cacc]
// 0086f62b  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0086f632  5e                   pop esi
// 0086f633  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPMouseManager.cpp (function ?SetupHook@CXTPMouseManager@@AAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMouseManager.cpp
