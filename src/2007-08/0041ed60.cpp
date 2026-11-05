// from server: 100% by auto
// roc 2007-08 0041ed60  unit: CSettingsExplorer  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041ed60
//
// 0041ed60  56                   push esi
// 0041ed61  8bf1                 mov esi, ecx
// 0041ed63  837e2800             cmp dword ptr [esi + 0x28], 0
// 0041ed67  7514                 jne 0x41ed7d
// 0041ed69  6858827800           push 0x788258
// 0041ed6e  e89dffffff           call 0x41ed10
// 0041ed73  50                   push eax
// 0041ed74  ff1588d27700         call dword ptr [0x77d288]
// 0041ed7a  894628               mov dword ptr [esi + 0x28], eax
// 0041ed7d  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 0041ed80  8b442408             mov eax, dword ptr [esp + 8]
// 0041ed84  8908                 mov dword ptr [eax], ecx
// 0041ed86  5e                   pop esi
// 0041ed87  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxtaskspane.cpp (function ?GetProcAddress_ImageList_Add@CComCtlWrapper@@QAE?AUImageList_Add_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtaskspane.cpp
