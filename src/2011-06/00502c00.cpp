// from server: 77% by atomic.potato
struct S
{
    int f();
};

extern int __fastcall sub_502c30(int *);
extern int __fastcall sub_65bd40(S *, int *);

int S::f()
{
    int value = sub_502c30((int *)((char *)this + 0xb8));
    return sub_65bd40(this, &value);
}
