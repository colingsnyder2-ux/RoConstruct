// from server: 31% by atomic.potato
extern "C" {
    void __stdcall func_9ea89c();
    int __stdcall func_9ea8d8();
    void __cdecl func_40a530(void*);
}

struct type_info;

struct bad_cast {
    bad_cast(const char*);
};

struct S {
    void __cdecl f(void*);
};

void S::f(void* p)
{
    if (p != 0) {
        void* q = *(void**)p;
        void* r;
        if (q != 0) {
            r = (*(void*(**)(void*))q)(q);
        } else {
            r = (void*)0xb7930c;
        }
        if (func_9ea8d8() == 0) {
            goto fail;
        }
        if ((char*)p + 4 != 0) {
            return;
        }
    }
fail:
    {
        char buf[8];
        func_9ea89c();
        *(void**)(buf + 0) = (void*)0xa00a4c;
        func_40a530(buf);
    }
}
