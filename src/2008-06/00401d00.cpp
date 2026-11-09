// from server: 100% by auto
// roc 2008-06 00401d00  unit: VCWorkspace::?$CComObject  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401d00
//
// 00401d00  56                   push esi
// 00401d01  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00401d05  57                   push edi
// 00401d06  8bf9                 mov edi, ecx
// 00401d08  85f6                 test esi, esi
// 00401d0a  7508                 jne 0x401d14
// 00401d0c  5f                   pop edi
// 00401d0d  8d460d               lea eax, [esi + 0xd]
// 00401d10  5e                   pop esi
// 00401d11  c20c00               ret 0xc
// 00401d14  56                   push esi
// 00401d15  ff15b8218000         call dword ptr [0x8021b8]
// 00401d1b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00401d1f  8b17                 mov edx, dword ptr [edi]
// 00401d21  40                   inc eax
// 00401d22  50                   push eax
// 00401d23  8b442418             mov eax, dword ptr [esp + 0x18]
// 00401d27  56                   push esi
// 00401d28  50                   push eax
// 00401d29  6a00                 push 0
// 00401d2b  51                   push ecx
// 00401d2c  52                   push edx
// 00401d2d  ff1514208000         call dword ptr [0x802014]
// 00401d33  5f                   pop edi
// 00401d34  5e                   pop esi
// 00401d35  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?SetStringValue@CRegKey@ATL@@QAEJPBD0K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
