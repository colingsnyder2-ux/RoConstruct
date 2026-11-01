// from server: 100% by auto
// roc 2009-06 0077f220  unit: CXTThemeManagerStyle  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077f220
//
// 0077f220  56                   push esi
// 0077f221  8b742408             mov esi, dword ptr [esp + 8]
// 0077f225  85f6                 test esi, esi
// 0077f227  7506                 jne 0x77f22f
// 0077f229  33c0                 xor eax, eax
// 0077f22b  5e                   pop esi
// 0077f22c  c20400               ret 4
// 0077f22f  57                   push edi
// 0077f230  8d44240c             lea eax, [esp + 0xc]
// 0077f234  8d7904               lea edi, [ecx + 4]
// 0077f237  50                   push eax
// 0077f238  56                   push esi
// 0077f239  8bcf                 mov ecx, edi
// 0077f23b  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0077f243  e83cd30c00           call 0x84c584
// 0077f248  85c0                 test eax, eax
// 0077f24a  7519                 jne 0x77f265
// 0077f24c  53                   push ebx
// 0077f24d  8bce                 mov ecx, esi
// 0077f24f  e8e0a1f9ff           call 0x719434
// 0077f254  56                   push esi
// 0077f255  8bcf                 mov ecx, edi
// 0077f257  89442414             mov dword ptr [esp + 0x14], eax
// 0077f25b  8bd8                 mov ebx, eax
// 0077f25d  e88cd20c00           call 0x84c4ee
// 0077f262  8918                 mov dword ptr [eax], ebx
// 0077f264  5b                   pop ebx
// 0077f265  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0077f269  5f                   pop edi
// 0077f26a  5e                   pop esi
// 0077f26b  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTThemeManager.cpp (function ?GetDefaultThemeFactory@CXTThemeManager@@QAEPAVCXTThemeManagerStyleFactory@@PAUCRuntimeClass@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTThemeManager.cpp
