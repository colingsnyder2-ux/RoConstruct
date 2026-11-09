// from server: 44% by atomic.potato
extern "C" void __stdcall _exit(int);

extern "C" int __cdecl sub_004d28b0(int);

struct CrashReporter
{
    void f(int);
};

void CrashReporter::f(int a1)
{
    int value = sub_004d28b0(a1);
    (void)value;
    _exit(1);
}
