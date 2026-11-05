// from server: 94% by atomic.potato
extern "C" void __cdecl func_00428540(void*);
extern "C" void __cdecl func_00428700(void*);

struct RBX_Log
{
    void* field_0;
    RBX_Log* assign(void*);
};

RBX_Log* RBX_Log::assign(void* arg)
{
    void* v = *(void**)arg;
    if (field_0)
        func_00428540((char*)field_0 + 5);
    field_0 = v;
    if (v)
        func_00428700((char*)v + 5);
    return this;
}
