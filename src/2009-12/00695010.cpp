// from server: 100% by atomic.potato
struct Tool
{
    int f();
};

int Tool::f()
{
    return *(int*)((char*)this + 0x134) >= 5;
}
