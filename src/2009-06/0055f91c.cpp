// roc 2009-06 0055f91c  unit: RBX::WedgeBuilder  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0055f91c
//
// 0055f91c  b831f55500           mov eax, 0x55f531
// 0055f921  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0055f91c()
{
    return &G;
}
