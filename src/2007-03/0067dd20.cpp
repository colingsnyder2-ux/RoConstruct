// from server: 100% by auto
// roc 2007-03 0067dd20  unit: seg_00670000  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067dd20
//
// 0067dd20  83ec18               sub esp, 0x18
// 0067dd23  56                   push esi
// 0067dd24  8d44240c             lea eax, [esp + 0xc]
// 0067dd28  57                   push edi
// 0067dd29  50                   push eax
// 0067dd2a  e8c18f0000           call 0x686cf0
// 0067dd2f  8bc8                 mov ecx, eax
// 0067dd31  e88a8b0000           call 0x6868c0
// 0067dd36  8b742424             mov esi, dword ptr [esp + 0x24]
// 0067dd3a  8b442418             mov eax, dword ptr [esp + 0x18]
// 0067dd3e  8b4e08               mov ecx, dword ptr [esi + 8]
// 0067dd41  8b3d58ed7700         mov edi, dword ptr [0x77ed58]
// 0067dd47  8d50fc               lea edx, [eax - 4]
// 0067dd4a  3bd1                 cmp edx, ecx
// 0067dd4c  7d0b                 jge 0x67dd59
// 0067dd4e  2bc1                 sub eax, ecx
// 0067dd50  6a00                 push 0
// 0067dd52  83e804               sub eax, 4
// 0067dd55  50                   push eax
// 0067dd56  56                   push esi
// 0067dd57  ffd7                 call edi
// 0067dd59  8b0e                 mov ecx, dword ptr [esi]
// 0067dd5b  8b442410             mov eax, dword ptr [esp + 0x10]
// 0067dd5f  3bc1                 cmp eax, ecx
// 0067dd61  7e08                 jle 0x67dd6b
// 0067dd63  6a00                 push 0
// 0067dd65  2bc1                 sub eax, ecx
// 0067dd67  50                   push eax
// 0067dd68  56                   push esi
// 0067dd69  ffd7                 call edi
// 0067dd6b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0067dd6f  83c0fc               add eax, -4
// 0067dd72  3b460c               cmp eax, dword ptr [esi + 0xc]
// 0067dd75  7d1b                 jge 0x67dd92
// 0067dd77  8d4c2408             lea ecx, [esp + 8]
// 0067dd7b  51                   push ecx
// 0067dd7c  ff1524ed7700         call dword ptr [0x77ed24]
// 0067dd82  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0067dd86  2b560c               sub edx, dword ptr [esi + 0xc]
// 0067dd89  83ea03               sub edx, 3
// 0067dd8c  52                   push edx
// 0067dd8d  6a00                 push 0
// 0067dd8f  56                   push esi
// 0067dd90  ffd7                 call edi
// 0067dd92  5f                   pop edi
// 0067dd93  5e                   pop esi
// 0067dd94  83c418               add esp, 0x18
// 0067dd97  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?EnsureVisible@CXTPToolTipContextToolTip@@IAEXAAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
