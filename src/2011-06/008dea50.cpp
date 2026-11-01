// from server: 100% by auto
// roc 2011-06 008dea50  unit: VCEdit::?$CXTMaskEditT  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008dea50
//
// 008dea50  53                   push ebx
// 008dea51  8b5c2408             mov ebx, dword ptr [esp + 8]
// 008dea55  0fbec3               movsx eax, bl
// 008dea58  56                   push esi
// 008dea59  50                   push eax
// 008dea5a  8bf1                 mov esi, ecx
// 008dea5c  ff155c07a400         call dword ptr [0xa4075c]
// 008dea62  83c404               add esp, 4
// 008dea65  85c0                 test eax, eax
// 008dea67  7516                 jne 0x8dea7f
// 008dea69  8b16                 mov edx, dword ptr [esi]
// 008dea6b  8b8254010000         mov eax, dword ptr [edx + 0x154]
// 008dea71  53                   push ebx
// 008dea72  8bce                 mov ecx, esi
// 008dea74  ffd0                 call eax
// 008dea76  85c0                 test eax, eax
// 008dea78  7505                 jne 0x8dea7f
// 008dea7a  5e                   pop esi
// 008dea7b  5b                   pop ebx
// 008dea7c  c20400               ret 4
// 008dea7f  5e                   pop esi
// 008dea80  b801000000           mov eax, 1
// 008dea85  5b                   pop ebx
// 008dea86  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\Controls\Deprecated\XTFlatComboBox.cpp (function ?IsPrintChar@?$CXTPMaskEditT@VCEdit@@@@MAEHD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Controls/Deprecated/XTFlatComboBox.cpp
