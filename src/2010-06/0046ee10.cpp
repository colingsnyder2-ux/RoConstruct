// from server: 100% by auto
// roc 2010-06 0046ee10  unit: Scintilla::CScintillaView  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0046ee10
//
// 0046ee10  83ec24               sub esp, 0x24
// 0046ee13  51                   push ecx
// 0046ee14  8d442404             lea eax, [esp + 4]
// 0046ee18  50                   push eax
// 0046ee19  ff1524a79e00         call dword ptr [0x9ea724]
// 0046ee1f  83c408               add esp, 8
// 0046ee22  85c0                 test eax, eax
// 0046ee24  7408                 je 0x46ee2e
// 0046ee26  32c0                 xor al, al
// 0046ee28  83c424               add esp, 0x24
// 0046ee2b  c20400               ret 4
// 0046ee2e  8b442428             mov eax, dword ptr [esp + 0x28]
// 0046ee32  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0046ee36  8b542410             mov edx, dword ptr [esp + 0x10]
// 0046ee3a  81c16c070000         add ecx, 0x76c
// 0046ee40  668908               mov word ptr [eax], cx
// 0046ee43  0fb74c2418           movzx ecx, word ptr [esp + 0x18]
// 0046ee48  42                   inc edx
// 0046ee49  66895002             mov word ptr [eax + 2], dx
// 0046ee4d  0fb754240c           movzx edx, word ptr [esp + 0xc]
// 0046ee52  66894804             mov word ptr [eax + 4], cx
// 0046ee56  0fb74c2408           movzx ecx, word ptr [esp + 8]
// 0046ee5b  66895006             mov word ptr [eax + 6], dx
// 0046ee5f  0fb7542404           movzx edx, word ptr [esp + 4]
// 0046ee64  66894808             mov word ptr [eax + 8], cx
// 0046ee68  0fb70c24             movzx ecx, word ptr [esp]
// 0046ee6c  6689500a             mov word ptr [eax + 0xa], dx
// 0046ee70  33d2                 xor edx, edx
// 0046ee72  6689480c             mov word ptr [eax + 0xc], cx
// 0046ee76  6689500e             mov word ptr [eax + 0xe], dx
// 0046ee7a  b001                 mov al, 1
// 0046ee7c  83c424               add esp, 0x24
// 0046ee7f  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Calendar\XTPCalendarDayView.cpp (function ?GetAsSystemTime@CTime@ATL@@QBE_NAAU_SYSTEMTIME@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Calendar/XTPCalendarDayView.cpp
