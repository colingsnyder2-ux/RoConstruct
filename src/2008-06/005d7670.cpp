// from server: 100% by king_originala
extern char instanceType;
extern char modelType;

extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

struct S {
    char padding[0x104];
    void* instance;
};

void* func_005d7670(S* object)
{
    if (object) {
        void* model = __RTDynamicCast(object->instance, 0,
                                     &instanceType, &modelType, 0);
        if (model)
            return model;
    }
    return 0;
}
