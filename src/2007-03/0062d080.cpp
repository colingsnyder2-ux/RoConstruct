// from server: 100% by auto
// roc 2007-03 0062d080  unit: seg_00620000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062d080
//
// 0062d080  83795c00             cmp dword ptr [ecx + 0x5c], 0
// 0062d084  b801000000           mov eax, 1
// 0062d089  7504                 jne 0x62d08f
// 0062d08b  8b442404             mov eax, dword ptr [esp + 4]
// 0062d08f  83b9c400000000       cmp dword ptr [ecx + 0xc4], 0
// 0062d096  7413                 je 0x62d0ab
// 0062d098  3981b0000000         cmp dword ptr [ecx + 0xb0], eax
// 0062d09e  740b                 je 0x62d0ab
// 0062d0a0  8981b0000000         mov dword ptr [ecx + 0xb0], eax
// 0062d0a6  e855faffff           call 0x62cb00
// 0062d0ab  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?ShowKeyboardCues@CXTPCommandBars@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
