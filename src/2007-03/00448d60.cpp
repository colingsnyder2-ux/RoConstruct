// from server: 100% by auto
// roc 2007-03 00448d60  unit: seg_00440000  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00448d60
//
// 00448d60  e82b561d00           call 0x61e390
// 00448d65  8b4034               mov eax, dword ptr [eax + 0x34]
// 00448d68  c3                   ret 
// library rbx2016-g3d/BinaryInput.cpp (function ?machineEndian@System@G3D@@SA?AW4G3DEndian@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d BinaryInput.cpp
