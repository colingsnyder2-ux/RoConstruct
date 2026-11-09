// roc 2012-06 00a7b948  unit: CXTIconHandle  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a7b948
//
// 00a7b948  8bff                 mov edi, edi
// 00a7b94a  56                   push esi
// 00a7b94b  8bf1                 mov esi, ecx
// 00a7b94d  8b06                 mov eax, dword ptr [esi]
// 00a7b94f  85c0                 test eax, eax
// 00a7b951  740a                 je 0xa7b95d
// 00a7b953  50                   push eax
// 00a7b954  e88777f0ff           call 0x9830e0
// 00a7b959  832600               and dword ptr [esi], 0
// 00a7b95c  59                   pop ecx
// 00a7b95d  83660400             and dword ptr [esi + 4], 0
// 00a7b961  83660800             and dword ptr [esi + 8], 0
// 00a7b965  5e                   pop esi
// 00a7b966  c3                   ret 
// copied from an identical function in another client (function ?RemoveAll@?$CSimpleArray@UCModuleInfo@CTraceSnapshot@@V?$CSimpleArrayEqualHelper@UCModuleInfo@CTraceSnapshot@@@ATL@@@ATL@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm atls.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/atl/atls/staticrelease/obj1r/i386/Externs.obj