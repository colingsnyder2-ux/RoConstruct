// from server: 77% by atomic.potato
struct S
{
    int f();
};

int __fastcall CallA(void *);
int __fastcall CallB(void *, int *);

int S::f()
{
    int value = CallA((char *)this + 0xc0);
    return CallB(this, &value);
}
