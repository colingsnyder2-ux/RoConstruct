// from server: 40% by atomic.potato
struct S
{
    int f(void* p);
    char* field;
};

extern "C" void G1_func_00565780(void*);

int S::f(void* p)
{
    if (p)
        G1_func_00565780((void*)((char*)field - 0x1c + ((char*)p - (char*)0)));
    else
        G1_func_00565780(field);
    return 0;
}
