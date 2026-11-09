// from server: 100% by atomic.potato
typedef void (__thiscall *StringDtorFn)(void *);

extern StringDtorFn const g_stringDtor;

extern "C" void __cdecl raw_free(void *p);

void __cdecl dispose_buffer(void *p) {
    if (p) {
        g_stringDtor(p);
        raw_free(p);
    }
}
