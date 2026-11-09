// from server: 90% by atomic.potato
struct S
{
    int f();
};

extern "C" int __stdcall sub_006a30c0(void *, void *);

int S::f()
{
    return sub_006a30c0(*(void **)((char *)this + 0x164),
                        (char *)this + 0x0c);
}
