// from server: 29% by tester
struct DescribedBase {
    void* vtable;
};

struct FunctionDescriptor {
    void* vtable;
    int pad[16];
};

struct Arguments {
    void* vtable;
    void* pad;
};

struct BoundFuncDesc {
    char pad0[0x38];
    void* field38;
    int field3c;
    int field40;
    void* field44;
    void* field48;

    void construct(Arguments* args);
};

extern "C" void* __stdcall sub_719c7a(void* a, void* b, void* c, void* d, int e);
extern "C" void __stdcall sub_719a4a(void* a, void* b);
extern "C" void __stdcall sub_5e80b0(void* a);
extern "C" void __stdcall sub_89e970(void* a);

void BoundFuncDesc::construct(Arguments* args)
{
    void* local8 = field44;
    void* localc;
    if (field48) {
        void** vt = *(void***)field48;
        typedef void* (__thiscall *Fn)(void*);
        localc = ((Fn)vt[2])(field48);
    } else {
        localc = 0;
    }
    void** avt = *(void***)args;
    typedef void (__thiscall *Fn2)(void*, int, void*);
    ((Fn2)avt[1])(args, 1, &local8);
    void* r = sub_719c7a(localc, 0, (void*)0x9dbfc4, (void*)0x9ecae4, 0);
    if (!r) {
        sub_89e970((void*)0x8ad350);
        sub_719a4a((void*)0x984bb0, &local8);
    }
    sub_5e80b0(&local8);
    float f = *(float*)r;
    int edx = *(int*)((char*)r + 0x140);
    int eax = field40;
    int ecx = *(int*)(edx + eax);
    ecx += field3c;
    void* edx2 = field38;
    typedef void (__thiscall *Fn3)(void*, float);
    ((Fn3)edx2)((char*)r + ecx + 0x140, f);
    if (localc) {
        void** vt = *(void***)localc;
        typedef void (__thiscall *Fn4)(void*, int);
        ((Fn4)vt[0])(localc, 1);
    }
}
