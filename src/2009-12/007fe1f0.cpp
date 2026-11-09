// from server: 100% by auto
// roc 2009-12 007fe1f0  unit: CXTPPaintManager  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007fe1f0
//
// 007fe1f0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007fe1f4  8b542408             mov edx, dword ptr [esp + 8]
// 007fe1f8  8b4904               mov ecx, dword ptr [ecx + 4]
// 007fe1fb  50                   push eax
// 007fe1fc  8b442408             mov eax, dword ptr [esp + 8]
// 007fe200  52                   push edx
// 007fe201  50                   push eax
// 007fe202  51                   push ecx
// 007fe203  ff1514b19800         call dword ptr [0x98b114]
// 007fe209  c20c00               ret 0xc
// library mfc-8.0/atlmfc\src\mfc\bardock.cpp (function ?AppendMenuA@CMenu@@QAEHIIPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/bardock.cpp
