// from server: 63% by atomic.potato
struct CRobloxApp
{
    bool f(void* a, void* b, void* c, void* d);
};

extern "C" void __stdcall _invalid_parameter_noinfo(void);

extern "C" int __cdecl sub_44a230(void* a, void* b, void* c, void* d);

bool CRobloxApp::f(void* a, void* b, void* c, void* d)
{
    int result = sub_44a230(a, b, c, d);
    if (a != 0 && a != d)
    {
        _invalid_parameter_noinfo();
    }
    return result == (int)d;
}
