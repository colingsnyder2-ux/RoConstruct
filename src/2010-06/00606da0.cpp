// from server: 37% by atomic.potato
struct DescribedBase {
    void* vtable;
    virtual void f0();
    virtual void f1();
    virtual void f2();
};

struct BoundFuncDesc {
    char pad0[0x38];
    void* field38;
    int field3c;
    int field40;
    void* field44;
    void* field48;
    void invoke(void* a, void* b);
};

extern "C" void* __stdcall sub_7a8bea(void*, void*, void*, void*, void*);
extern "C" void* __stdcall sub_7a89b2(void*, void*);
extern "C" void* __stdcall sub_5a8bd0(void*);
extern "C" void __stdcall sub_9ea89c(void*, void*);

void BoundFuncDesc::invoke(void* a, void* b)
{
    void* local8;
    void* localc;
    void* local1c;
    void* local24;
    void* local2c;

    local8 = field44;
    if (field48) {
        localc = (*(void*(**)(void*))((*(void***)field48) + 2))(field48);
    } else {
        localc = 0;
    }
    local2c = 0;
    (*(void(**)(void*, void*, int))((*(void***)a) + 1))(a, &local8, 1);
    void* r = sub_7a8bea(local2c, 0, (void*)0xb79040, (void*)0xbaacf4, 0);
    if (!r) {
        sub_9ea89c(&local1c, (void*)0xa00a54);
        sub_7a89b2(&local1c, (void*)0xb12290);
    }
    unsigned char c = *(unsigned char*)sub_5a8bd0(&local8);
    void* p = (void*)((char*)r + 0x98);
    int off = *(int*)((char*)p + field40);
    off += field3c;
    void* target = (void*)((char*)r + off + 0x98);
    (*(void(**)(void*, int))field38)(target, c);
    local24 = (void*)0xffffffff;
    if (localc) {
        (*(void(**)(void*, int))localc)(localc, 1);
    }
}
