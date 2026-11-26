// from server: 100% by Xemicl
// copied from an identical function in another client (function ?dispatch@ns_ROCX000004@@YGHHHHHHH@Z)

namespace ns_ROCX000004 {
struct S {
    int forward(int a, int b, int c, int d, int e);
};

extern S globalObject;

int __stdcall dispatch(int unused, int a, int b, int c, int d, int e)
{
    return globalObject.forward(a, b, c, d, e);
}
}
