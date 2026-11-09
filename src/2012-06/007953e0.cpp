// from server: 58% by colin
struct S {
    int f();
};

int S::f()
{
    *(int*)((char*)this + 0) = 0xbb3764;
    *(int*)((char*)this + 4) = 0xbb3758;
    *(int*)((char*)this + 0x18) = 0xbb374c;
    *(int*)((char*)this + 0x1c) = 0xbb3740;
    return ((int (__stdcall *)(void*))0x685090)(this);
}
