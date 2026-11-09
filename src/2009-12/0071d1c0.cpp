// from server: 100% by auto
// roc 2009-12 0071d1c0  unit: RBX::VDataModelMesh::?$NonFactoryProduct  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0071d1c0
//
// 0071d1c0  8b542408             mov edx, dword ptr [esp + 8]
// 0071d1c4  8bc1                 mov eax, ecx
// 0071d1c6  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0071d1ca  8908                 mov dword ptr [eax], ecx
// 0071d1cc  895004               mov dword ptr [eax + 4], edx
// 0071d1cf  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ??0CPoint@@QAE@HH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
