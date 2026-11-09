// from server: 68% by atomic.potato
struct S
{
    int f();
    char pad[0x178];
};

int __cdecl sub_664370(void *);

int S::f()
{
    sub_664370((void *)(this->pad + 0x178));
    return sub_664370((void *)(this->pad + 0x180));
}
