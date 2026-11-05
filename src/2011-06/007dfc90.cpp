// from server: 86% by atomic.potato
extern "C" void* __cdecl sub_80B2EA(void*, void*, void*, void*, void*);

struct RBX_AnchorTool
{
    char pad[0x1c];
    void* field_1c;
    void __thiscall_method(void*);
};

void RBX_AnchorTool::__thiscall_method(void* arg)
{
    void* p = field_1c;
    if (p != 0)
    {
        void* r = sub_80B2EA(p, 0, (void*)0xC071F8, (void*)0xC29224, 0);
        if (r != 0)
        {
            void** vt = *(void***)r;
            void (__thiscall *fn)(void*, void*) = (void (__thiscall *)(void*, void*))vt[7];
            fn(r, arg);
        }
    }
}
