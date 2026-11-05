// from server: 30% by atomic.potato
extern "C" void __stdcall sub_4015a0(int, int);
extern "C" void* __stdcall make_value_00540c20();
extern "C" void __cdecl sub_542250();
extern "C" void* __cdecl sub_543ab0();
extern "C" char __cdecl sub_5441a0();
extern "C" void __cdecl sub_6ce510();
extern "C" void __cdecl sub_6dde00();
extern "C" void __cdecl sub_864e70(int, void*);
extern "C" void __cdecl sub_4026a0();

struct S {
    char pad0[0x80];
    int field_80;
    int field_84;
    int field_88;
    int method();
};

int S::method() {
    sub_4015a0(0xe215f0, 0x541c10);
    int edi = (int)make_value_00540c20();
    int eax = this->field_88 - this->field_84;
    eax >>= 3;
    int edx = edi + 1;
    if ((unsigned)edx > (unsigned)eax) {
        int local0 = 0;
        int local1 = 0;
        sub_864e70(edx, &local0);
    } else {
        int ecx = this->field_84;
        int eax2 = *(int*)(ecx + edi * 8);
        if (eax2 != 0) {
            return eax2;
        }
    }
    if (sub_5441a0()) {
        return 0;
    }
    sub_542250();
    int eax3 = (int)sub_543ab0();
    int local2;
    sub_6ce510();
    int ecx2 = local2;
    if (ecx2 == 0) {
        sub_6dde00();
        return 0;
    }
    int eax4 = this->field_84;
    eax4 += edi * 8;
    *(int*)eax4 = ecx2;
    sub_4026a0();
    sub_6dde00();
    return ecx2;
}
