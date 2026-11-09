// roc 2011-06 00977074  unit: seg_00970000  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00977074
//
// 00977074  b8266f9700           mov eax, 0x976f26
// 00977079  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00977074()
{
    return &G;
}
