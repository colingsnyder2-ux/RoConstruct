// from server: 46% by atomic.potato
struct EventDesc
{
    int pad[11];
    void* value;
    void f(void*);
};

extern "C" void __stdcall sub_008fa2a0(void*, void*);

void EventDesc::f(void* arg)
{
    char* p = (char*)value;
    if (arg)
        p += (int)arg - 0x1c;
    sub_008fa2a0(this, p);
}
