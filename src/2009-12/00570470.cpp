// from server: 100% by auto
// roc 2009-12 00570470  unit: CSHA1  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00570470
//
// 00570470  8bc1                 mov eax, ecx
// 00570472  c6401800             mov byte ptr [eax + 0x18], 0
// 00570476  c3                   ret 
// library ogre-1.7.0/OgreProgressiveMesh.cpp (function ??0PMTriangle@ProgressiveMesh@Ogre@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreProgressiveMesh.cpp
