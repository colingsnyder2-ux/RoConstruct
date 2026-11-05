// from server: 84% by atomic.potato
struct S {
    S* next;
};

void* __cdecl f(S* first, S* last, void (__stdcall *fn)(void*))
{
    S* p = first;
    if (p != last) {
        do {
            void* arg = (p != 0) ? (void*)((char*)p - 0x30) : 0;
            fn(arg);
            p = p->next;
        } while (p != last);
    }
    return (void*)fn;
}
