// from server: 73% by atomic.potato
struct S
{
    int __cdecl f(int);
};

extern "C" int __cdecl sub_006b0d20(int);
extern "C" int sub_006ae870(int);

int S::f(int value)
{
    return sub_006ae870(sub_006b0d20(value));
}
