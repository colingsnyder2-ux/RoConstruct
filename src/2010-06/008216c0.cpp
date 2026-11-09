// from server: 100% by auto
// roc 2010-06 008216c0  unit: CSelectionCaption  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008216c0
//
// 008216c0  8b442404             mov eax, dword ptr [esp + 4]
// 008216c4  56                   push esi
// 008216c5  8bf1                 mov esi, ecx
// 008216c7  85c0                 test eax, eax
// 008216c9  7403                 je 0x8216ce
// 008216cb  89466c               mov dword ptr [esi + 0x6c], eax
// 008216ce  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008216d2  85c0                 test eax, eax
// 008216d4  744e                 je 0x821724
// 008216d6  8b4004               mov eax, dword ptr [eax + 4]
// 008216d9  57                   push edi
// 008216da  8b3d54ba9e00         mov edi, dword ptr [0x9eba54]
// 008216e0  6a01                 push 1
// 008216e2  50                   push eax
// 008216e3  8b4620               mov eax, dword ptr [esi + 0x20]
// 008216e6  6a30                 push 0x30
// 008216e8  50                   push eax
// 008216e9  ffd7                 call edi
// 008216eb  8b8efc000000         mov ecx, dword ptr [esi + 0xfc]
// 008216f1  51                   push ecx
// 008216f2  ff1528bc9e00         call dword ptr [0x9ebc28]
// 008216f8  85c0                 test eax, eax
// 008216fa  7427                 je 0x821723
// 008216fc  8b5620               mov edx, dword ptr [esi + 0x20]
// 008216ff  6a00                 push 0
// 00821701  6a00                 push 0
// 00821703  6a31                 push 0x31
// 00821705  52                   push edx
// 00821706  ffd7                 call edi
// 00821708  50                   push eax
// 00821709  e8966df8ff           call 0x7a84a4
// 0082170e  85c0                 test eax, eax
// 00821710  7403                 je 0x821715
// 00821712  8b4004               mov eax, dword ptr [eax + 4]
// 00821715  6a01                 push 1
// 00821717  50                   push eax
// 00821718  8b86fc000000         mov eax, dword ptr [esi + 0xfc]
// 0082171e  6a30                 push 0x30
// 00821720  50                   push eax
// 00821721  ffd7                 call edi
// 00821723  5f                   pop edi
// 00821724  8b442410             mov eax, dword ptr [esp + 0x10]
// 00821728  85c0                 test eax, eax
// 0082172a  740d                 je 0x821739
// 0082172c  50                   push eax
// 0082172d  8d8ed0000000         lea ecx, [esi + 0xd0]
// 00821733  ff158cce9e00         call dword ptr [0x9ece8c]
// 00821739  8b442414             mov eax, dword ptr [esp + 0x14]
// 0082173d  85c0                 test eax, eax
// 0082173f  7406                 je 0x821747
// 00821741  8986cc000000         mov dword ptr [esi + 0xcc], eax
// 00821747  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0082174a  6a01                 push 1
// 0082174c  6a00                 push 0
// 0082174e  51                   push ecx
// 0082174f  ff1578ba9e00         call dword ptr [0x9eba78]
// 00821755  5e                   pop esi
// 00821756  c21000               ret 0x10
// library xtp-13.2.1-shared-mfc/Source\Controls\XTCaption.cpp (function ?ModifyCaptionStyle@CXTCaption@@UAEXHPAVCFont@@PBDPAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTCaption.cpp
