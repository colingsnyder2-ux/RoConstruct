// from server: 100% by auto
// roc 2007-03 00718750  unit: seg_00710000  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00718750
//
// 00718750  f644240804           test byte ptr [esp + 8], 4
// 00718755  56                   push esi
// 00718756  8bf1                 mov esi, ecx
// 00718758  7509                 jne 0x718763
// 0071875a  e8735ff0ff           call 0x61e6d2
// 0071875f  5e                   pop esi
// 00718760  c20800               ret 8
// 00718763  8b442408             mov eax, dword ptr [esp + 8]
// 00718767  50                   push eax
// 00718768  e821240200           call 0x73ab8e
// 0071876d  85c0                 test eax, eax
// 0071876f  7408                 je 0x718779
// 00718771  50                   push eax
// 00718772  8bce                 mov ecx, esi
// 00718774  e8f7faffff           call 0x718270
// 00718779  b801000000           mov eax, 1
// 0071877e  5e                   pop esi
// 0071877f  c20800               ret 8
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectButton.cpp (function ?OnPrintClient@CXTPSkinObjectButton@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectButton.cpp
