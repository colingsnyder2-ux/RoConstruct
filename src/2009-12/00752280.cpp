// from server: 31% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl sub_410330(void*, void*);
extern "C" void __cdecl sub_4020A0(void*, void*);
extern "C" void __cdecl sub_41AF50(void*);
extern "C" void __cdecl sub_53CCD0(void*, void*);
extern "C" void __cdecl sub_57BA80(void*, void*);
extern "C" void __cdecl sub_664370(void*);
extern "C" char __cdecl sub_664540(void*, void*);
extern "C" void* __cdecl sub_751FE0(void*, void*);

struct LocalBackpack {
    char pad0[0x130];
    void* field130;
    char pad134[0x3C];
    char field170[8];
    char field178[8];
    void construct(void*);
};

void LocalBackpack::construct(void* a)
{
    char buf[0x10];
    void* p = sub_410330(buf, a);
    void* v = *(void**)p;
    p = (char*)p + 4;
    this->field130 = v;
    sub_4020A0((char*)this + 0x134, p);

    void* edi = *(void**)buf;
    if (edi) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)edi + 4), -1) == 1) {
            void** vt = *(void***)edi;
            ((void (__cdecl*)(void*))vt[1])(edi);
            if (_InterlockedExchangeAdd((volatile long*)((char*)edi + 8), -1) == 1) {
                void** vt2 = *(void***)edi;
                ((void (__cdecl*)(void*))vt2[2])(edi);
            }
        }
    }

    struct { void* f0; void* f4; void* f8; void* fc; } local;
    local.f0 = (void*)0x752030;
    local.f4 = 0;
    local.f8 = this;
    local.fc = 0;
    sub_53CCD0(this->field130, &local);

    void* edi2 = this->field130;
    local.f0 = (void*)0x752030;
    local.f4 = 0;
    local.f8 = this;
    local.fc = 0;
    void* ebx = sub_751FE0((char*)edi2 + 0x78, &local);
    if (sub_664540(this->field170, ebx)) {
        sub_664370(this->field170);
        sub_57BA80(this->field170, ebx);
    }
    sub_41AF50(buf);

    void* edi3 = this->field130;
    local.f0 = (void*)0x751F40;
    local.f4 = 0;
    local.f8 = this;
    local.fc = 0;
    void* edi4 = sub_751FE0((char*)edi3 + 0x7C, &local);
    if (sub_664540(this->field178, edi4)) {
        sub_664370(this->field178);
        sub_57BA80(this->field178, edi4);
    }
    sub_41AF50(buf);
}
