// from server: 100% by king_originala
struct S {
    char pad[0x28];
    int value;
};

extern "C" int __stdcall sub_006a0f92(S*);
extern "C" void __stdcall sub_006a0926();
extern "C" void* __stdcall sub_006a0f2c(const char*, const char*);
extern "C" void* (__stdcall *LoadIconA)(void*, const char*);
extern "C" int __stdcall sub_006a0f8c(int, int, int, void*);

int __stdcall create(S* object)
{
    if (!sub_006a0f92(object))
        return 0;

    sub_006a0926();
    object->value = sub_006a0f8c(
        0, 0, 0,
        LoadIconA(sub_006a0f2c((const char*)128, (const char*)14),
                  (const char*)128));
    return 1;
}
