// roc 2012-06 00a7bdf6  unit: CXTIconHandle  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a7bdf6
//
// 00a7bdf6  8bff                 mov edi, edi
// 00a7bdf8  55                   push ebp
// 00a7bdf9  8bec                 mov ebp, esp
// 00a7bdfb  8b4904               mov ecx, dword ptr [ecx + 4]
// 00a7bdfe  8b01                 mov eax, dword ptr [ecx]
// 00a7be00  5d                   pop ebp
// 00a7be01  ff6004               jmp dword ptr [eax + 4]
// copied from an identical function in another client (function ?Free@CAtlStringMgr@ATL@@UAEXPAUCStringData@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm atls.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/atl/atls/staticrelease/obj1r/i386/atlstr.obj