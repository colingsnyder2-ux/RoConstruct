// from server: 48% by colin
struct sp_counted_impl_p {
    void* inner;
    sp_counted_impl_p(void* p);
};

extern "C" void* __cdecl operator_new(unsigned int size);

sp_counted_impl_p::sp_counted_impl_p(void* p)
{
    inner = 0;
    void* mem = operator_new(0x10);
    if (mem) {
        *(int*)((char*)mem + 4) = 1;
        *(int*)((char*)mem + 8) = 1;
        *(void**)mem = (void*)0x7e51a4;
        *(void**)((char*)mem + 0xc) = p;
    } else {
        mem = 0;
    }
    inner = mem;
}
