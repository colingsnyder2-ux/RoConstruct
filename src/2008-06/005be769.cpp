// roc 2008-06 005be769  unit: RBX::Soundscape::SoundService  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005be769
//
// 005be769  b86fe75b00           mov eax, 0x5be76f
// 005be76e  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_005be769()
{
    return &G;
}
