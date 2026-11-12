// from server: 100% by auto
// roc 2008-06 004bbae0  unit: ProfiledRakPeer  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bbae0
//
// 004bbae0  81eca0000000         sub esp, 0xa0
// 004bbae6  68a0000000           push 0xa0
// 004bbaeb  8d442404             lea eax, [esp + 4]
// 004bbaef  6a00                 push 0
// 004bbaf1  50                   push eax
// 004bbaf2  e80d5c1e00           call 0x6a1704
// 004bbaf7  83c40c               add esp, 0xc
// 004bbafa  8d0c24               lea ecx, [esp]
// 004bbafd  51                   push ecx
// 004bbafe  b9311d9700           mov ecx, 0x971d31
// 004bbb03  e8b82d0100           call 0x4ce8c0
// 004bbb08  33c0                 xor eax, eax
// 004bbb0a  380424               cmp byte ptr [esp], al
// 004bbb0d  740c                 je 0x4bbb1b
// 004bbb0f  8d0c24               lea ecx, [esp]
// 004bbb12  83c110               add ecx, 0x10
// 004bbb15  40                   inc eax
// 004bbb16  803900               cmp byte ptr [ecx], 0
// 004bbb19  75f7                 jne 0x4bbb12
// 004bbb1b  81c4a0000000         add esp, 0xa0
// 004bbb21  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ?GetNumberOfAddresses@RakPeer@@UAEIXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
