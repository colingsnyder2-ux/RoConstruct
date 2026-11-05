// from server: 67% by atomic.potato
struct S {
    char pad[0x18];
    int (__stdcall *fn)(int);
    int offset1c;
    int offset20;
    int method(int* a, int* b);
};

int S::method(int* a, int* b) {
    int* p = a;
    if (p != 0) {
        p = (int*)((char*)p - 0x1c);
    } else {
        p = 0;
    }
    int idx = *b;
    int esi = *(int*)((char*)this + 0x20);
    int ecx = *(int*)((char*)p + 0x148);
    ecx = *(int*)((char*)ecx + esi);
    ecx += *(int*)((char*)this + 0x1c);
    int (__stdcall *f)(int) = *(int (__stdcall **)(int))((char*)this + 0x18);
    ecx = (int)((char*)p + 0x148 + ecx);
    return f(ecx);
}
