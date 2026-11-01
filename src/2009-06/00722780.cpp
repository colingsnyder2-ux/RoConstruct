// from server: 100% by auto
// roc 2009-06 00722780  unit: CRobloxControlColorSelector  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00722780
//
// 00722780  8b442404             mov eax, dword ptr [esp + 4]
// 00722784  83f83e               cmp eax, 0x3e
// 00722787  771a                 ja 0x7227a3
// 00722789  8d0440               lea eax, [eax + eax*2]
// 0072278c  8d848164010000       lea eax, [ecx + eax*4 + 0x164]
// 00722793  8b4808               mov ecx, dword ptr [eax + 8]
// 00722796  83f9ff               cmp ecx, -1
// 00722799  7506                 jne 0x7227a1
// 0072279b  8b4004               mov eax, dword ptr [eax + 4]
// 0072279e  c20400               ret 4
// 007227a1  8bc1                 mov eax, ecx
// 007227a3  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?GetXtremeColor@CXTPPaintManager@@QAEKI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
