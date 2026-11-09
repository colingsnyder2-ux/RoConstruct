// from server: 100% by auto
// roc 2007-03 00625b70  unit: seg_00620000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00625b70
//
// 00625b70  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00625b74  8b542408             mov edx, dword ptr [esp + 8]
// 00625b78  8b4904               mov ecx, dword ptr [ecx + 4]
// 00625b7b  50                   push eax
// 00625b7c  8b442408             mov eax, dword ptr [esp + 8]
// 00625b80  52                   push edx
// 00625b81  50                   push eax
// 00625b82  51                   push ecx
// 00625b83  ff1504d17700         call dword ptr [0x77d104]
// 00625b89  c20c00               ret 0xc
// library mfc-8.0/atlmfc\src\mfc\bardock.cpp (function ?AppendMenuA@CMenu@@QAEHIIPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/bardock.cpp
