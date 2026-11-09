// roc 2012-06 008bcc1e  unit: RBX::AsyncHttpQueue  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008bcc1e
//
// 008bcc1e  b824cc8b00           mov eax, 0x8bcc24
// 008bcc23  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_008bcc1e()
{
    return &G;
}
