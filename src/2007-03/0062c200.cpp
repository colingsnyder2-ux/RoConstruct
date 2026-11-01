// from server: 100% by auto
// roc 2007-03 0062c200  unit: seg_00620000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062c200
//
// 0062c200  8b442404             mov eax, dword ptr [esp + 4]
// 0062c204  894154               mov dword ptr [ecx + 0x54], eax
// 0062c207  e874f7ffff           call 0x62b980
// 0062c20c  8bc8                 mov ecx, eax
// 0062c20e  e80dd3ffff           call 0x629520
// 0062c213  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?SetImageManager@CXTPCommandBars@@QAEXPAVCXTPImageManager@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
