// roc 2008-06 005be661  unit: RBX::Soundscape::SoundService  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005be661
//
// 005be661  b867e65b00           mov eax, 0x5be667
// 005be666  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_005be661()
{
    return &G;
}
