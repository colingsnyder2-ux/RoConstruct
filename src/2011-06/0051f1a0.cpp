// from server: 100% by atomic.potato
struct S {
    int f(int* p);
};

int S::f(int* p)
{
    *(int*)((char*)this + 0) = *(int*)0xc2f9b8;
    *(int*)((char*)this + 4) = *(int*)0xc2f9bc;
    *(unsigned short*)((char*)this + 8) = *(unsigned short*)0xc2f9c0;
    *(int*)((char*)this + 0x10) = *(int*)p;
    *(unsigned short*)((char*)this + 0x14) = *(unsigned short*)((char*)p + 4);
    *(unsigned short*)((char*)this + 0x16) = *(unsigned short*)((char*)p + 6);
    return (int)this;
}
