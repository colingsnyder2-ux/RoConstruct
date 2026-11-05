// from server: 100% by auto
// roc 2012-06 004242d0  unit: RBX::DSVideoCaptureEngine  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004242d0
//
// 004242d0  56                   push esi
// 004242d1  8bf1                 mov esi, ecx
// 004242d3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004242d7  890e                 mov dword ptr [esi], ecx
// 004242d9  c6460400             mov byte ptr [esi + 4], 0
// 004242dd  e87effffff           call 0x424260
// 004242e2  c6460401             mov byte ptr [esi + 4], 1
// 004242e6  8bc6                 mov eax, esi
// 004242e8  5e                   pop esi
// 004242e9  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??0?$unique_lock@Vmutex@boost@@@boost@@QAE@AAVmutex@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
