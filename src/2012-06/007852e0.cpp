// from server: 33% by atomic.potato
// roc 2012-06 007852e0  unit: RBX::W4WaterCellDirection::?$EnumDesc  size: 307 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007852e0

extern "C" void __stdcall sub_4015a0(void*, void*);
extern "C" void __stdcall sub_9831f5(void*);
extern "C" void __stdcall sub_6d31d0(void*, void*);
extern "C" void __stdcall sub_511180(void*);
extern "C" void __stdcall sub_40c3d0(void*);
extern "C" void __stdcall sub_40cb30(void*, void*, void*);
extern "C" void __stdcall sub_413360(void*, void*);

struct S {
    void f();
};

void S::f() {
    int* self = (int*)this;
    if (*self == 0) return;

    int local10 = 0;
    int local14 = -1;
    int local18 = -1;
    int local1c = 0x7fffffff;

    while (*self != 0) {
        sub_4015a0((void*)0xe39acc, (void*)0x77b080);

        if ((*(unsigned char*)0xe39ac8 & 1) == 0) {
            *(unsigned int*)0xe39ac8 |= 1;
            *(unsigned int*)0xe39ac0 = 0;
            *(unsigned int*)0xe39ac4 = 0;
            sub_9831f5((void*)0xb18d00);
        }

        sub_40cb30((void*)0xe39ac0, &local18, &local14);

        sub_413360((void*)0xe39ac0, &local10);

        int count = 10;
        int* p = (int*)local10;
        while (p != 0) {
            p[4] = 0;
            if (--count == 0) break;
            p = (int*)((char*)p + 0xc);
            sub_6d31d0(&local10, p);
            p = (int*)local10;
        }

        sub_40c3d0(&local1c);

        sub_6d31d0(self, &local10);

        sub_511180(&local10);
    }
}
