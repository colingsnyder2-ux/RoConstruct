// roc 2012-06 006e01eb  unit: RBX::VFunctionalTest::?$FactoryProduct::Creator  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006e01eb
//
// 006e01eb  b8f1016e00           mov eax, 0x6e01f1
// 006e01f0  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_006e01eb()
{
    return &G;
}
