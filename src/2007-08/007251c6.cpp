// from server: 100% by colin
// roc 2007-08 007251c6  unit: CXTIconHandle  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 007251c6
//
// 007251c6  33d2                 xor edx, edx
// 007251c8  8d4114               lea eax, [ecx + 0x14]
// 007251cb  42                   inc edx
// 007251cc  f00fc110             lock xadd dword ptr [eax], edx
// 007251d0  8d4108               lea eax, [ecx + 8]
// 007251d3  c3                   ret 
// copied from an identical function in another client (function ?GetNilString@CAtlStringMgr@ATL@@UAEPAUCStringData@2@XZ)

// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm atls.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/atl/atls/staticrelease/obj1r/i386/atlstr.obj