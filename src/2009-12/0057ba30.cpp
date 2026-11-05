// from server: 100% by auto
// roc 2009-12 0057ba30  unit: RBX::VCylinderMesh::?$FactoryProduct::Creator  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057ba30
//
// 0057ba30  8bc1                 mov eax, ecx
// 0057ba32  c70000000000         mov dword ptr [eax], 0
// 0057ba38  c7400400000000       mov dword ptr [eax + 4], 0
// 0057ba3f  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\ctlnownd.cpp (function ??0CGdiObject@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlnownd.cpp
