// from server: 34% by atomic.potato
struct S
{
    int vtable;
    int pad[4];
    int base;
    ~S();
};

extern "C" void __cdecl destroy_exception();

S::~S()
{
    vtable = 0xa91160;
    base = 0xa91158;
    base = 0xa5bfdc;
    if (pad[4] != 0)
        destroy_exception();
}
