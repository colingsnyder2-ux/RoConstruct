// from server: 62% by atomic.potato
struct EventDesc
{
    int* m_38;
    int* m_3c;

    void* f(void* p);
};

extern "C" void* sub_503a70(void* p);

void* EventDesc::f(void* p)
{
    char* x = p ? (char*)p - 0x1c : 0;
    int v = *(int*)((char*)x + 0x148);
    v = *(int*)((char*)v + *m_3c);
    v += (int)m_38;
    return sub_503a70((char*)x + 0x148 + v);
}
