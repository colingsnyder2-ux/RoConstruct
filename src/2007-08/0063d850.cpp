// from server: 100% by auto
// roc 2007-08 0063d850  unit: CXTPPaintManager  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0063d850
//
// 0063d850  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0063d854  8b542408             mov edx, dword ptr [esp + 8]
// 0063d858  8b4904               mov ecx, dword ptr [ecx + 4]
// 0063d85b  50                   push eax
// 0063d85c  8b442408             mov eax, dword ptr [esp + 8]
// 0063d860  52                   push edx
// 0063d861  50                   push eax
// 0063d862  51                   push ecx
// 0063d863  ff1530d17700         call dword ptr [0x77d130]
// 0063d869  c20c00               ret 0xc
// library mfc-8.0/atlmfc\src\mfc\bardock.cpp (function ?AppendMenuA@CMenu@@QAEHIIPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/bardock.cpp
