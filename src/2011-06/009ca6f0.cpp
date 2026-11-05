// from server: 36% by atomic.potato
struct S {
    int f();
};

int S::f()
{
    return *reinterpret_cast<const unsigned int *>(this) >= 0x3d09000
        ? 0x400
        : 0x200;
}
