// from server: 100% by auto
// roc 2010-06 007b4ac0  unit: CXTPEdit  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b4ac0
//
// 007b4ac0  8b442404             mov eax, dword ptr [esp + 4]
// 007b4ac4  3d25e10000           cmp eax, 0xe125
// 007b4ac9  740e                 je 0x7b4ad9
// 007b4acb  3d23e10000           cmp eax, 0xe123
// 007b4ad0  7407                 je 0x7b4ad9
// 007b4ad2  3d22e10000           cmp eax, 0xe122
// 007b4ad7  7526                 jne 0x7b4aff
// 007b4ad9  837c2408ff           cmp dword ptr [esp + 8], -1
// 007b4ade  751f                 jne 0x7b4aff
// 007b4ae0  56                   push esi
// 007b4ae1  8b742410             mov esi, dword ptr [esp + 0x10]
// 007b4ae5  57                   push edi
// 007b4ae6  8b3e                 mov edi, dword ptr [esi]
// 007b4ae8  50                   push eax
// 007b4ae9  e842ffffff           call 0x7b4a30
// 007b4aee  50                   push eax
// 007b4aef  8b07                 mov eax, dword ptr [edi]
// 007b4af1  8bce                 mov ecx, esi
// 007b4af3  ffd0                 call eax
// 007b4af5  5f                   pop edi
// 007b4af6  b801000000           mov eax, 1
// 007b4afb  5e                   pop esi
// 007b4afc  c21000               ret 0x10
// 007b4aff  33c0                 xor eax, eax
// 007b4b01  c21000               ret 0x10
// library xtp-13.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?OnCmdMsg@CXTPCommandBarEditCtrl@@UAEHIHPAXPAUAFX_CMDHANDLERINFO@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlComboBox.cpp
