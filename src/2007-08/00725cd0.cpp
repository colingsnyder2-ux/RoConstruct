// from server: 100% by colin
extern "C" void __cdecl free_0062fc62(void*);

struct Inner {
    void method_00725720();
};

struct Outer {
    Inner* ptr;
    void method_00725cd0();
};

void Outer::method_00725cd0()
{
    Inner* p = ptr;
    if (p != 0) {
        void* q = *(void**)((char*)p + 0xc);
        if (q != 0) {
            free_0062fc62(q);
        }
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        *(int*)((char*)p + 0x14) = 0;
        p->method_00725720();
        free_0062fc62(p);
    }
}
