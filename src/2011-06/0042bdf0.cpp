// from server: 74% by atomic.potato
extern "C" void sub_42bbe0(void*, unsigned int);

struct CRobloxTreeCtrlNode
{
    unsigned char pad[0x5c];
    void f(void*, unsigned int*);
};

void CRobloxTreeCtrlNode::f(void* arg, unsigned int* result)
{
    sub_42bbe0(*(void**)((unsigned char*)arg + 0x0c), *(unsigned int*)((unsigned char*)arg + 0x5c));
    *result = 0;
}
