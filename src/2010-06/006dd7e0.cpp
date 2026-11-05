// from server: 57% by atomic.potato
extern "C" int CallTarget(void*, int);
extern "C" void ProcessTarget(void*, int);

struct S
{
    int value;
    int offset;
    int (__cdecl *callback)(void*, int);
    int f(int, int);
};

int S::f(int unused, int value)
{
    int adjusted = value ? value - 28 : 0;
    int result = callback(this, offset + adjusted);
    ProcessTarget((void*)value, result);
    return value;
}
