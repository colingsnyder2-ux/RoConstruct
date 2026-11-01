// from server: 100% by auto
// roc 2007-03 00620f20  unit: seg_00620000  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00620f20
//
// 00620f20  8b442404             mov eax, dword ptr [esp + 4]
// 00620f24  3d25e10000           cmp eax, 0xe125
// 00620f29  740e                 je 0x620f39
// 00620f2b  3d23e10000           cmp eax, 0xe123
// 00620f30  7407                 je 0x620f39
// 00620f32  3d22e10000           cmp eax, 0xe122
// 00620f37  7526                 jne 0x620f5f
// 00620f39  837c2408ff           cmp dword ptr [esp + 8], -1
// 00620f3e  751f                 jne 0x620f5f
// 00620f40  56                   push esi
// 00620f41  8b742410             mov esi, dword ptr [esp + 0x10]
// 00620f45  57                   push edi
// 00620f46  8b3e                 mov edi, dword ptr [esi]
// 00620f48  50                   push eax
// 00620f49  e872ffffff           call 0x620ec0
// 00620f4e  50                   push eax
// 00620f4f  8b07                 mov eax, dword ptr [edi]
// 00620f51  8bce                 mov ecx, esi
// 00620f53  ffd0                 call eax
// 00620f55  5f                   pop edi
// 00620f56  b801000000           mov eax, 1
// 00620f5b  5e                   pop esi
// 00620f5c  c21000               ret 0x10
// 00620f5f  33c0                 xor eax, eax
// 00620f61  c21000               ret 0x10
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ?OnCmdMsg@CXTPCommandBarEditCtrl@@UAEHIHPAXPAUAFX_CMDHANDLERINFO@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
