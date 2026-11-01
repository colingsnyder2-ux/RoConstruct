// from server: 100% by colin
extern "C" int __stdcall sub_630010(void* p);

struct S {
    int field0;
    unsigned int flags;
};

void __stdcall func(S* p)
{
    if (sub_630010(p) == 0)
        p->flags |= 0x1844014;
}
