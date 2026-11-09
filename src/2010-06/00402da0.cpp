// from server: 100% by atomic.potato
typedef void *HANDLE;
typedef unsigned long DWORD;
typedef int BOOL;

extern "C" HANDLE __declspec(dllimport) __stdcall OpenEventA(DWORD, BOOL, const char *);

struct S
{
    HANDLE value;
    int f(DWORD access, DWORD inherit, const char *name);
};

int S::f(DWORD access, DWORD inherit, const char *name)
{
    HANDLE h = OpenEventA(access, inherit, name);
    value = h;
    return h != 0;
}
