// from server: 100% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    int* p = *(int**)((char*)this + 0xf0);
    int* v = *(int**)p;
    int (__thiscall *fn)(int*, int*) = *(int (__thiscall **)(int*, int*))((char*)v + 0x1c);
    return fn(v, p);
}
