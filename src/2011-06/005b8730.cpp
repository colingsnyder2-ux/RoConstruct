// from server: 50% by atomic.potato
extern "C" void __cdecl f401610(const char*, const char*, int);
extern "C" void f5b8600(void*);

struct GlobalAdvancedSettings
{
    int f();
};

int GlobalAdvancedSettings::f()
{
    int value = 0;
    f401610("tUVW", (const char*)0x00cbe0e8, 0);
    f5b8600(this);
    return value;
}
