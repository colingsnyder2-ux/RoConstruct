// from server: 61% by atomic.potato
struct S {
    void __cdecl f(S* first, S* last, void (__stdcall *fn)(void*));
};

void S::f(S* first, S* last, void (__stdcall *fn)(void*))
{
    S* p = first;
    while (p != last) {
        void* arg;
        if (p != 0)
            arg = (char*)p - 0x34;
        else
            arg = 0;
        fn(arg);
        p = *(S**)p;
    }
    first = last;
    *(S**)this = first;
    *(void (__stdcall **)(void*))((char*)this + 4) = fn;
}
