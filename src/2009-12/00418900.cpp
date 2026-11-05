// from server: 100% by auto
// roc 2009-12 00418900  unit: RBX::VTool::?$FactoryProduct::Creator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00418900
//
// 00418900  56                   push esi
// 00418901  8bf1                 mov esi, ecx
// 00418903  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00418907  890e                 mov dword ptr [esi], ecx
// 00418909  c6460400             mov byte ptr [esi + 4], 0
// 0041890d  e87effffff           call 0x418890
// 00418912  c6460401             mov byte ptr [esi + 4], 1
// 00418916  8bc6                 mov eax, esi
// 00418918  5e                   pop esi
// 00418919  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??0?$unique_lock@Vmutex@boost@@@boost@@QAE@AAVmutex@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
