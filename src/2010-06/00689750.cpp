// from server: 37% by atomic.potato
struct Inner {
    char pad[0x58];
};

struct Outer {
    int field0;
    Inner field4;
    int method(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
};

extern "C" void __stdcall sub_682890(void*);
extern "C" void __stdcall sub_687E00();
extern "C" void __stdcall sub_67ECF0();

int Outer::method(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int)
{
    Inner local;
    sub_682890(&local);
    sub_687E00();
    sub_67ECF0();
    return 0;
}
