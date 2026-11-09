// roc 2008-06 005be5f1  unit: RBX::Soundscape::SoundService  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005be5f1
//
// 005be5f1  b8f7e55b00           mov eax, 0x5be5f7
// 005be5f6  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_005be5f1()
{
    return &G;
}
