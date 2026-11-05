// from server: 100% by auto
// roc 2009-12 00815b40  unit: CXTPCommandBar  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00815b40
//
// 00815b40  83795c00             cmp dword ptr [ecx + 0x5c], 0
// 00815b44  b801000000           mov eax, 1
// 00815b49  7504                 jne 0x815b4f
// 00815b4b  8b442404             mov eax, dword ptr [esp + 4]
// 00815b4f  83b9c400000000       cmp dword ptr [ecx + 0xc4], 0
// 00815b56  7413                 je 0x815b6b
// 00815b58  3981b0000000         cmp dword ptr [ecx + 0xb0], eax
// 00815b5e  740b                 je 0x815b6b
// 00815b60  8981b0000000         mov dword ptr [ecx + 0xb0], eax
// 00815b66  e895faffff           call 0x815600
// 00815b6b  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?ShowKeyboardCues@CXTPCommandBars@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
