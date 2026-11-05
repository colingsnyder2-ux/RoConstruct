// from server: 41% by atomic.potato
extern "C" int __stdcall func_0080b2ea(int, int, int, int, int);
extern "C" void __stdcall func_0080b0ac(void*, void*);
extern "C" void __stdcall func_005f3a70(int, int, int, int, int);
extern "C" void __stdcall func_00a40a10(void*);

struct S {
    char pad0[0x28];
    int field28;
    int field2c;
    int field30;
    int field34;
    void method(int, int);
};

void S::method(int a, int b) {
    int local8 = field30;
    int localc;
    if (field34) {
        localc = (*(int(__thiscall**)(int))((*(int*)field34) + 8))(field34);
    } else {
        localc = 0;
    }
    int* p = (int*)b;
    (*(void(__thiscall**)(int*, int, int*))((*(int*)p) + 4))(p, 1, &local8);
    int r = func_0080b2ea(localc, 0, 0xc073f8, 0xc17c14, 0);
    if (r == 0) {
        func_00a40a10((void*)0xa5c10c);
        func_0080b0ac((void*)0xb989fc, &local8);
    }
    func_005f3a70(r, field28, field2c, (int)(p + 1), (int)&local8);
    if (localc) {
        (*(void(__thiscall**)(int, int))(*((int*)localc)))(localc, 1);
    }
}
