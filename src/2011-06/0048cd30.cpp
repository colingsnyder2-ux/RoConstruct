// from server: 100% by auto
// roc 2011-06 0048cd30  unit: Scintilla::CScintillaView  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0048cd30
//
// 0048cd30  83ec18               sub esp, 0x18
// 0048cd33  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048cd37  8b5004               mov edx, dword ptr [eax + 4]
// 0048cd3a  56                   push esi
// 0048cd3b  8bf1                 mov esi, ecx
// 0048cd3d  8b08                 mov ecx, dword ptr [eax]
// 0048cd3f  8d44240c             lea eax, [esp + 0xc]
// 0048cd43  894c2404             mov dword ptr [esp + 4], ecx
// 0048cd47  50                   push eax
// 0048cd48  8d4c2408             lea ecx, [esp + 8]
// 0048cd4c  8954240c             mov dword ptr [esp + 0xc], edx
// 0048cd50  e8cbe9ffff           call 0x48b720
// 0048cd55  84c0                 test al, al
// 0048cd57  7420                 je 0x48cd79
// 0048cd59  8d4c240c             lea ecx, [esp + 0xc]
// 0048cd5d  56                   push esi
// 0048cd5e  51                   push ecx
// 0048cd5f  e80ce9ffff           call 0x48b670
// 0048cd64  83c408               add esp, 8
// 0048cd67  85c0                 test eax, eax
// 0048cd69  740e                 je 0x48cd79
// 0048cd6b  33c0                 xor eax, eax
// 0048cd6d  894608               mov dword ptr [esi + 8], eax
// 0048cd70  8bc6                 mov eax, esi
// 0048cd72  5e                   pop esi
// 0048cd73  83c418               add esp, 0x18
// 0048cd76  c20400               ret 4
// 0048cd79  b801000000           mov eax, 1
// 0048cd7e  894608               mov dword ptr [esi + 8], eax
// 0048cd81  8bc6                 mov eax, esi
// 0048cd83  5e                   pop esi
// 0048cd84  83c418               add esp, 0x18
// 0048cd87  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxshelllistctrl.cpp (function ??4COleDateTime@ATL@@QAEAAV01@AB_J@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxshelllistctrl.cpp
