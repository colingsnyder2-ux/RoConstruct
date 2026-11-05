// from server: 54% by atomic.potato
extern "C" void* removeChild(void*, unsigned int);

struct S
{
    void* f(unsigned int);
};

void* S::f(unsigned int id)
{
    void* node = removeChild(*(void**)0x00A4133C, id);
    f((unsigned int)node);
    return node;
}
