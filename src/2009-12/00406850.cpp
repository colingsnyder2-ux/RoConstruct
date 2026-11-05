// from server: 100% by nuck16
// roc 2009-12 00406850  (same-shape propagation from exact 004056a0)
// copied from an identical function in another client (function ?sub_404880@ns_ROCX000009@@YGHHHH@Z)

namespace ns_ROCX000009 {
extern "C" int __stdcall sub_4022a0(int, void*, int, int);

extern int G_784f68;

int __stdcall sub_404880(int a1, int a2, int a3)
{
    return sub_4022a0(a1, &G_784f68, a2, a3);
}
}
