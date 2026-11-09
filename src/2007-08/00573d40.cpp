// from server: 100% by colin
struct S {
    char pad[0x68];
    void* field68;
};

void* __cdecl get(S* arg)
{
    if (arg != 0) {
        void* p = arg->field68;
        if (p != 0)
            return (char*)p - 0x170;
    }
    return 0;
}
