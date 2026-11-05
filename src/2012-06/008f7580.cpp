// from server: 76% by atomic.potato
extern "C" float __cdecl sub_68A700(void*, void*, int);

struct BoundFuncDesc {
    char pad_00[0x30];
    void* call_30;
    unsigned int adjust_34;
    char data_38;
    void invoke(void*, void*);
};

void BoundFuncDesc::invoke(void* a, void* b) {
    float v = sub_68A700(b, &data_38, 0);
    char* self;
    if (a) {
        self = (char*)a - 0x1c + adjust_34;
    } else {
        self = (char*)adjust_34;
    }
    typedef void (__thiscall *Trampoline)(void*, float);
    ((Trampoline)call_30)(self, v);
}
