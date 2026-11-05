// from server: 43% by colin
struct S_func_00724d9e {
    int f();
};

extern "C" unsigned long __stdcall GetACP();
extern "C" int __stdcall GetLocaleInfoA(unsigned long Locale, unsigned long LCType, char* lpLCData, int cchData);
extern "C" unsigned long __stdcall GetThreadLocale();

int S_func_00724d9e::f()
{
    char buf[8];
    int result = 0;
    unsigned long acp = GetACP();
    if (GetLocaleInfoA(GetThreadLocale(), 0x1004, buf, 7) != 0)
    {
        char* p = buf;
        char c = *p;
        if (c != 0)
        {
            do
            {
                result = result * 10 + (int)c - 0x30;
                p++;
                c = *p;
            } while (c != 0);
            if (result != 0)
                return result;
        }
    }
    return (int)GetACP();
}
