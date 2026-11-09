// from server: 54% by atomic.potato
extern "C" void __stdcall sub_7a799a(void*);
extern "C" void __stdcall sub_7a8ade(void*, int, int, void*);
extern "C" void __stdcall sub_4024a0(void*);

struct SleepStage {
    void dtor();
};

void SleepStage::dtor()
{
    char* p = (char*)this;
    *(void**)p = (void*)0xa521b4;

    void* q;
    q = *(void**)(p + 0x200);
    if (q) {
        (*(void(__thiscall**)(void*, int))*(void**)q)(q, 1);
    }
    q = *(void**)(p + 0x1fc);
    if (q) {
        (*(void(__thiscall**)(void*, int))*(void**)q)(q, 1);
    }
    q = *(void**)(p + 0x1f8);
    if (q) {
        (*(void(__thiscall**)(void*, int))*(void**)q)(q, 1);
    }

    sub_4024a0(p + 0x1d0);
    sub_7a8ade(p + 0x1b8, 0xc, 2, (void*)0x7113b0);
    sub_7a8ade(p + 0x1a0, 0xc, 2, (void*)0x7113b0);
    sub_4024a0(p + 0x180);
    sub_4024a0(p + 0x160);
    sub_4024a0(p + 0x140);
    sub_4024a0(p + 0x120);
    sub_4024a0(p + 0x100);
    sub_4024a0(p + 0xe0);

    q = *(void**)(p + 0xc4);
    if (q) {
        sub_7a799a(q);
    }
    sub_7a799a(*(void**)(p + 0xb8));
    *(void**)(p + 0xc4) = 0;
    *(void**)(p + 0xc8) = 0;
    *(void**)(p + 0xcc) = 0;

    q = *(void**)(p + 0xac);
    if (q) {
        sub_7a799a(q);
    }
    sub_7a799a(*(void**)(p + 0xa0));
    *(void**)(p + 0xac) = 0;
    *(void**)(p + 0xb0) = 0;
    *(void**)(p + 0xb4) = 0;

    q = *(void**)(p + 0x94);
    if (q) {
        sub_7a799a(q);
    }
    sub_7a799a(*(void**)(p + 0x88));
    *(void**)(p + 0x94) = 0;
    *(void**)(p + 0x98) = 0;
    *(void**)(p + 0x9c) = 0;

    q = *(void**)(p + 0x7c);
    if (q) {
        sub_7a799a(q);
    }
    sub_7a799a(*(void**)(p + 0x70));
    *(void**)(p + 0x7c) = 0;
    *(void**)(p + 0x80) = 0;
    *(void**)(p + 0x84) = 0;

    q = *(void**)(p + 0x64);
    if (q) {
        sub_7a799a(q);
    }
    sub_7a799a(*(void**)(p + 0x58));
    *(void**)(p + 0x64) = 0;
    *(void**)(p + 0x68) = 0;
    *(void**)(p + 0x6c) = 0;

    q = *(void**)(p + 0x4c);
    if (q) {
        sub_7a799a(q);
    }
    sub_7a799a(*(void**)(p + 0x40));
    *(void**)(p + 0x4c) = 0;
    *(void**)(p + 0x50) = 0;
    *(void**)(p + 0x54) = 0;

    q = *(void**)(p + 0x34);
    if (q) {
        sub_7a799a(q);
    }
    sub_7a799a(*(void**)(p + 0x28));
    *(void**)(p + 0x34) = 0;
    *(void**)(p + 0x38) = 0;
    *(void**)(p + 0x3c) = 0;

    q = *(void**)(p + 0x1c);
    if (q) {
        sub_7a799a(q);
    }
    sub_7a799a(*(void**)(p + 0x10));
    *(void**)(p + 0x1c) = 0;
    *(void**)(p + 0x20) = 0;
    *(void**)(p + 0x24) = 0;

    q = *(void**)(p + 8);
    if (q) {
        (*(void(__thiscall**)(void*, int))*(void**)q)(q, 1);
    }
}
