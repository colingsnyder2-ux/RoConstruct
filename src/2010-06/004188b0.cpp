// from server: 100% by auto
// roc 2010-06 004188b0  unit: RBX::VTool::?$FactoryProduct::Creator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004188b0
//
// 004188b0  56                   push esi
// 004188b1  8bf1                 mov esi, ecx
// 004188b3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004188b7  890e                 mov dword ptr [esi], ecx
// 004188b9  c6460400             mov byte ptr [esi + 4], 0
// 004188bd  e87effffff           call 0x418840
// 004188c2  c6460401             mov byte ptr [esi + 4], 1
// 004188c6  8bc6                 mov eax, esi
// 004188c8  5e                   pop esi
// 004188c9  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??0?$unique_lock@Vmutex@boost@@@boost@@QAE@AAVmutex@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
