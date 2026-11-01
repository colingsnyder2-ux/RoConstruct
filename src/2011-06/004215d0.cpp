// from server: 100% by tester
extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*, ...);

extern const char ATL_FMT[];
extern int (__stdcall *sprintf_s_ptr)(char*, unsigned int, const char*, ...);

int __cdecl sub_00413760(char* buf, unsigned int size, const char* fmt, ...)
{
    return sprintf_s_ptr(buf, size, ATL_FMT, fmt);
}
