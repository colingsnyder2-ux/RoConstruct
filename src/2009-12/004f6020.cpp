// from server: 79% by atomic.potato
extern "C" void* __cdecl func_006e3130(void*);
extern "C" void* __cdecl func_006ec3a0();
extern "C" void* __cdecl func_00701650();

struct S {
    char pad[0x94];
    void* field_94;
    void* f();
};

void* S::f()
{
    void* p = field_94;
    if (p) {
        void* q = func_006e3130(p);
        if (q) {
            void* r = *(void**)((char*)q + 0x168);
            if (r) {
                void* s = func_006ec3a0();
                if (s) {
                    return func_00701650();
                }
            }
        }
    }
    return 0;
}
