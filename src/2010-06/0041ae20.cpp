// from server: 100% by auto
// roc 2010-06 0041ae20  unit: CXTPReportGroupRow_Batch  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0041ae20
//
// 0041ae20  51                   push ecx
// 0041ae21  833d8c55c20000       cmp dword ptr [0xc2558c], 0
// 0041ae28  755a                 jne 0x41ae84
// 0041ae2a  56                   push esi
// 0041ae2b  6a00                 push 0
// 0041ae2d  6a00                 push 0
// 0041ae2f  6a00                 push 0
// 0041ae31  ff1518a39e00         call dword ptr [0x9ea318]
// 0041ae37  687439a000           push 0xa03974
// 0041ae3c  a38c55c200           mov dword ptr [0xc2558c], eax
// 0041ae41  8bf0                 mov esi, eax
// 0041ae43  c744240802000000     mov dword ptr [esp + 8], 2
// 0041ae4b  ff158ca39e00         call dword ptr [0x9ea38c]
// 0041ae51  85c0                 test eax, eax
// 0041ae53  7424                 je 0x41ae79
// 0041ae55  686039a000           push 0xa03960
// 0041ae5a  50                   push eax
// 0041ae5b  ff1590a39e00         call dword ptr [0x9ea390]
// 0041ae61  85c0                 test eax, eax
// 0041ae63  7414                 je 0x41ae79
// 0041ae65  6a04                 push 4
// 0041ae67  8d4c2408             lea ecx, [esp + 8]
// 0041ae6b  51                   push ecx
// 0041ae6c  6a00                 push 0
// 0041ae6e  56                   push esi
// 0041ae6f  ffd0                 call eax
// 0041ae71  a39455c200           mov dword ptr [0xc25594], eax
// 0041ae76  5e                   pop esi
// 0041ae77  59                   pop ecx
// 0041ae78  c3                   ret 
// 0041ae79  b801000000           mov eax, 1
// 0041ae7e  a39455c200           mov dword ptr [0xc25594], eax
// 0041ae83  5e                   pop esi
// 0041ae84  59                   pop ecx
// 0041ae85  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?CreateHeapIfNeed@?$CXTPHeapAllocatorT@UCXTPReportDataAllocatorData@@@@SAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
