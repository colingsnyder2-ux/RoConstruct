// from server: 100% by auto
// roc 2010-06 00820f30  unit: CXTCaption  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00820f30
//
// 00820f30  8b442404             mov eax, dword ptr [esp + 4]
// 00820f34  83ec10               sub esp, 0x10
// 00820f37  56                   push esi
// 00820f38  57                   push edi
// 00820f39  50                   push eax
// 00820f3a  8bf1                 mov esi, ecx
// 00820f3c  e82bbe1500           call 0x97cd6c
// 00820f41  8bf8                 mov edi, eax
// 00820f43  85ff                 test edi, edi
// 00820f45  743b                 je 0x820f82
// 00820f47  56                   push esi
// 00820f48  8d4c240c             lea ecx, [esp + 0xc]
// 00820f4c  e8bfe3fdff           call 0x7ff310
// 00820f51  8b16                 mov edx, dword ptr [esi]
// 00820f53  8b926c010000         mov edx, dword ptr [edx + 0x16c]
// 00820f59  8d442408             lea eax, [esp + 8]
// 00820f5d  50                   push eax
// 00820f5e  57                   push edi
// 00820f5f  8bce                 mov ecx, esi
// 00820f61  ffd2                 call edx
// 00820f63  8b06                 mov eax, dword ptr [esi]
// 00820f65  8b9070010000         mov edx, dword ptr [eax + 0x170]
// 00820f6b  57                   push edi
// 00820f6c  8bce                 mov ecx, esi
// 00820f6e  ffd2                 call edx
// 00820f70  8b06                 mov eax, dword ptr [esi]
// 00820f72  8b9074010000         mov edx, dword ptr [eax + 0x174]
// 00820f78  8d4c2408             lea ecx, [esp + 8]
// 00820f7c  51                   push ecx
// 00820f7d  57                   push edi
// 00820f7e  8bce                 mov ecx, esi
// 00820f80  ffd2                 call edx
// 00820f82  5f                   pop edi
// 00820f83  b801000000           mov eax, 1
// 00820f88  5e                   pop esi
// 00820f89  83c410               add esp, 0x10
// 00820f8c  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\Controls\XTCaption.cpp (function ?OnPrintClient@CXTCaption@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTCaption.cpp
