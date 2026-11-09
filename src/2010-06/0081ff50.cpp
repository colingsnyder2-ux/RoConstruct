// roc 2010-06 0081ff50  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081ff50
//
// 0081ff50  b856ff8100           mov eax, 0x81ff56
// 0081ff55  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0081ff50()
{
    return &G;
}
