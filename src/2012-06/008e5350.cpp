// from server: 36% by atomic.potato
struct P8SelectionPointLasso_GetSetImpl {
    void f(int a, int b, int c);
};

void P8SelectionPointLasso_GetSetImpl::f(int a, int b, int c)
{
    int* p = (int*)a;
    int* q;
    if (p)
        q = p - 7;
    else
        q = 0;

    int* r = (int*)c;
    int v0 = r[0];
    int v1 = r[1];
    int v2 = r[2];

    int off = *(int*)((char*)this + 0x14);
    int fn = *(int*)((char*)this + 0x10);
    off += (int)q;

    typedef void (__thiscall *Fn)(int, int, int);
    ((Fn)fn)(v0, v1, v2);
}
