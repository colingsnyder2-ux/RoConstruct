// from server: 85% by atomic.potato
typedef unsigned long DWORD;
typedef int BOOL;

extern "C" BOOL __stdcall PostMessageA(void*, unsigned int, unsigned int, long);

struct HelpCommand
{
    int f(int);
    int pad0[3];
    int value;
};

int HelpCommand::f(int)
{
    PostMessageA((void*)value, 0x111, 0x80fd, 0);
    return 0;
}
