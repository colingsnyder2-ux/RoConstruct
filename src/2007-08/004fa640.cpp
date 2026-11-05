// from server: 45% by colin
struct Lighting {
    char pad0[0xc];
    char field0c[0x1c];
    int field28;
    char field2c;
    char pad2d[3];
    int field30;
    int field34;
    int field38;
    int field3c;
    Lighting(void*);
};

extern "C" void __stdcall sub_4cfd40();
extern "C" void __stdcall sub_474f70(int);
extern "C" void __stdcall sub_457dd0();
extern "C" int __stdcall sub_77d2e8(void*);
extern "C" void __stdcall sub_77e62c(char*, const char*);

void* __fastcall sub_4fa640(Lighting* self, void*, void* arg);

void* __fastcall sub_4fa640(Lighting* self, void*, void* arg)
{
    sub_4cfd40();
    *(void**)self = (void*)0x79f148;
    self->field28 = 0;
    self->field2c = 0;
    self->field30 = 0;
    *(int*)((char*)self + 0x38) = 0;
    sub_474f70((int)arg);
    self->field3c = 0;
    sub_77e62c((char*)self + 0xc, (const char*)0x785954);
    if (arg != 0) {
        if (sub_77d2e8((char*)arg + 4) == 0) {
            sub_457dd0();
            void** vt = *(void***)arg;
            void (*fn)(void*, int) = (void (*)(void*, int))vt[0];
            fn(arg, 1);
        }
    }
    return self;
}
