// from server: 55% by atomic.potato
struct S {
    char pad[0x18];
    int (__thiscall *fn)(void *, float);
    char pad2[0x4];
    int field20;
    int field1c;
    int method(int, float *);
};

int S::method(int a, float *b) {
    S *p;
    if (a != 0) {
        p = (S *)((char *)a - 0x1c);
    } else {
        p = 0;
    }
    int esi = *(int *)((char *)this + 0x20);
    float val = *b;
    int ecx = *(int *)((char *)p + 0x138);
    ecx = *(int *)(ecx + esi);
    ecx += *(int *)((char *)this + 0x1c);
    int (__thiscall *fn)(void *, float) = *(int (__thiscall **)(void *, float))((char *)this + 0x18);
    ecx = (int)((char *)p + 0x138 + ecx);
    return fn((void *)ecx, val);
}
