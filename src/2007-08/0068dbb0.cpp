// from server: 100% by auto
// roc 2007-08 0068dbb0  unit: CXTPTabClientWnd  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0068dbb0
//
// 0068dbb0  56                   push esi
// 0068dbb1  8bf1                 mov esi, ecx
// 0068dbb3  83bed800000000       cmp dword ptr [esi + 0xd8], 0
// 0068dbba  57                   push edi
// 0068dbbb  7512                 jne 0x68dbcf
// 0068dbbd  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0068dbc1  50                   push eax
// 0068dbc2  e8f9f8ffff           call 0x68d4c0
// 0068dbc7  50                   push eax
// 0068dbc8  8bce                 mov ecx, esi
// 0068dbca  e831e3ffff           call 0x68bf00
// 0068dbcf  8bce                 mov ecx, esi
// 0068dbd1  e86826faff           call 0x63023e
// 0068dbd6  8b16                 mov edx, dword ptr [esi]
// 0068dbd8  8bf8                 mov edi, eax
// 0068dbda  8b823c010000         mov eax, dword ptr [edx + 0x13c]
// 0068dbe0  8bce                 mov ecx, esi
// 0068dbe2  ffd0                 call eax
// 0068dbe4  8bc7                 mov eax, edi
// 0068dbe6  5f                   pop edi
// 0068dbe7  5e                   pop esi
// 0068dbe8  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnMDIDestroy@CXTPTabClientWnd@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
