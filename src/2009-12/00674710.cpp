// from server: 100% by atomic.potato
extern "C" int __cdecl sub_7F4AAA(void*, void*, void*, void*, void*);

struct ServiceProvider
{
    int f();
};

int ServiceProvider::f()
{
    void* value = *(void**)((char*)this + 0x4c);
    return sub_7F4AAA(value, 0, (void*)0xaffe40, (void*)0xb028b0, 0);
}
