// from server: 100% by colin
struct S {
    void f(int);
};

extern "C" bool __cdecl sub_4915F0(void*, int);
extern "C" void* __cdecl sub_5A56B0(void*);

void S::f(int a)
{
    if (sub_4915F0(this, 0)) {
        void* p = sub_5A56B0(*(void**)((char*)this + 0xbc));
        if (p) {
            void** vt = *(void***)this;
            void (__thiscall *fn)(void*, void*) = (void (__thiscall *)(void*, void*))vt[0x44 / 4];
            fn(this, p);
        }
    }
}
