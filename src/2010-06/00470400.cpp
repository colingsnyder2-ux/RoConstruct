// from server: 100% by auto
// roc 2010-06 00470400  unit: Scintilla::CScintillaView  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00470400
//
// 00470400  83ec18               sub esp, 0x18
// 00470403  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00470407  8b5004               mov edx, dword ptr [eax + 4]
// 0047040a  56                   push esi
// 0047040b  8bf1                 mov esi, ecx
// 0047040d  8b08                 mov ecx, dword ptr [eax]
// 0047040f  8d44240c             lea eax, [esp + 0xc]
// 00470413  894c2404             mov dword ptr [esp + 4], ecx
// 00470417  50                   push eax
// 00470418  8d4c2408             lea ecx, [esp + 8]
// 0047041c  8954240c             mov dword ptr [esp + 0xc], edx
// 00470420  e8ebe9ffff           call 0x46ee10
// 00470425  84c0                 test al, al
// 00470427  7420                 je 0x470449
// 00470429  8d4c240c             lea ecx, [esp + 0xc]
// 0047042d  56                   push esi
// 0047042e  51                   push ecx
// 0047042f  e82ce9ffff           call 0x46ed60
// 00470434  83c408               add esp, 8
// 00470437  85c0                 test eax, eax
// 00470439  740e                 je 0x470449
// 0047043b  33c0                 xor eax, eax
// 0047043d  894608               mov dword ptr [esi + 8], eax
// 00470440  8bc6                 mov eax, esi
// 00470442  5e                   pop esi
// 00470443  83c418               add esp, 0x18
// 00470446  c20400               ret 4
// 00470449  b801000000           mov eax, 1
// 0047044e  894608               mov dword ptr [esi + 8], eax
// 00470451  8bc6                 mov eax, esi
// 00470453  5e                   pop esi
// 00470454  83c418               add esp, 0x18
// 00470457  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxshelllistctrl.cpp (function ??4COleDateTime@ATL@@QAEAAV01@AB_J@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxshelllistctrl.cpp
