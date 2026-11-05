// from server: 42% by TrollStein
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RBXName {
    void* rep;
};

struct CreatorBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

struct Creator : CreatorBase {
    void* field4;
};

struct CreatorsMap {
    void* head;
};

struct FactoryProduct {
    char pad[0xec];
    void* field_ec;
    char pad2[0x120 - 0xec - 4];
    CreatorsMap map120;
    char pad3[0x12c - 0x120 - 4];
    CreatorsMap map12c;

    void* construct(bool flag, void* arg);
    void sub_77e6d8();
};

struct StringImpl {
    char buf[0x1c];
};

struct String {
    StringImpl* impl;
};

struct SharedPtr {
    void* px;
    long* pn;
};


extern "C" void __stdcall sub_77e6ac();
extern "C" void* __stdcall sub_77e69c(void*, void*, void*);

void* __cdecl operator_new(unsigned int size);
void __cdecl sub_40cc20(void*, void*, void*);

void* __fastcall sub_588f30(void* self, void* dummy, void* a, void* b);
void* __fastcall sub_588d80(void* self, void* dummy, void* a);
void* __fastcall sub_58a110(void* self, void* dummy, void* a);
void* __fastcall sub_587df0(void* self, void* dummy, void* a);
void* __fastcall sub_402a60(void* self, void* dummy, void* a);

void* FactoryProduct::construct(bool flag, void* arg)
{
    void* result;
    void* local10 = 0;
    char local2c = 1;
    void* local38;
    void* local18;
    void* local20;
    void* local14;
    void* local24;
    void* local34;
    void* local58 = arg;

    CreatorsMap* map = flag ? &map12c : &map120;

    sub_588f30(map, 0, &local18, &local38);

    void* esi = local10;
    local20 = map->head;

    if (esi != 0 && esi != map) {
        sub_77e6d8();
    }

    void* ebp = local18;
    if (ebp != local20) {
        if (esi != 0) {
            sub_77e6d8();
        }
        if (ebp == *(void**)((char*)esi + 4)) {
            sub_77e6d8();
        }

        void* eax = *(void**)((char*)ebp + 0x2c);
        void* out = local34;
        *(void**)out = eax;
        eax = *(void**)((char*)ebp + 0x30);
        *(void**)((char*)out + 4) = eax;
        if (eax != 0) {
            _InterlockedExchangeAdd((volatile long*)((char*)eax + 4), 1);
        }

        local10 = (void*)1;
        local2c = 0;
        sub_77e6ac();
        return out;
    }

    void* mem = operator_new(0x30);
    ebp = mem;
    local14 = ebp;
    if (ebp != 0) {
        void* a = local58;
        char buf[0x20];
        sub_77e69c(buf, 0, &local58);
        *(void**)(buf + 0x1c) = local58;
        void* edx = field_ec;
        void* r = sub_587df0(ebp, 0, edx);
        esi = r;
    } else {
        esi = 0;
    }

    local18 = esi;
    sub_588d80(&local18, 0, esi);
    sub_40cc20(&local18, esi, esi);

    void* r2 = sub_58a110(map, 0, &local38);
    *(void**)r2 = local14;
    sub_402a60((char*)r2 + 4, 0, &local18);

    void* edi = local34;
    *(void**)edi = local14;
    void* esi2 = local18;
    *(void**)((char*)edi + 4) = esi2;
    if (esi2 != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)esi2 + 4), 1);
    }

    local10 = (void*)1;
    local2c = 1;

    if (esi2 != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)esi2 + 4), -1) == 1) {
            void** vt = *(void***)esi2;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(esi2);
            if (_InterlockedExchangeAdd((volatile long*)((char*)esi2 + 8), -1) == 1) {
                void** vt2 = *(void***)esi2;
                void (*fn2)(void*) = (void (*)(void*))vt2[2];
                fn2(esi2);
            }
        }
    }

    local2c = 0;
    sub_77e6ac();
    return edi;
}
