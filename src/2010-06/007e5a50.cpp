// from server: 100% by auto
// roc 2010-06 007e5a50  unit: CXTTreeBase  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e5a50
//
// 007e5a50  8b5110               mov edx, dword ptr [ecx + 0x10]
// 007e5a53  8b442404             mov eax, dword ptr [esp + 4]
// 007e5a57  895048               mov dword ptr [eax + 0x48], edx
// 007e5a5a  83410cff             add dword ptr [ecx + 0xc], -1
// 007e5a5e  894110               mov dword ptr [ecx + 0x10], eax
// 007e5a61  7505                 jne 0x7e5a68
// 007e5a63  e828ffffff           call 0x7e5990
// 007e5a68  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?FreeAssoc@?$CMap@PAXPAXUCLRFONT@CXTTreeBase@@AAU12@@@IAEXPAVCAssoc@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
