// from server: 83% by atomic.potato
extern "C" int GetDlgItem(void*, int);
extern "C" long __stdcall SendMessageA(int, unsigned int, unsigned int, long);

struct S
{
    char padding[0x19c];
    int value;
    int f();
};

int S::f()
{
    int h = GetDlgItem(this, 0x412);
    value = SendMessageA(h, 0xf0, 0, 0) == 0;
    return value;
}
