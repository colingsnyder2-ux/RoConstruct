// from server: 25% by atomic.potato
struct S {
    char pad0[0x1c];
    char str1c[0x1c];
    char pad38[0x8];
    char pad40[0x8];
    char pad48[0x8];
    void f(int, int, int, int);
};

extern "C" void __stdcall sub_98b6f0(void*, void*);

void S::f(int a, int b, int c, int d)
{
    char buf[0x20];
    *(void**)buf = 0;
    void* p = *(void**)((char*)this + 0x40);
    if (p) {
        *(void**)buf = p;
        void* q = *(void**)((char*)this + 0x40);
        void* r = (void*)((char*)this + 0x48);
        void* fn = *(void**)q;
        ((void (__stdcall*)(void*, void*, int))fn)(r, buf + 8, 0);
    }
    unsigned char ch = *(unsigned char*)((char*)this + 0x38);
    sub_98b6f0((char*)this + 0x1c, buf);
    sub_98b6f0(this, buf);
    void* obj = (void*)d;
    void* fn2 = *(void**)obj;
    ((void (__stdcall*)(void*))fn2)(obj);
}
