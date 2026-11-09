// from server: 30% by atomic.potato
void func_005b3580()
{
    volatile unsigned char* p = (volatile unsigned char*)0;
    *p = (unsigned char)((*p << 1) | (*p >> 7));
    if ((unsigned char)*p > 0)
        *p = (unsigned char)(*p + 1);
}
