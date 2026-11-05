// from server: 100% by colin
namespace ns_ROCX000009 {
struct S {
    int value;
    S(int);
};

#pragma optimize("", off)
S::S(int v)
{
    value = v;
}
}
