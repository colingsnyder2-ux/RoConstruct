// from server: 18% by colin
struct DescribedBase {
    void* vtable;
};

struct ReflectionType {
    void* vtable;
};

struct FunctionDescriptor {
    void* vtable;
};

struct Arguments {
    void* vtable;
};

struct BoundFuncDesc {
    char pad0[0x34];
    void* field34;
    void* field38;
    void* field3c;
    void* field40;

    void construct(Arguments* args, int a, int b);
};

extern "C" void* __stdcall sub_630d36(void* a, void* b, void* c, void* d, void* e);
extern "C" void __stdcall sub_630b9e(void* a, void* b);
extern "C" void* __stdcall sub_77e710(void* a);

void BoundFuncDesc::construct(Arguments* args, int a, int b)
{
    void* local8;
    void* localc;
    void* local10;
    void* local14;

    local10 = field34;
    if (field38) {
        local14 = ((void* (__thiscall*)(void*))((void**)field38)[2])(field38);
    } else {
        local14 = 0;
    }

    void** vtbl = *(void***)args;
    void (*fn)(void*, int, void*) = (void (*)(void*, int, void*))vtbl[1];
    fn(args, 1, &local10);

    local8 = field3c;
    if (field40) {
        localc = ((void* (__thiscall*)(void*))((void**)field40)[2])(field40);
    } else {
        localc = 0;
    }

    vtbl = *(void***)args;
    fn = (void (*)(void*, int, void*))vtbl[1];
    fn(args, 2, &local8);

    void* result = sub_630d36((void*)local14, (void*)0x88209c, (void*)0x8a76c8, (void*)0, (void*)0);
    if (!result) {
        sub_77e710((void*)0x786e04);
        sub_630b9e((void*)0x841e0c, (void*)0);
    }

    void* p1 = &local8;
    void* p2 = &local10;
    void* p3 = (char*)args + 4;
    void* p4 = result;
    ((void (__thiscall*)(BoundFuncDesc*, void*, void*, void*, void*))0x5a7a70)(this, p4, p3, p2, p1);

    if (localc) {
        ((void (__thiscall*)(void*, int))((void**)localc)[0])(localc, 1);
    }
    if (local14) {
        ((void (__thiscall*)(void*, int))((void**)local14)[0])(local14, 1);
    }
}
