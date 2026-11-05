// from server: 32% by atomic.potato
extern "C" {
    int __stdcall sub_9EA8D8(void*, void*);
    int __stdcall sub_9EA89C(void*, void*);
    void __cdecl sub_40A530(void*);
}

struct S {
    void f(void* p);
};

void S::f(void* p)
{
    if (p != 0) {
        void* q = *(void**)p;
        if (q != 0) {
            void** vt = *(void***)q;
            typedef void (__stdcall *Fn)(void*);
            Fn fn = (Fn)vt[1];
            fn(q);
        } else {
            q = (void*)0xB7930C;
        }
        if (sub_9EA8D8((void*)0xB924F0, q)) {
            char* r = (char*)*(void**)p;
            r += 4;
            if (r != 0) {
                return;
            }
        }
    }
    sub_9EA89C((void*)0xA00A54, (void*)0xA00A4C);
    sub_40A530((void*)0xA00A4C);
}
