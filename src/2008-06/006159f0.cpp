// from server: 100% by colin
struct S_func_006159f0 {
    int f(int a1);
};

int S_func_006159f0::f(int a1)
{
    *(int*)((char*)this + 8) = -1;
    *(int*)((char*)this + 12) = -1;
    *(int*)((char*)this + 16) = 0;
    *(char*)((char*)this + 20) = 0;
    *(int*)((char*)this + 0) = 0x8439fc;
    *(int*)((char*)this + 4) = 0x8439e0;
    *(int*)((char*)this + 24) = a1;
    return (int)this;
}
