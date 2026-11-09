// from server: 37% by atomic.potato
struct S_func_008a9b6d {
    void* f(void* a, void* b);
};

extern "C" void* __stdcall HeapReAlloc(void*, unsigned long, void*, unsigned long);

void* S_func_008a9b6d::f(void* a, void* b)
{
    if (a == 0) {
        return (*(void*(__thiscall**)(void*, void*))this)(this, b);
    }
    if (b == 0) {
        (*(void(__thiscall**)(void*, void*))this)(this, a);
        return 0;
    }
    return HeapReAlloc(*(void**)((char*)this + 4), 0, a, (unsigned long)b);
}
