// from server: 11% by atomic.potato
struct EventDesc
{
    void f(int, int);
};

void EventDesc::f(int a, int b)
{
    if (a)
    {
        void* ecx = *(void**)((char*)this + 0x24);
        void* ecx2 = (void*)((char*)ecx + *(int*)((char*)this + 0x1c));
        ((void (__stdcall *)(void*, void*))0x627ce0)(ecx2, (void*)b);
    }
    else
    {
        void* ecx = *(void**)((char*)this + 0x24);
        void* ecx2 = (void*)((char*)ecx + *(int*)((char*)this + 0x1c));
        ((void (__stdcall *)(void*, void*))0x627ce0)(ecx2, (void*)b);
    }
}
