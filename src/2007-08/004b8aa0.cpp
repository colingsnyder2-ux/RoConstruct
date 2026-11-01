// from server: 100% by colin
extern "C" void __cdecl free(void*);

extern void* free_ptr;

struct RakPeer
{
    char pad[0x14];
    void* field_14;
    char field_18;

    void func_004b8aa0(RakPeer* p);
};

void RakPeer::func_004b8aa0(RakPeer* p)
{
    if (p)
    {
        if (p->field_18)
        {
            free(p->field_14);
        }
        ((void (__cdecl*)(void*))free_ptr)(p);
    }
}
