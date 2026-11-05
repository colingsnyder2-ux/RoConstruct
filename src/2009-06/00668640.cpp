// from server: 100% by atomic.potato
struct T4_00668640 {
    char pad[0x48];
    void* m_ptr;
};

extern "C" void* __cdecl sub_00719c7a(void*, void*, void*, void*, void*);
extern "C" void* __fastcall sub_00668240(void*);

void* sub_00668640(T4_00668640* p)
{
    if (p != 0) {
        void* q = p->m_ptr;
        if (q != 0) {
            void* r = sub_00719c7a(q, 0, (void*)0x9dbe40, (void*)0x9e6188, 0);
            if (r != 0)
                return sub_00668240(r);
        }
    }
    return 0;
}
