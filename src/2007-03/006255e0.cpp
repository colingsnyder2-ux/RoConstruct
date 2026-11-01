// from server: 100% by auto
// roc 2007-03 006255e0  unit: seg_00620000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006255e0
//
// 006255e0  56                   push esi
// 006255e1  8bf1                 mov esi, ecx
// 006255e3  837e2000             cmp dword ptr [esi + 0x20], 0
// 006255e7  7514                 jne 0x6255fd
// 006255e9  6860337c00           push 0x7c3360
// 006255ee  e8bdb2dfff           call 0x4208b0
// 006255f3  50                   push eax
// 006255f4  ff1544d27700         call dword ptr [0x77d244]
// 006255fa  894620               mov dword ptr [esi + 0x20], eax
// 006255fd  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00625600  8b442408             mov eax, dword ptr [esp + 8]
// 00625604  8908                 mov dword ptr [eax], ecx
// 00625606  5e                   pop esi
// 00625607  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxglobalutils.cpp (function ?GetProcAddress_ImageList_GetImageCount@CComCtlWrapper@@QAE?AUImageList_GetImageCount_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobalutils.cpp
