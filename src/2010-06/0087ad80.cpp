// from server: 100% by auto
// roc 2010-06 0087ad80  unit: VCEdit::?$CXTMaskEditT  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0087ad80
//
// 0087ad80  53                   push ebx
// 0087ad81  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0087ad85  0fbec3               movsx eax, bl
// 0087ad88  56                   push esi
// 0087ad89  50                   push eax
// 0087ad8a  8bf1                 mov esi, ecx
// 0087ad8c  ff154ca99e00         call dword ptr [0x9ea94c]
// 0087ad92  83c404               add esp, 4
// 0087ad95  85c0                 test eax, eax
// 0087ad97  7516                 jne 0x87adaf
// 0087ad99  8b16                 mov edx, dword ptr [esi]
// 0087ad9b  8b8254010000         mov eax, dword ptr [edx + 0x154]
// 0087ada1  53                   push ebx
// 0087ada2  8bce                 mov ecx, esi
// 0087ada4  ffd0                 call eax
// 0087ada6  85c0                 test eax, eax
// 0087ada8  7505                 jne 0x87adaf
// 0087adaa  5e                   pop esi
// 0087adab  5b                   pop ebx
// 0087adac  c20400               ret 4
// 0087adaf  5e                   pop esi
// 0087adb0  b801000000           mov eax, 1
// 0087adb5  5b                   pop ebx
// 0087adb6  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Controls\XTBrowseEdit.cpp (function ?IsPrintChar@?$CXTMaskEditT@VCEdit@@@@MAEHD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTBrowseEdit.cpp
