// from server: 100% by atomic.potato
struct S
{
    void method(void**);
};

void __cdecl wrapper(void* arg1, void* arg2)
{
    ((S*)arg1)->method(&arg2);
}
