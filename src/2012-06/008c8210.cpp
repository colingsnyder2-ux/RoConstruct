// from server: 60% by atomic.potato
struct GetSetImpl {
    char pad[0x10];
    int field10;
    int field14;
    void method(void* a, void* b);
};

extern "C" void* __stdcall sub_b22644(void*);

void GetSetImpl::method(void* a, void* b)
{
    char* p = 0;
    if (a != 0)
        p = (char*)a - 0x1c;

    char buf[0x1c];
    sub_b22644(b);
    void* ecx = (char*)this + 0x14;
    int edx = field10;
    ecx = (char*)ecx + (int)p;
    ((void (__thiscall*)(void*, void*))edx)(ecx, buf);
}
