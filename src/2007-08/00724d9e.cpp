// from server: 100% by EspClaude
// roc 2007-08 00724d9e  unit: CXTIconHandle  size: 101 bytes
// roc-flags: /O1 /GS /EHsc /MD
// Free helper: default ANSI code page of the thread locale (LOCALE_IDEFAULTANSICODEPAGE = 0x1004, 7 chars).
extern "C" __declspec(dllimport) unsigned int __stdcall GetACP();
extern "C" __declspec(dllimport) int __stdcall GetLocaleInfoA(unsigned long Locale, unsigned long LCType, char* lpLCData, int cchData);
extern "C" __declspec(dllimport) unsigned long __stdcall GetThreadLocale();

unsigned int GetLocaleCodePage()
{
    char buf[7];
    unsigned int cp = 0;
    unsigned long lcid = GetThreadLocale();
    if (GetLocaleInfoA(lcid, 0x1004, buf, 7))
    {
        for (char* p = buf; *p; p++)
            cp = cp * 10 + *p - '0';
    }
    if (cp == 0)
        cp = GetACP();
    return cp;
}
