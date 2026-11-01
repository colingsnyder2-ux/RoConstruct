// from server: 100% by auto
// roc 2011-06 0048b720  unit: Scintilla::CScintillaView  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0048b720
//
// 0048b720  83ec24               sub esp, 0x24
// 0048b723  51                   push ecx
// 0048b724  8d442404             lea eax, [esp + 4]
// 0048b728  50                   push eax
// 0048b729  ff158809a400         call dword ptr [0xa40988]
// 0048b72f  83c408               add esp, 8
// 0048b732  85c0                 test eax, eax
// 0048b734  7408                 je 0x48b73e
// 0048b736  32c0                 xor al, al
// 0048b738  83c424               add esp, 0x24
// 0048b73b  c20400               ret 4
// 0048b73e  8b442428             mov eax, dword ptr [esp + 0x28]
// 0048b742  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0048b746  8b542410             mov edx, dword ptr [esp + 0x10]
// 0048b74a  81c16c070000         add ecx, 0x76c
// 0048b750  668908               mov word ptr [eax], cx
// 0048b753  0fb74c2418           movzx ecx, word ptr [esp + 0x18]
// 0048b758  42                   inc edx
// 0048b759  66895002             mov word ptr [eax + 2], dx
// 0048b75d  0fb754240c           movzx edx, word ptr [esp + 0xc]
// 0048b762  66894804             mov word ptr [eax + 4], cx
// 0048b766  0fb74c2408           movzx ecx, word ptr [esp + 8]
// 0048b76b  66895006             mov word ptr [eax + 6], dx
// 0048b76f  0fb7542404           movzx edx, word ptr [esp + 4]
// 0048b774  66894808             mov word ptr [eax + 8], cx
// 0048b778  0fb70c24             movzx ecx, word ptr [esp]
// 0048b77c  6689500a             mov word ptr [eax + 0xa], dx
// 0048b780  33d2                 xor edx, edx
// 0048b782  6689480c             mov word ptr [eax + 0xc], cx
// 0048b786  6689500e             mov word ptr [eax + 0xe], dx
// 0048b78a  b001                 mov al, 1
// 0048b78c  83c424               add esp, 0x24
// 0048b78f  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\Calendar\XTPCalendarControl.cpp (function ?GetAsSystemTime@CTime@ATL@@QBE_NAAU_SYSTEMTIME@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Calendar/XTPCalendarControl.cpp
