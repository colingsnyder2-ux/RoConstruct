// from server: 69% by atomic.potato
extern "C" void __cdecl free(void*);

struct S {
    char pad0[4];
    char* field4;
    char* field8;
    char padC[4];
    unsigned int field10;
};

void __cdecl func(S* s) {
    if (s) {
        unsigned int i = 0;
        while (i < s->field10) {
            s->field8 += 4;
            if (s->field8 == s->field4) {
                s->field8 = *(char**)s;
            }
            ++i;
        }
        if (*(void**)s) {
            free(*(void**)s);
        }
        free(s);
    }
}
