// from server: 19% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

struct EventInvocationItem {
    char pad0[0x38];
    int field38;
    int method(int, int, int, int);
};

int EventInvocationItem::method(int a, int b, int c, int d)
{
    int result = 0;
    if (a == 0) {
        InterlockedIncrement((long volatile*)0xc007a8);
        *(int*)b = 0;
        *(int*)(b + 4) = 0;
        return result;
    }
    char buf[0x20];
    *(int*)buf = 0;
    int* src = (int*)d;
    int v = *src;
    if (v != 0) {
        *(int*)buf = v;
        int* p = (int*)*src;
        int (*fn)(int*, int*, int) = *(int (**)(int*, int*, int))p;
        fn((int*)((char*)src + 8), (int*)(buf + 8), 0);
    }
    int e = *(int*)((char*)&a + 0x40);
    int f = *(int*)((char*)&a + 0x34);
    return ((int (*)(int, int, int))0x4fa0e0)(field38 + (a - 0x1c), f, e);
}
