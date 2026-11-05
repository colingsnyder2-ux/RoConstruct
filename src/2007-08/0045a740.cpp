// from server: 29% by colin
struct S {
    char pad0[0x54];
    int f54;
    int f58;
    char pad5c[0x68 - 0x5c];
    int f68;
    char pad6c[0x79 - 0x6c];
    char f79;
    char pad7a[0xa0 - 0x7a];
    int fa0;
    void method(int);
};

extern "C" int __stdcall sub_450EC0(int);
extern "C" int __stdcall sub_52DCE0(int, void*);
extern "C" void __stdcall sub_45A5D0(int);
extern "C" void __stdcall glClearColor(float, float, float, float);
extern "C" void __stdcall glClear(unsigned int);

void S::method(int arg)
{
    if (f79 != 0)
        return;

    char old = f79;
    f79 = 1;

    if (f68 == 0) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(0x4100);
    } else if (fa0 == 0) {
        int r = sub_450EC0(f68);
        if (r != 0)
            sub_52DCE0(r, &f54);
    } else if (f58 == 2) {
        sub_45A5D0(arg);
    }

    f79 = old;
}
