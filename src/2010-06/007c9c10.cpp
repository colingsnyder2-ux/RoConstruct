// from server: 100% by auto
// roc 2010-06 007c9c10  unit: CXTPCommandBar  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c9c10
//
// 007c9c10  83795c00             cmp dword ptr [ecx + 0x5c], 0
// 007c9c14  b801000000           mov eax, 1
// 007c9c19  7504                 jne 0x7c9c1f
// 007c9c1b  8b442404             mov eax, dword ptr [esp + 4]
// 007c9c1f  83b9c400000000       cmp dword ptr [ecx + 0xc4], 0
// 007c9c26  7413                 je 0x7c9c3b
// 007c9c28  3981b0000000         cmp dword ptr [ecx + 0xb0], eax
// 007c9c2e  740b                 je 0x7c9c3b
// 007c9c30  8981b0000000         mov dword ptr [ecx + 0xb0], eax
// 007c9c36  e895faffff           call 0x7c96d0
// 007c9c3b  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?ShowKeyboardCues@CXTPCommandBars@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
