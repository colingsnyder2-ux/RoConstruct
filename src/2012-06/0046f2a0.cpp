// from server: 100% by auto
// roc 2012-06 0046f2a0  unit: CRobloxModule  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046f2a0
//
// 0046f2a0  e82d315100           call 0x9823d2
// 0046f2a5  8b4034               mov eax, dword ptr [eax + 0x34]
// 0046f2a8  c3                   ret 
// library rbx2016-g3d/BinaryInput.cpp (function ?machineEndian@System@G3D@@SA?AW4G3DEndian@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryInput.cpp
