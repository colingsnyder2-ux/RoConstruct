// from server: 56% by colin
struct DomResourceIcon;

struct CXTIconHandle {
    void* m_p;
    void* m_q;
    void* __thiscall create(DomResourceIcon* a, unsigned int b);
};

extern "C" int __cdecl sub_4017a0(void*, unsigned int, unsigned int);
extern "C" int __cdecl sub_4028b0(void*, unsigned int, unsigned int);

void* __thiscall CXTIconHandle::create(DomResourceIcon* a, unsigned int b)
{
    unsigned int aligned = ((unsigned int)a + 8) & 0xfffffff8;
    void* p = &a;
    if (sub_4017a0(p, aligned, b) < 0)
        return 0;
    if (sub_4028b0(p, 0x10, (unsigned int)a) < 0)
        return 0;
    void* q = m_q;
    void* r = (*(void*(__thiscall**)(void*))q)(a);
    if (r != 0)
        return 0;
    aligned--;
    *(unsigned int*)((char*)r + 4) = 0;
    *(void**)r = this;
    *(unsigned int*)((char*)r + 0xc) = 1;
    *(unsigned int*)((char*)r + 8) = aligned;
    return r;
}
