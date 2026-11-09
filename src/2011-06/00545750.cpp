// from server: 100% by atomic.potato
extern "C" int (__cdecl *isdigit)(int);

int ParseError_00545750(unsigned char c)
{
    return isdigit((int)c) != 0;
}
