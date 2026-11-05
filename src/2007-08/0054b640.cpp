// from server: 33% by colin
struct S_func_0054b640 {
    void* m_handle;
    int f(int a1, int a2);
};

extern "C" int __stdcall InternetQueryDataAvailable(void*, unsigned long*, unsigned long, unsigned long);
extern "C" int __stdcall InternetReadFile(void*, void*, unsigned long, unsigned long*);
extern "C" void* __stdcall sub_77E698(const char*);
extern "C" void __stdcall sub_412DC0(void*, void*);
extern "C" void __stdcall sub_630B9E(void*, void*);

int S_func_0054b640::f(int a1, int a2)
{
    unsigned long avail = 0;
    unsigned long read = 0;
    char buf[64];

    if (!InternetQueryDataAvailable(m_handle, &avail, 0, 0))
        return -1;
    if (avail == 0)
        return -1;

    if (!InternetReadFile(m_handle, buf, a1, &read))
    {
        sub_77E698("InternetReadFile failed");
        sub_412DC0(buf, &avail);
        sub_630B9E(buf, (void*)0x8410C0);
    }

    return (int)read;
}
