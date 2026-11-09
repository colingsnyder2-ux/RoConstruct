// from server: 37% by colin
struct Creator {
    void construct(char flag);
};

extern "C" void __stdcall sub_417f10(void*, int, void*);
extern "C" void* __stdcall sub_4141a0(void*, void*);
extern "C" void __stdcall sub_62fc62(void*);
extern "C" void* __stdcall sub_62fef6(unsigned int);
extern "C" void __stdcall sub_77e6ac();
extern "C" void __stdcall sub_77e6d8();

struct Inner {
    void* vtable;
    char flag;
};

struct Holder {
    void* begin;
    void* end;
    void* cap;
};

void Creator::construct(char flag)
{
    Holder h;
    h.begin = 0;
    h.end = 0;
    h.cap = 0;

    sub_417f10(&h, 2, &h.begin);

    void* p = h.begin;
    if (p != 0 || ((char*)h.end - (char*)p) / 4 == 0) {
        sub_77e6d8();
        p = h.begin;
    }

    void* tmp = 0;
    void* slot = sub_4141a0(&tmp, &flag);
    void* old = *(void**)slot;
    *(void**)slot = *(void**)p;
    *(void**)p = old;

    if (tmp) {
        void** vt = *(void***)tmp;
        ((void (__stdcall*)(void*, int))vt[0])(tmp, 1);
    }

    if (h.begin == 0 || ((char*)h.end - (char*)h.begin) / 4 <= 1) {
        sub_77e6d8();
    }

    Inner* inner = (Inner*)sub_62fef6(8);
    if (inner) {
        inner->vtable = (void*)0x78a5fc;
        inner->flag = flag;
    } else {
        inner = 0;
    }

    Inner* prev = *(Inner**)((char*)h.begin + 4);
    *(Inner**)((char*)h.begin + 4) = inner;
    if (prev) {
        void** vt = *(void***)prev;
        ((void (__stdcall*)(void*, int))vt[0])(prev, 1);
    }

    void** vt = *(void***)this;
    ((void (__stdcall*)(void*, void*))vt[1])(this, &h);

    if (h.begin) {
        void** cur = (void**)h.begin;
        void** end = (void**)h.end;
        while (cur != end) {
            void* obj = *cur;
            if (obj) {
                void** ovt = *(void***)obj;
                ((void (__stdcall*)(void*, int))ovt[0])(obj, 1);
            }
            cur++;
        }
        sub_62fc62(h.begin);
    }

    h.begin = 0;
    h.end = 0;
    h.cap = 0;
    sub_77e6ac();
}
