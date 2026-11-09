// from server: 72% by atomic.potato
extern "C" void __stdcall sub_0040C080(void*);
extern "C" void* __stdcall sub_00785CE0(void*, int, void*);
extern "C" void __stdcall sub_006D0780(void*, void*);
extern "C" void* __stdcall sub_0067ACD0(void*, int);
extern "C" void __stdcall sub_006BAD70(void*, void*);
extern "C" void __stdcall sub_006877A0(void*, void*);

struct S
{
    void f(int);
};

void S::f(int a)
{
    void* p = sub_00785CE0((void*)a, 0, (void*)0x00B98888);
    if (p)
    {
        sub_006D0780(p, *(void**)0x00B3A70C);
        void* q = sub_0067ACD0(*(void**)((char*)this + 0x18), 10);
        sub_006BAD70(q, 0);
        void* r = (*(void*(**)(void*))*(void**)this)(this);
        char* s;
        if (*(unsigned int*)((char*)r + 0x18) < 0x10)
            s = (char*)r + 4;
        else
            s = *(char**)((char*)r + 4);
        sub_006877A0(s, *(void**)((char*)this + 0x18));
        void* t = *(void**)((char*)this + 0x18);
        void* u = *(void**)((char*)t + 0x1AC);
        (*(void(**)(void*, int))*(void**)u)(u, 1);
    }
}
