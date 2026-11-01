// from server: 100% by auto
// roc 2007-03 006895b0  unit: seg_00680000  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006895b0
//
// 006895b0  56                   push esi
// 006895b1  8bf1                 mov esi, ecx
// 006895b3  8b06                 mov eax, dword ptr [esi]
// 006895b5  8b5078               mov edx, dword ptr [eax + 0x78]
// 006895b8  6a01                 push 1
// 006895ba  ffd2                 call edx
// 006895bc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006895c0  3bc1                 cmp eax, ecx
// 006895c2  750b                 jne 0x6895cf
// 006895c4  8bce                 mov ecx, esi
// 006895c6  e835fbffff           call 0x689100
// 006895cb  5e                   pop esi
// 006895cc  c20c00               ret 0xc
// 006895cf  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006895d3  51                   push ecx
// 006895d4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006895d8  50                   push eax
// 006895d9  51                   push ecx
// 006895da  8bce                 mov ecx, esi
// 006895dc  e8bb160b00           call 0x73ac9c
// 006895e1  5e                   pop esi
// 006895e2  c20c00               ret 0xc
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?OnVScroll@CXTPPropertyGridView@@IAEXIIPAVCScrollBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
