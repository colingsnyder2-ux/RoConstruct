// from server: 100% by auto
// roc 2009-12 008333e0  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008333e0
//
// 008333e0  51                   push ecx
// 008333e1  56                   push esi
// 008333e2  8bf1                 mov esi, ecx
// 008333e4  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 008333e7  e886300f00           call 0x926472
// 008333ec  a900040000           test eax, 0x400
// 008333f1  740d                 je 0x833400
// 008333f3  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 008333f6  e8350afcff           call 0x7f3e30
// 008333fb  5e                   pop esi
// 008333fc  59                   pop ecx
// 008333fd  c20c00               ret 0xc
// 00833400  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00833404  8b542410             mov edx, dword ptr [esp + 0x10]
// 00833408  57                   push edi
// 00833409  8d442408             lea eax, [esp + 8]
// 0083340d  50                   push eax
// 0083340e  51                   push ecx
// 0083340f  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00833412  52                   push edx
// 00833413  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0083341b  e8f40dfcff           call 0x7f4214
// 00833420  8bf8                 mov edi, eax
// 00833422  85ff                 test edi, edi
// 00833424  7437                 je 0x83345d
// 00833426  f644240846           test byte ptr [esp + 8], 0x46
// 0083342b  7430                 je 0x83345d
// 0083342d  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00833430  6a02                 push 2
// 00833432  57                   push edi
// 00833433  e8ce320f00           call 0x926706
// 00833438  a802                 test al, 2
// 0083343a  752c                 jne 0x833468
// 0083343c  6a00                 push 0
// 0083343e  6a00                 push 0
// 00833440  8bce                 mov ecx, esi
// 00833442  e8c9f1ffff           call 0x832610
// 00833447  57                   push edi
// 00833448  8bce                 mov ecx, esi
// 0083344a  e881f0ffff           call 0x8324d0
// 0083344f  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00833452  e8d909fcff           call 0x7f3e30
// 00833457  5f                   pop edi
// 00833458  5e                   pop esi
// 00833459  59                   pop ecx
// 0083345a  c20c00               ret 0xc
// 0083345d  6a00                 push 0
// 0083345f  6a00                 push 0
// 00833461  8bce                 mov ecx, esi
// 00833463  e8a8f1ffff           call 0x832610
// 00833468  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0083346b  e8c009fcff           call 0x7f3e30
// 00833470  5f                   pop edi
// 00833471  5e                   pop esi
// 00833472  59                   pop ecx
// 00833473  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnRButtonDown@CXTPTreeBase@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
