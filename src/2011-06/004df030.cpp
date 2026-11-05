// from server: 42% by atomic.potato
extern "C" int __cdecl sub_004def90(int);

extern "C" void __cdecl _exit(int);

struct CrashReporter
{
    void f(int a1);
};

void CrashReporter::f(int a1)
{
    sub_004def90(a1);
    _exit(1);
}
