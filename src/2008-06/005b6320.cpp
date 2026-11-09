// from server: 100% by king_originala
struct S {
    int f(void* arg);
    S* lookup(void* arg, int index, const char* name);
    void* get();
    void assign(S* value);
};

extern "C" void* __cdecl cast_object(
    void* object, long offset, const void* sourceType,
    const void* targetType, int isReference);

int S::f(void* arg)
{
    S* value = lookup(arg, 0, reinterpret_cast<const char*>(0x97bee0));
    if (value) {
        S* model = static_cast<S*>(cast_object(
            value->get(), 0,
            reinterpret_cast<const void*>(0x947f1c),
            reinterpret_cast<const void*>(0x932a40), 0));
        if (model)
            model->assign(value);
    }
    return 0;
}
