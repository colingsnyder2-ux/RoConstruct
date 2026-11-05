// from server: 50% by atomic.potato
struct S {
    void* m_pad0;
    void* m_field4;
    int Filter(void* arg);
};

extern "C" void* __cdecl sub_751300(void*);
extern "C" bool __stdcall sub_42a4f0(void*);

int S::Filter(void* arg) {
    if (this->m_field4 == 0)
        return 2;
    void* r = sub_751300(arg);
    void* f4 = this->m_field4;
    if (r == f4)
        return 1;
    void* r38 = *(void**)((char*)r + 0x38);
    if (f4 == r38)
        return 1;
    if (r38 == 0)
        return 2;
    if (!sub_42a4f0(f4))
        return 2;
    return 1;
}
