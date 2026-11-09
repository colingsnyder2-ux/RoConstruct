// from server: 25% by atomic.potato
struct ManualGlueJoint
{
    void f(int, int, int*, int*);
};

void ManualGlueJoint::f(int a, int b, int* c, int* d)
{
    *(int*)((char*)this + 4) = a;
    *(int*)((char*)this + 0) = 0xabd07c;
    *(int*)((char*)this + 8) = b;
    *(int*)((char*)this + 0xc) = *c;
    *(int*)((char*)this + 0x10) = *d;
    *(int*)((char*)this + 0) = 0xabd0ac;
}
