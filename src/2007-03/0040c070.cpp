// from server: 100% by auto
// roc 2007-03 0040c070  unit: seg_00400000  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0040c070
//
// 0040c070  8b442410             mov eax, dword ptr [esp + 0x10]
// 0040c074  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0040c078  50                   push eax
// 0040c079  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040c07d  52                   push edx
// 0040c07e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0040c082  50                   push eax
// 0040c083  52                   push edx
// 0040c084  8b542424             mov edx, dword ptr [esp + 0x24]
// 0040c088  83ec10               sub esp, 0x10
// 0040c08b  8bc4                 mov eax, esp
// 0040c08d  8910                 mov dword ptr [eax], edx
// 0040c08f  8b542438             mov edx, dword ptr [esp + 0x38]
// 0040c093  895004               mov dword ptr [eax + 4], edx
// 0040c096  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0040c09a  895008               mov dword ptr [eax + 8], edx
// 0040c09d  8b542440             mov edx, dword ptr [esp + 0x40]
// 0040c0a1  89500c               mov dword ptr [eax + 0xc], edx
// 0040c0a4  e8bd252100           call 0x61e666
// 0040c0a9  c22000               ret 0x20
// library mfc-8.0/atlmfc\src\mfc\viewform.cpp (function ?accLocation@CFormView@@UAEJPAJ000UtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewform.cpp
