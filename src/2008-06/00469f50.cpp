// from server: 100% by king_originala
int __cdecl func_00469f50(const unsigned char* keys)
{
    int result = 0;
    if (keys[0x2a] & 0x80)
        result = 1;
    if (keys[0x36] & 0x80)
        result |= 2;
    if (keys[0x1d] & 0x80)
        result |= 0x40;
    if (keys[0x9d] & 0x80)
        result |= 0x80;
    if (keys[0x38] & 0x80)
        result |= 0x100;
    if (keys[0x38] & 0x80)
        result |= 0x200;
    return result;
}
