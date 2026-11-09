// from server: 45% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl _invalid_parameter_noinfo();

struct RBXName {
    void* data;
};

struct CreatorBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

struct Creator : CreatorBase {
    int field0;
};

struct CreatorsMap {
    void* field0;
    void* field1;
    void* field2;
};

struct FactoryProduct {
    char pad[0x134];
    Creator** creators_begin;
    Creator** creators_end;
};

extern "C" void __cdecl sub_43DE50(void* out, void* a, void* b);
extern "C" void* __cdecl sub_5578C0();
extern "C" void __cdecl sub_725520(void* a, void* b, void* c);
extern "C" void __cdecl sub_402A60(void* a, void* b);
extern "C" void __cdecl sub_541630(void* a, void* b);
extern "C" void* __cdecl sub_55A490();
extern "C" void* __cdecl sub_77E6D8();

void FactoryProduct_ctor(FactoryProduct* self) {
    void* result = sub_55A490();
    if (result != 0) {
        return;
    }

    void* local8 = 0;
    void* localC = 0;
    sub_43DE50(&local8, &localC, 0);

    void* ebx = local8;

    sub_725520((void*)0x8C1F1C, (void*)0x5588D0, 0);

    void* eax = sub_5578C0();
    int edi = (int)eax;

    Creator** begin = self->creators_begin;
    if (begin == 0) {
        sub_77E6D8();
    } else {
        Creator** end = self->creators_end;
        int count = (int)((char*)end - (char*)begin) >> 3;
        if (edi >= count) {
            sub_77E6D8();
        }
    }

    Creator** slot = self->creators_begin + edi;
    *slot = (Creator*)localC;
    sub_402A60(slot + 1, &local8);

    sub_541630(ebx, self);

    Creator* obj = (Creator*)local8;
    if (obj != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)obj + 4), -1) == 1) {
            void** vt = *(void***)obj;
            ((void (__thiscall*)(Creator*))vt[1])(obj);
            if (_InterlockedExchangeAdd((volatile long*)((char*)obj + 8), -1) == 1) {
                void** vt2 = *(void***)obj;
                ((void (__thiscall*)(Creator*))vt2[2])(obj);
            }
        }
    }
}
