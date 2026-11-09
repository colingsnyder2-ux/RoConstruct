// from server: 100% by atomic.potato
struct BasicPartInstance {
    int f();
};

int BasicPartInstance::f()
{
    return *(int*)((char*)this + 0x280) == 2;
}
