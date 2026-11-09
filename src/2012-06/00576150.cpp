// from server: 88% by atomic.potato
struct PingItem {
    char pad[0x20];
    bool method(int);
};

extern "C" void __stdcall sub_5aaf90(int, int);
extern "C" void __stdcall sub_56b920(int, int);
extern "C" void __stdcall sub_56c250(int, void*);

bool PingItem::method(int a) {
    sub_5aaf90(a, 5);
    sub_56b920(a, 0);
    sub_56c250(a, this + 0x20);
    return true;
}
