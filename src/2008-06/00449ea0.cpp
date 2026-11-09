// from server: 100% by auto
// roc 2008-06 00449ea0  unit: CIDEDocManager  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00449ea0
//
// 00449ea0  56                   push esi
// 00449ea1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00449ea5  57                   push edi
// 00449ea6  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00449eaa  8b07                 mov eax, dword ptr [edi]
// 00449eac  8d542414             lea edx, [esp + 0x14]
// 00449eb0  52                   push edx
// 00449eb1  8b542410             mov edx, dword ptr [esp + 0x10]
// 00449eb5  56                   push esi
// 00449eb6  8944241c             mov dword ptr [esp + 0x1c], eax
// 00449eba  8d442418             lea eax, [esp + 0x18]
// 00449ebe  50                   push eax
// 00449ebf  6a00                 push 0
// 00449ec1  c70700000000         mov dword ptr [edi], 0
// 00449ec7  8b01                 mov eax, dword ptr [ecx]
// 00449ec9  52                   push edx
// 00449eca  50                   push eax
// 00449ecb  ff1520208000         call dword ptr [0x802020]
// 00449ed1  85c0                 test eax, eax
// 00449ed3  7532                 jne 0x449f07
// 00449ed5  8b442410             mov eax, dword ptr [esp + 0x10]
// 00449ed9  83f801               cmp eax, 1
// 00449edc  7405                 je 0x449ee3
// 00449ede  83f802               cmp eax, 2
// 00449ee1  7513                 jne 0x449ef6
// 00449ee3  8b442414             mov eax, dword ptr [esp + 0x14]
// 00449ee7  85f6                 test esi, esi
// 00449ee9  7418                 je 0x449f03
// 00449eeb  85c0                 test eax, eax
// 00449eed  7411                 je 0x449f00
// 00449eef  807c30ff00           cmp byte ptr [eax + esi - 1], 0
// 00449ef4  740d                 je 0x449f03
// 00449ef6  5f                   pop edi
// 00449ef7  b80d000000           mov eax, 0xd
// 00449efc  5e                   pop esi
// 00449efd  c20c00               ret 0xc
// 00449f00  c60600               mov byte ptr [esi], 0
// 00449f03  8907                 mov dword ptr [edi], eax
// 00449f05  33c0                 xor eax, eax
// 00449f07  5f                   pop edi
// 00449f08  5e                   pop esi
// 00449f09  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?QueryStringValue@CRegKey@ATL@@QAEJPBDPADPAK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
