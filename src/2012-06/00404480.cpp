// from server: 100% by auto
// roc 2012-06 00404480  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct::Creator  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00404480
//
// 00404480  56                   push esi
// 00404481  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00404485  57                   push edi
// 00404486  8bf9                 mov edi, ecx
// 00404488  85f6                 test esi, esi
// 0040448a  7508                 jne 0x404494
// 0040448c  5f                   pop edi
// 0040448d  8d460d               lea eax, [esi + 0xd]
// 00404490  5e                   pop esi
// 00404491  c20c00               ret 0xc
// 00404494  56                   push esi
// 00404495  ff15a821b200         call dword ptr [0xb221a8]
// 0040449b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0040449f  8b17                 mov edx, dword ptr [edi]
// 004044a1  40                   inc eax
// 004044a2  50                   push eax
// 004044a3  8b442418             mov eax, dword ptr [esp + 0x18]
// 004044a7  56                   push esi
// 004044a8  50                   push eax
// 004044a9  6a00                 push 0
// 004044ab  51                   push ecx
// 004044ac  52                   push edx
// 004044ad  ff151020b200         call dword ptr [0xb22010]
// 004044b3  5f                   pop edi
// 004044b4  5e                   pop esi
// 004044b5  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?SetStringValue@CRegKey@ATL@@QAEJPBD0K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
