// from server: 100% by auto
// roc 2009-06 0072ae90  unit: CXTPCommandBar  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0072ae90
//
// 0072ae90  83795c00             cmp dword ptr [ecx + 0x5c], 0
// 0072ae94  b801000000           mov eax, 1
// 0072ae99  7504                 jne 0x72ae9f
// 0072ae9b  8b442404             mov eax, dword ptr [esp + 4]
// 0072ae9f  83b9c400000000       cmp dword ptr [ecx + 0xc4], 0
// 0072aea6  7413                 je 0x72aebb
// 0072aea8  3981b0000000         cmp dword ptr [ecx + 0xb0], eax
// 0072aeae  740b                 je 0x72aebb
// 0072aeb0  8981b0000000         mov dword ptr [ecx + 0xb0], eax
// 0072aeb6  e895faffff           call 0x72a950
// 0072aebb  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?ShowKeyboardCues@CXTPCommandBars@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
