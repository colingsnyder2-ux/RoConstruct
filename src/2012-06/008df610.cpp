// from server: 68% by atomic.potato
struct S_func_008df610
{
    char pad[48];
    int m_offset;
    int f(void* p);
};

extern "C" int __cdecl sub_00683ab0(void*, void*);

int S_func_008df610::f(void* p)
{
    int eax = p ? ((char*)p - 28, (int)((char*)p - 28)) : 0;
    int edx = *(int*)((char*)eax + 132);
    edx = *(int*)((char*)edx + m_offset);
    edx += *(int*)((char*)this + 48);
    return sub_00683ab0((void*)(edx + eax + 132), 0);
}
