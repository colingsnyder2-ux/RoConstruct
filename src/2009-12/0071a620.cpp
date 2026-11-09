// from server: 58% by atomic.potato
extern "C" int __cdecl f();

extern "C" void g(void*, void*, void*, int);

struct EventDesc
{
    char padding[0xd0];
    void* field;
    void f(int);
};

void EventDesc::f(int value)
{
    struct Arg
    {
        void* p;
    };

    Arg* arg = (Arg*)value;
    int result = ::f();
    g((void*)0x77e440, field, arg, result);
}
