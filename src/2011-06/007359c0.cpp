// from server: 6% by atomic.potato
struct FactoryProductCreator
{
    void *product;
    unsigned char initialized;
    FactoryProductCreator(void *value);
};

extern "C" void __cdecl InitializeFactoryProduct();

FactoryProductCreator::FactoryProductCreator(void *value)
{
    product = value;
    initialized = 0;
    InitializeFactoryProduct();
}

struct Instance {
    virtual ~Instance();
    char pad[0x40];
    Instance* next;
};

struct ServiceProvider : Instance {
    ServiceProvider* finish();
};

ServiceProvider* func_0048e470(Instance* p) {
    while (p) {
        ServiceProvider* q = dynamic_cast<ServiceProvider*>(p);
        if (q) return q->finish();
        p = p->next;
    }
    return 0;
}

struct Result {
    int a;
    int b;
};

struct TextureContentProvider {
    char pad0[0xd0];
    char field_d0[0x7c];
    char field_14c[0x8];
    char field_154[0x14];
    char field_168[0x10];
    char field_178[0x8];
    char field_180[0x4];
    char field_184[0x4];
    char field_9c[0x4];
    char field_1c[0x4];
    char field_14[0x4];

    int method_7359c0(void* a, Result* b, int* c, int d, int e);
};

extern "C" void* __cdecl func_80a05e(int);
extern "C" void __cdecl func_8011e0(void*);
extern "C" void __cdecl func_7cc1b0(void*, void*, void*, void*, void*, void*, void*);
extern "C" void __cdecl func_72ba70(void*, void*, void*);
extern "C" void __cdecl func_65a430(void*, void*, float);
extern "C" void __cdecl func_65a6d0(void*, void*, void*, float);
extern "C" void __cdecl func_72d6d0(void*, void*, void*);
extern "C" void __cdecl func_734e60(void*, void*, void*);
extern "C" void __cdecl func_735070(void*, void*);
extern "C" void __cdecl func_734df0(void*);
extern "C" void __cdecl func_733600(void*, void*, int);
extern "C" void __cdecl func_733e50(void*, void*);
extern "C" void __cdecl func_78d700(void*, void*, void*);
extern "C" void __cdecl func_78db20(void*, void*, void*);
extern "C" void __cdecl func_78dfe0(void*, void*);
extern "C" void __cdecl func_7736f0(void*);
extern "C" void __cdecl func_411500(void*);
extern "C" void __cdecl func_411650(void*, void*);
extern "C" void __cdecl func_4cd4d0(void*, void*, void*);
extern "C" void __cdecl func_40ac80(void*);
extern "C" void __cdecl func_5e8250(void*, void*);
extern "C" void __cdecl func_7333d0(void*);
extern "C" void* __cdecl func_48e470(void*);

int TextureContentProvider::method_7359c0(void* a, Result* b, int* c, int d, int e)
{
    if (*(int*)((char*)a + 0x14) == 0) {
        *c = 2;
        b->a = 0;
        b->b = 0;
        return 0;
    }
    return 0;
}
