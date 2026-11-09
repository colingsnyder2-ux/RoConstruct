// roc 2012-06 007644f0  unit: RBX::VExplosion::?$EventDesc  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007644f0
//
// 007644f0  b8c075e300           mov eax, 0xe375c0
// 007644f5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_007644f0()
{
    return &G;
}
