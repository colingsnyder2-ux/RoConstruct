// from server: 57% by atomic.potato
struct S {
    char pad0[8];
    int (__thiscall *fn)(void*, void*);
    char pad1[4];
    void* f(void* a, void* b);
};

void* S::f(void* a, void* b) {
    void* p = a;
    if (p) p = (char*)p - 0x1c;
    else p = 0;
    char buf[16];
    void* r = ((void* (__thiscall*)(void*, void*, void*))fn)((char*)this + 0xc + (int)p, buf, b);
    *(int*)((char*)b + 0) = *(int*)((char*)r + 0);
    *(int*)((char*)b + 4) = *(int*)((char*)r + 4);
    *(int*)((char*)b + 8) = *(int*)((char*)r + 8);
    *(int*)((char*)b + 12) = *(int*)((char*)r + 12);
    return b;
}
