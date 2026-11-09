// roc 2012-06 00a7be04  unit: CXTIconHandle  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a7be04
//
// 00a7be04  33d2                 xor edx, edx
// 00a7be06  8d4114               lea eax, [ecx + 0x14]
// 00a7be09  42                   inc edx
// 00a7be0a  f00fc110             lock xadd dword ptr [eax], edx
// 00a7be0e  8d4108               lea eax, [ecx + 8]
// 00a7be11  c3                   ret 
// copied from an identical function in another client (function ?GetNilString@CAtlStringMgr@ATL@@UAEPAUCStringData@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm atls.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/atl/atls/staticrelease/obj1r/i386/atlstr.obj