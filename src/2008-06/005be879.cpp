// roc 2008-06 005be879  unit: RBX::Soundscape::SoundService  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005be879
//
// 005be879  b87fe85b00           mov eax, 0x5be87f
// 005be87e  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_005be879()
{
    return &G;
}
