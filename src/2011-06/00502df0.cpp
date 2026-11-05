// from server: 29% by atomic.potato
struct StatsItem {
    char pad0[0xb8];
    int field_b8;
};

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __stdcall sub_4580b0();
extern "C" void __stdcall sub_4fa8d0(void*, void*);
extern "C" void __stdcall sub_4f7730(void*, void*, void*);

void __stdcall sub_502df0(void* self, void* arg)
{
    StatsItem* p = (StatsItem*)operator_new(0xd8);
    if (p) {
        sub_4580b0();
        *(void**)p = (void*)0xa7b9c4;
        *(void**)((char*)p + 4) = (void*)0xa7b9b8;
        *(void**)((char*)p + 0x18) = (void*)0xa7b9ac;
        *(void**)((char*)p + 0x1c) = (void*)0xa7b9a0;
        p->field_b8 = 0;
        sub_4fa8d0((char*)p + 0xb8, (void*)0x4f4330);
    } else {
        p = 0;
    }
    sub_4f7730(self, p, arg);
}
