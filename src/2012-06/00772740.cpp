// from server: 90% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    *(int*)this = 0x00BAFB5C;
    *((int*)this + 1) = 0x00BAFB50;
    *((int*)this + 6) = 0x00BAFB44;
    *((int*)this + 7) = 0x00BAFB38;
}
