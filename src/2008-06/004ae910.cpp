// from server: 100% by colin
extern "C" void __cdecl free(void*);

struct S {
    char pad0[0x34];
    void* field34;
    char pad1[0x08];
    void* field40;
    void* field44;
    void* field48;
    void destroy();
};

void S::destroy()
{
    if (field40) {
        free(field40);
    }
    void* p = field34;
    field40 = 0;
    field44 = 0;
    field48 = 0;
    free(p);
}
