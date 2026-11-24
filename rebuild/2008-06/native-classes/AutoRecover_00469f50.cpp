// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: arg type unknown; raw byte offsets used, flag bits all test 0x80.
extern "C" unsigned int fn_00469f50(const unsigned char* p)
{
    unsigned int r = 0;
    if (p[0x2a] & 0x80) r = 1;
    if (p[0x36] & 0x80) r |= 2;
    if (p[0x1d] & 0x80) r |= 0x40;
    if (p[0x9d] & 0x80) r |= 0x80;
    unsigned char m = p[0x38] & 0x80;
    if (m) r |= 0x100;
    if (m) r |= 0x200;
    return r;
}
