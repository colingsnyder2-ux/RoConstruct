// from server: 85% by atomic.potato
extern "C" void* __cdecl sub_00689990(void*);

struct S
{
    void f(void*);
};

void S::f(void* p)
{
    void* q = sub_00689990((char*)p + 4);
    void* value = *(void**)q;
    *(void**)((char*)&value) = value;
    ((void (__thiscall*)(S*, void*))0x76a190)(this, &value);
}
