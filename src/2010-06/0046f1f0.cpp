// from server: 53% by atomic.potato
extern "C" int GetWindowHandle();

extern "C" long __stdcall SendMessageA(int, unsigned int, unsigned int, long);

struct S
{
    char pad[0x19c];
    int value;

    void f();
};

void S::f()
{
    int h = *(int *)((char *)GetWindowHandle() + 0x20);
    value = SendMessageA(h, 0x412, 0, 0xf0) != 0;
}
