// from server: 100% by auto
// roc 2009-12 0044d930  unit: CRobloxModule  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0044d930
//
// 0044d930  e8e9613a00           call 0x7f3b1e
// 0044d935  8b4034               mov eax, dword ptr [eax + 0x34]
// 0044d938  c3                   ret 
// library rbx2016-g3d/BinaryInput.cpp (function ?machineEndian@System@G3D@@SA?AW4G3DEndian@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d BinaryInput.cpp
