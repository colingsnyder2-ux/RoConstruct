// from server: 100% by colin
struct Inner {
    void destroy();
};

struct Outer {
    char pad[0x58];
    Inner inner;
    Outer* scalar_deleting_destructor(unsigned int flags);
};

extern "C" void __cdecl free_mem(void*);
extern void (__thiscall *ifstream_dtor)(Inner*);

Outer* Outer::scalar_deleting_destructor(unsigned int flags)
{
    Outer* self = (Outer*)((char*)this - 0x58);
    Inner* p = (Inner*)self;
    ifstream_dtor(p);
    if (flags & 1) {
        free_mem(self);
    }
    return self;
}
