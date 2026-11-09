// from server: 100% by atomic.potato
struct PingBackItem {
    char pad[0x20];
    int field20;
    bool f(int);
};

extern "C" void __cdecl sub_5aaf90(int, int);
extern "C" void* __cdecl sub_56b920(void*, bool);
extern "C" void __cdecl sub_56c250(void*, void*);

bool PingBackItem::f(int a) {
    sub_5aaf90(a, 6);
    sub_56b920((void*)a, true);
    sub_56c250((void*)a, &field20);
    return true;
}
