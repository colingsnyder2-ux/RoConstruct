// from server: 73% by atomic.potato
struct seg_00610000
{
    int __cdecl f(int);
};

extern "C" int __cdecl sub_0061ea90(int);
int sub_0061c5e0(int);

int seg_00610000::f(int value)
{
    return sub_0061c5e0(sub_0061ea90(value));
}
