// from server: 64% by atomic.potato
typedef unsigned int DWORD;

extern "C" int __cdecl Function401610(const char *, const char *, DWORD);
extern "C" int __cdecl Function5b8760();

struct GlobalAdvancedSettings
{
    int f();
};

int GlobalAdvancedSettings::f()
{
    int result = Function401610("tUVW", (const char *)0x00cbe0f8, 0);
    Function5b8760();
    return result;
}
