// from server: 100% by auto
// roc 2010-06 00881e70  unit: CXTPPropertyGridInplaceList  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00881e70
//
// 00881e70  56                   push esi
// 00881e71  8bf1                 mov esi, ecx
// 00881e73  e8f860f2ff           call 0x7a7f70
// 00881e78  6a00                 push 0
// 00881e7a  e881f9f7ff           call 0x801800
// 00881e7f  8b06                 mov eax, dword ptr [esi]
// 00881e81  8b9068010000         mov edx, dword ptr [eax + 0x168]
// 00881e87  83c404               add esp, 4
// 00881e8a  8bce                 mov ecx, esi
// 00881e8c  ffd2                 call edx
// 00881e8e  8b06                 mov eax, dword ptr [esi]
// 00881e90  8b5068               mov edx, dword ptr [eax + 0x68]
// 00881e93  8bce                 mov ecx, esi
// 00881e95  ffd2                 call edx
// 00881e97  5e                   pop esi
// 00881e98  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?OnKillFocus@CXTPPropertyGridInplaceList@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/PropertyGrid/XTPPropertyGridInplaceList.cpp
