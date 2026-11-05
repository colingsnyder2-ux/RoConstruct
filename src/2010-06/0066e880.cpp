// from server: 84% by atomic.potato
struct VPartInstance {
    char pad[0x4c];
    void* m_field4c;
};

extern "C" void* __cdecl sub_007a8bea(void*, void*, void*, void*, void*);
extern "C" void* __cdecl sub_0066e470(void*);

void* __cdecl sub_0066e880(VPartInstance* p)
{
    if (p != 0) {
        void* q = p->m_field4c;
        if (q != 0) {
            void* r = sub_007a8bea(q, 0, (void*)0xb78e40, (void*)0xb84678, 0);
            if (r != 0)
                return sub_0066e470(r);
        }
    }
    return 0;
}
