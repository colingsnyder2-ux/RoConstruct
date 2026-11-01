// from server: 100% by auto
// roc 2012-06 0049e440  unit: CrashReporter  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0049e440
//
// 0049e440  83ec24               sub esp, 0x24
// 0049e443  51                   push ecx
// 0049e444  8d442404             lea eax, [esp + 4]
// 0049e448  50                   push eax
// 0049e449  ff15a029b200         call dword ptr [0xb229a0]
// 0049e44f  83c408               add esp, 8
// 0049e452  85c0                 test eax, eax
// 0049e454  7408                 je 0x49e45e
// 0049e456  32c0                 xor al, al
// 0049e458  83c424               add esp, 0x24
// 0049e45b  c20400               ret 4
// 0049e45e  8b442428             mov eax, dword ptr [esp + 0x28]
// 0049e462  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0049e466  8b542410             mov edx, dword ptr [esp + 0x10]
// 0049e46a  81c16c070000         add ecx, 0x76c
// 0049e470  668908               mov word ptr [eax], cx
// 0049e473  0fb74c2418           movzx ecx, word ptr [esp + 0x18]
// 0049e478  42                   inc edx
// 0049e479  66895002             mov word ptr [eax + 2], dx
// 0049e47d  0fb754240c           movzx edx, word ptr [esp + 0xc]
// 0049e482  66894804             mov word ptr [eax + 4], cx
// 0049e486  0fb74c2408           movzx ecx, word ptr [esp + 8]
// 0049e48b  66895006             mov word ptr [eax + 6], dx
// 0049e48f  0fb7542404           movzx edx, word ptr [esp + 4]
// 0049e494  66894808             mov word ptr [eax + 8], cx
// 0049e498  0fb70c24             movzx ecx, word ptr [esp]
// 0049e49c  6689500a             mov word ptr [eax + 0xa], dx
// 0049e4a0  33d2                 xor edx, edx
// 0049e4a2  6689480c             mov word ptr [eax + 0xc], cx
// 0049e4a6  6689500e             mov word ptr [eax + 0xe], dx
// 0049e4aa  b001                 mov al, 1
// 0049e4ac  83c424               add esp, 0x24
// 0049e4af  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\Calendar\XTPCalendarControl.cpp (function ?GetAsSystemTime@CTime@ATL@@QBE_NAAU_SYSTEMTIME@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Calendar/XTPCalendarControl.cpp
