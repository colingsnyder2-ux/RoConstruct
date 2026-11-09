// from server: 71% by atomic.potato
extern "C" void* removeChild(void*, void*);

struct S
{
    void* f(void*);
};

void* S::f(void* child)
{
    void* node = removeChild(0, child);
    removeChild(this, node);
    return node;
}
