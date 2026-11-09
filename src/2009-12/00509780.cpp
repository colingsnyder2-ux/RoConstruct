// from server: 33% by atomic.potato
struct DescribedBase {
    void* vfptr;
    char pad[0x38];
    void* field_38;
    void* field_3c;
    void* field_40;
    void* field_44;
};

struct VPlayerBoundFuncDesc {
    char pad0[0x38];
    void* field_38;
    void* field_3c;
    void* field_40;
    void* field_44;
    void invoke(void* a, int b);
};

extern "C" void* __stdcall sub_7F4AAA(void* a, void* b, void* c, void* d, void* e);
extern "C" void __stdcall sub_646410(void* a);
extern "C" void __stdcall sub_7F4878(void* a, void* b);
extern "C" void __stdcall bad_cast_ctor(void* a, const char* b);

void VPlayerBoundFuncDesc::invoke(void* a, int b)
{
    void* local8;
    void* localc;
    void* local1c;
    void* local24;
    void* local2c;
    void* local30;

    local8 = this->field_40;
    if (this->field_44) {
        void** vt = *(void***)this->field_44;
        void* (*fn)(void*) = (void* (*)(void*))vt[2];
        localc = fn(this->field_44);
    } else {
        localc = 0;
    }

    void** vt2 = *(void***)a;
    void (*fn2)(void*, int, void*) = (void (*)(void*, int, void*))vt2[1];
    local2c = 0;
    fn2(a, 1, &local8);

    void* result = sub_7F4AAA(local2c, 0, (void*)0xB00040, (void*)0xB0C040, 0);
    void* esi = result;
    if (esi == 0) {
        bad_cast_ctor(&local1c, "bad cast");
        sub_7F4878(&local1c, (void*)0xA9D814);
    }

    sub_646410(&local8);
    unsigned char dl = *(unsigned char*)result;
    void* ecx = this->field_3c;
    void* eax = this->field_38;
    ecx = (char*)ecx + (int)esi;
    void (*fn3)(void*, unsigned char) = (void (*)(void*, unsigned char))eax;
    fn3(ecx, dl);

    void* ecx2 = localc;
    local24 = (void*)0xFFFFFFFF;
    if (ecx2) {
        void** vt3 = *(void***)ecx2;
        void (*fn4)(void*, int) = (void (*)(void*, int))vt3[0];
        fn4(ecx2, 1);
    }
}
