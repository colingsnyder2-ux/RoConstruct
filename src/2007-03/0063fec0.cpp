// from server: 100% by auto
// roc 2007-03 0063fec0  unit: seg_00630000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0063fec0
//
// 0063fec0  8b442404             mov eax, dword ptr [esp + 4]
// 0063fec4  56                   push esi
// 0063fec5  50                   push eax
// 0063fec6  8bf1                 mov esi, ecx
// 0063fec8  e8bfeefdff           call 0x61ed8c
// 0063fecd  8b16                 mov edx, dword ptr [esi]
// 0063fecf  8b828c010000         mov eax, dword ptr [edx + 0x18c]
// 0063fed5  8bce                 mov ecx, esi
// 0063fed7  ffd0                 call eax
// 0063fed9  8bc8                 mov ecx, eax
// 0063fedb  e8b2e5fdff           call 0x61e492
// 0063fee0  5e                   pop esi
// 0063fee1  c20400               ret 4
// library xtp-15.2.1/Source\Calendar\XTPCalendarControlView.cpp (function ?OnSetFocus@CXTPCalendarControlView@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarControlView.cpp
