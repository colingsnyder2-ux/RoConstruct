// roc 2012-06 005d8a70  unit: RBX::VCylinderMesh::?$FactoryProduct::Creator  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005d8a70
//
// 005d8a70  b8e6885d00           mov eax, 0x5d88e6
// 005d8a75  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_005d8a70()
{
    return &G;
}
