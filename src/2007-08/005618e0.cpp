// from server: 11% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct RBXName;

struct CreatorBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

struct Creator : CreatorBase {
    int field_04;
    int field_08;
};

struct CreatorsMap {
    Creator** begin;
    Creator** end;
};

struct FactoryProduct {
    char pad_000[0x134];
    Creator** creators_begin;
    Creator** creators_end;

    int sub_560e30();
    void sub_560490(void** out);
    void sub_541630(Creator* c);
};

extern "C" void* __cdecl sub_725520(void* a, void* b, void* c);
extern "C" int __cdecl sub_55e7c0();
extern "C" void __cdecl sub_402a60(void* a, void* b);
extern "C" void* __stdcall sub_77e6d8();

int FactoryProduct::sub_560e30()
{
    return 0;
}

void FactoryProduct::sub_560490(void** out)
{
    *out = 0;
}

void FactoryProduct::sub_541630(Creator* c)
{
}

Creator* FactoryProduct_ctor(FactoryProduct* self)
{
    if (self->sub_560e30() != 0)
        return 0;

    void* local = 0;
    self->sub_560490(&local);

    Creator* c = (Creator*)local;

    sub_725520((void*)0x8c2328, (void*)0x55ed70, 0);
    int idx = sub_55e7c0();

    Creator** begin = self->creators_begin;
    if (begin != 0) {
        Creator** end = self->creators_end;
        int count = (int)((char*)end - (char*)begin) >> 3;
        if ((unsigned)idx >= (unsigned)count) {
            sub_77e6d8();
        }
    } else {
        sub_77e6d8();
    }

    Creator** slot = self->creators_begin + idx;
    *slot = c;
    sub_402a60(slot + 1, &local);

    self->sub_541630(c);

    if (c != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)c + 4), -1) == 1) {
            void** vt = *(void***)c;
            ((void (__thiscall*)(Creator*))vt[1])(c);
            if (_InterlockedExchangeAdd((volatile long*)((char*)c + 8), -1) == 1) {
                void** vt2 = *(void***)c;
                ((void (__thiscall*)(Creator*))vt2[2])(c);
            }
        }
    }

    return c;
}
