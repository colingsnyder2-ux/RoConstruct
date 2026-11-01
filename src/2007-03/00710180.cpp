// from server: 100% by auto
// roc 2007-03 00710180  unit: seg_00710000  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00710180
//
// 00710180  56                   push esi
// 00710181  8d442408             lea eax, [esp + 8]
// 00710185  50                   push eax
// 00710186  8bf1                 mov esi, ecx
// 00710188  e8235ef7ff           call 0x685fb0
// 0071018d  85c0                 test eax, eax
// 0071018f  7530                 jne 0x7101c1
// 00710191  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00710195  8b542408             mov edx, dword ptr [esp + 8]
// 00710199  51                   push ecx
// 0071019a  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0071019e  83ec10               sub esp, 0x10
// 007101a1  8bc4                 mov eax, esp
// 007101a3  8910                 mov dword ptr [eax], edx
// 007101a5  8b542424             mov edx, dword ptr [esp + 0x24]
// 007101a9  894804               mov dword ptr [eax + 4], ecx
// 007101ac  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007101b0  895008               mov dword ptr [eax + 8], edx
// 007101b3  89480c               mov dword ptr [eax + 0xc], ecx
// 007101b6  8bce                 mov ecx, esi
// 007101b8  e8f3f7f1ff           call 0x62f9b0
// 007101bd  5e                   pop esi
// 007101be  c21400               ret 0x14
// 007101c1  68b4d17c00           push 0x7cd1b4
// 007101c6  ff15ccea7700         call dword ptr [0x77eacc]
// 007101cc  8b542418             mov edx, dword ptr [esp + 0x18]
// 007101d0  8902                 mov dword ptr [edx], eax
// 007101d2  33c0                 xor eax, eax
// 007101d4  5e                   pop esi
// 007101d5  c21400               ret 0x14
// library xtp-15.2.1/Source\Ribbon\XTPRibbonControlTab.cpp (function ?GetAccessibleDefaultAction@CXTPRibbonControlTab@@MAEJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonControlTab.cpp
