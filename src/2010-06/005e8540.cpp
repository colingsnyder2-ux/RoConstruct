// from server: 71% by atomic.potato
struct S {
    char f(int);
};

extern "C" char __stdcall sub_5e83d0(void*, char*);

char S::f(int a) {
    char buf[16];
    *(int*)(buf + 8) = a;
    char* p = buf + 4;
    char* q = buf + 3;
    buf[3] = 1;
    *(void**)(buf + 4) = (void*)0x5e7300;
    *(char**)(buf + 12) = q;
    sub_5e83d0(p, q);
    return buf[3];
}
