// from server: 100% by auto
// roc 2011-06 0082b6c0  unit: CXTPCommandBar  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0082b6c0
//
// 0082b6c0  83795c00             cmp dword ptr [ecx + 0x5c], 0
// 0082b6c4  b801000000           mov eax, 1
// 0082b6c9  7504                 jne 0x82b6cf
// 0082b6cb  8b442404             mov eax, dword ptr [esp + 4]
// 0082b6cf  83b9c400000000       cmp dword ptr [ecx + 0xc4], 0
// 0082b6d6  7413                 je 0x82b6eb
// 0082b6d8  3981b0000000         cmp dword ptr [ecx + 0xb0], eax
// 0082b6de  740b                 je 0x82b6eb
// 0082b6e0  8981b0000000         mov dword ptr [ecx + 0xb0], eax
// 0082b6e6  e895faffff           call 0x82b180
// 0082b6eb  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?ShowKeyboardCues@CXTPCommandBars@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
