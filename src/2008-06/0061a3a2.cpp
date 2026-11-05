// roc 2008-06 0061a3a2  unit: RBX::InletTool  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0061a3a2
//
// 0061a3a2  b883a36100           mov eax, 0x61a383
// 0061a3a7  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0061a3a2()
{
    return &G;
}
