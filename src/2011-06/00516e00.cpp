// from server: 53% by atomic.potato
extern "C" void sub_004F1270(void*, void*);

struct NetworkOwnerJob
{
    void f(void*, void*);
};

void NetworkOwnerJob::f(void* a, void* b)
{
    char* p = (char*)this + 0xE10;
    sub_004F1270(a, b);
}
