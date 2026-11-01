// from server: 100% by auto
// roc 2009-06 00794490  unit: PAVCXTPCommandBar::?$CArray  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00794490
//
// 00794490  837c240400           cmp dword ptr [esp + 4], 0
// 00794495  56                   push esi
// 00794496  8bf1                 mov esi, ecx
// 00794498  7423                 je 0x7944bd
// 0079449a  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0079449e  7532                 jne 0x7944d2
// 007944a0  ff15ece18900         call dword ptr [0x89e1ec]
// 007944a6  50                   push eax
// 007944a7  6a00                 push 0
// 007944a9  6820437900           push 0x794320
// 007944ae  6a07                 push 7
// 007944b0  ff15c4ee8900         call dword ptr [0x89eec4]
// 007944b6  89461c               mov dword ptr [esi + 0x1c], eax
// 007944b9  5e                   pop esi
// 007944ba  c20400               ret 4
// 007944bd  8b461c               mov eax, dword ptr [esi + 0x1c]
// 007944c0  85c0                 test eax, eax
// 007944c2  740e                 je 0x7944d2
// 007944c4  50                   push eax
// 007944c5  ff15c0ee8900         call dword ptr [0x89eec0]
// 007944cb  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007944d2  5e                   pop esi
// 007944d3  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPMouseManager.cpp (function ?SetupHook@CXTPMouseManager@@AAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMouseManager.cpp
