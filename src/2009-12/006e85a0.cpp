// from server: 40% by atomic.potato
struct DescribedBase {
    void* vtable;
    char pad[0x34];
    int field38;
    int field3c;
    int field40;
    int field44;
    void* field48;
};

struct Humanoid {
    char pad[0x148];
    int field148;
};

struct String {
    char pad[0x1c];
};

extern "C" void* __stdcall sub_7f4aaa(int, int, int, int, int);
extern "C" void __stdcall sub_7f4878(void*, void*);
extern "C" void __stdcall sub_409c20(void*, void*);
extern "C" void __stdcall sub_646920(void*);
extern "C" void* __stdcall sub_98b7a4();
extern "C" void __stdcall sub_98b6f0(void*, void*);

struct VHumanoid {
    void func(int, int);
};

void VHumanoid::func(int a, int b) {
    DescribedBase* self = (DescribedBase*)this;
    int local_c;
    int local_10;
    void* local_14;
    int local_18;
    int local_1c;
    int local_20;
    int local_24;
    int local_28;
    int local_2c;
    int local_30;
    int local_34;
    int local_38;
    int local_3c;
    int local_40;
    int local_44;
    int local_48;
    int local_4c;
    int local_50;
    int local_54;
    int local_58;
    int local_5c;
    int local_60;
    int local_64;
    int local_68;
    int local_6c;
    int local_70;
    int local_74;
    int local_78;
    int local_7c;
    int local_80;

    local_c = self->field44;
    if (self->field48) {
        local_10 = ((int (__thiscall*)(void*))((void**)self->field48)[2])(self->field48);
    } else {
        local_10 = 0;
    }
    void* ebx = (void*)b;
    ((void (__thiscall*)(void*, int, int*))((void**)*(void**)ebx)[1])(ebx, 1, &local_c);
    local_30 = 0;
    void* esi = sub_7f4aaa(local_30, 0xb00040, 0xb1323c, 0, 0);
    if (!esi) {
        sub_98b7a4();
        sub_7f4878(&local_18, &local_18);
    }
    sub_646920(&local_c);
    sub_98b6f0(esi, 0);
    int edx = *(int*)((char*)esi + 0x148);
    int eax = self->field40;
    int ecx = *(int*)(edx + eax);
    ecx += self->field3c;
    int edx2 = self->field38;
    ecx = ecx + (int)esi + 0x148;
    ((void (__thiscall*)(int))edx2)(ecx);
    local_34 = 0;
    sub_409c20((char*)ebx + 4, &local_34);
    int ecx2 = local_10;
    local_28 = -1;
    if (ecx2) {
        ((void (__thiscall*)(int, int))*(void**)*(void**)ecx2)(ecx2, 1);
    }
}
