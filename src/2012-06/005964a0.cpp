// from server: 49% by atomic.potato
struct S
{
    int f();
    int value[42];
};

extern "C" int sub_499fe0(int *);
extern "C" int sub_759f50(S *, int *);

int S::f()
{
    int value = sub_499fe0(&this->value[42]);
    sub_759f50(this, &value);
    return 0;
}
