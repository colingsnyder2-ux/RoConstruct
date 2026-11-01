// from server: 100% by auto
// roc 2009-12 0057b850  unit: RBX::VCylinderMesh::?$FactoryProduct::Creator  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057b850
//
// 0057b850  8b4908               mov ecx, dword ptr [ecx + 8]
// 0057b853  85c9                 test ecx, ecx
// 0057b855  7413                 je 0x57b86a
// 0057b857  8d4108               lea eax, [ecx + 8]
// 0057b85a  83caff               or edx, 0xffffffff
// 0057b85d  f00fc110             lock xadd dword ptr [eax], edx
// 0057b861  7507                 jne 0x57b86a
// 0057b863  8b01                 mov eax, dword ptr [ecx]
// 0057b865  8b5008               mov edx, dword ptr [eax + 8]
// 0057b868  ffe2                 jmp edx
// 0057b86a  c3                   ret 
// library templates-boost-1_34_1/map_int_wp.cpp (function ??1?$pair@$$CBHV?$weak_ptr@UT@@@boost@@@std@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 map_int_wp.cpp
