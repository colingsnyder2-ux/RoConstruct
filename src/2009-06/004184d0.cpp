// from server: 100% by auto
// roc 2009-06 004184d0  unit: RBX::VTool::?$FactoryProduct::Creator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004184d0
//
// 004184d0  56                   push esi
// 004184d1  8bf1                 mov esi, ecx
// 004184d3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004184d7  890e                 mov dword ptr [esi], ecx
// 004184d9  c6460400             mov byte ptr [esi + 4], 0
// 004184dd  e87effffff           call 0x418460
// 004184e2  c6460401             mov byte ptr [esi + 4], 1
// 004184e6  8bc6                 mov eax, esi
// 004184e8  5e                   pop esi
// 004184e9  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??0?$unique_lock@Vmutex@boost@@@boost@@QAE@AAVmutex@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
