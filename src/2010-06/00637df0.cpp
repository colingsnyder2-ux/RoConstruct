// from server: 100% by atomic.potato
struct P8PartInstance_GetSetImpl {
    void f(int a, float* b);
};

void P8PartInstance_GetSetImpl::f(int a, float* b) {
    char* p;
    if (a != 0)
        p = (char*)a - 0x1c;
    else
        p = 0;
    int esi = *(int*)((char*)this + 0x20);
    float val = *b;
    int ecx = *(int*)(p + 0x98);
    ecx = *(int*)(ecx + esi);
    ecx += *(int*)((char*)this + 0x1c);
    int edx = *(int*)((char*)this + 0x18);
    ecx = ecx + (int)p + 0x98;
    ((void (__thiscall*)(int, float))edx)(ecx, val);
}
