// from server: 100% by auto
// roc 2011-06 004206d0  unit: RBX::DSVideoCaptureEngine  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004206d0
//
// 004206d0  56                   push esi
// 004206d1  8bf1                 mov esi, ecx
// 004206d3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004206d7  890e                 mov dword ptr [esi], ecx
// 004206d9  c6460400             mov byte ptr [esi + 4], 0
// 004206dd  e87effffff           call 0x420660
// 004206e2  c6460401             mov byte ptr [esi + 4], 1
// 004206e6  8bc6                 mov eax, esi
// 004206e8  5e                   pop esi
// 004206e9  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??0?$unique_lock@Vmutex@boost@@@boost@@QAE@AAVmutex@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
