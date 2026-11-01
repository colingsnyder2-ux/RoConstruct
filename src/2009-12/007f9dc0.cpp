// from server: 100% by auto
// roc 2009-12 007f9dc0  unit: CXTPEdit  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f9dc0
//
// 007f9dc0  8b442404             mov eax, dword ptr [esp + 4]
// 007f9dc4  3d25e10000           cmp eax, 0xe125
// 007f9dc9  740e                 je 0x7f9dd9
// 007f9dcb  3d23e10000           cmp eax, 0xe123
// 007f9dd0  7407                 je 0x7f9dd9
// 007f9dd2  3d22e10000           cmp eax, 0xe122
// 007f9dd7  7526                 jne 0x7f9dff
// 007f9dd9  837c2408ff           cmp dword ptr [esp + 8], -1
// 007f9dde  751f                 jne 0x7f9dff
// 007f9de0  56                   push esi
// 007f9de1  8b742410             mov esi, dword ptr [esp + 0x10]
// 007f9de5  57                   push edi
// 007f9de6  8b3e                 mov edi, dword ptr [esi]
// 007f9de8  50                   push eax
// 007f9de9  e842ffffff           call 0x7f9d30
// 007f9dee  50                   push eax
// 007f9def  8b07                 mov eax, dword ptr [edi]
// 007f9df1  8bce                 mov ecx, esi
// 007f9df3  ffd0                 call eax
// 007f9df5  5f                   pop edi
// 007f9df6  b801000000           mov eax, 1
// 007f9dfb  5e                   pop esi
// 007f9dfc  c21000               ret 0x10
// 007f9dff  33c0                 xor eax, eax
// 007f9e01  c21000               ret 0x10
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ?OnCmdMsg@CXTPCommandBarEditCtrl@@UAEHIHPAXPAUAFX_CMDHANDLERINFO@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
