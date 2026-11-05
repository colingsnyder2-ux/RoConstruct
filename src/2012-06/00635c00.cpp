// from server: 100% by tester
extern "C" int (__cdecl *isdigit)(int);

int ParseError_00545750(unsigned char c)
{
    return isdigit((int)c) != 0;
}
