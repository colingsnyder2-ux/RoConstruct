// roc 2012-06 00991ec0  unit: CPatchedControlComboBox  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00991ec0
//
// 00991ec0  b810dfc000           mov eax, 0xc0df10
// 00991ec5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00991ec0()
{
    return &G;
}
