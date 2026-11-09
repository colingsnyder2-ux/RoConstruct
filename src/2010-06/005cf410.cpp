// from server: 36% by atomic.potato
struct S {
    void* p;
    void f();
};

extern "C" void* __cdecl f7a79a0(unsigned int);
extern "C" void __fastcall f4a4440(void*, void*);
extern "C" void __fastcall f4a3360(void*);

void S::f() {
    void* mem = f7a79a0(0x3c);
    if (mem != 0) {
        *(void**)mem = this->p;
        f4a4440((char*)mem + 4, (char*)this + 4);
    } else {
        mem = 0;
    }
    *(void**)((char*)this + 0x44) = mem;
    f4a3360((char*)this + 4);
}
