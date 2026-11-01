// from server: 43% by Intel
struct Controller {
    void* f_38;
    char pad_3c[124];
    float f_b8;
    int f_b4;
    char pad_b8[200];
    int f_148;
    char pad_14c[16];
    void* f_15c;
    Controller* base();
    int func(int a1, int a2);
};

extern "C" void __stdcall sub_4a01e0(void* ecx);
extern "C" int __stdcall sub_983448(int a1, int a2, int a3, int a4, int a5);
extern "C" void __stdcall sub_4be3e0(void* ecx);
extern "C" int __stdcall sub_443530();
extern "C" void __stdcall sub_68bbd0(void* ecx, float val);

int Controller::func(int a1, int a2) {
    if (!this)
        return 0;

    void* eax = f_38;
    if (eax) {
        void* ecx = *reinterpret_cast<void**>(reinterpret_cast<char*>(eax) + 0x38);
        if (ecx)
            sub_4a01e0(ecx);
    } else {
        eax = this;
    }

    if (!eax)
        return 0;

    int result = sub_983448(reinterpret_cast<int>(eax), 0, 0xd65108, 0xd601e8, 0);
    if (!result)
        return 0;

    sub_4be3e0(reinterpret_cast<void*>(result));

    int esi;
    {
        void* vtable = *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x150);
        int (__stdcall *fn)(void*) = *reinterpret_cast<int (__stdcall**)(void*)>(reinterpret_cast<char*>(vtable) + 4);
        esi = fn(this);
    }

    int eax2 = sub_443530();
    int eax3 = 0;

    if (*reinterpret_cast<int*>(eax2 + 0x8c) == 3 && *reinterpret_cast<char*>(eax2 + 0x96) == 0) {
        int arg = a1;
        if (*reinterpret_cast<char*>(arg + 6) == 0)
            eax3 = *reinterpret_cast<unsigned char*>(arg + 7);
        else
            eax3 = 1;
    } else {
        int arg = a1;
        if (*reinterpret_cast<char*>(arg + 2) == 0)
            eax3 = *reinterpret_cast<unsigned char*>(arg + 3);
        else
            eax3 = 1;
    }

    eax3 = -eax3;
    eax3 = (eax3 >> 31) & 1;
    *reinterpret_cast<int*>(&a2) = eax3;

    if (f_148 != 6) {
        *reinterpret_cast<int*>(&a2) = 0;
    } else if (!eax3) {
        *reinterpret_cast<int*>(&a2) = 0;
    } else {
        float val = *reinterpret_cast<float*>(a2 + 8);
        val *= f_b8;
        val *= *reinterpret_cast<int*>(&a2);
        val *= *reinterpret_cast<float*>(0xb5ef80);
        sub_68bbd0(reinterpret_cast<void*>(esi), val);
        f_b4++;
    }

    return 0;
}
