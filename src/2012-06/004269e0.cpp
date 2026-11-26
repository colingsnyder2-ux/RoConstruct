// from server: 100% by Xemicl
// copied from an identical function in another client (function ?f@ns_ROCX000003@@YGHPAUXOleCommandTarget@1@@Z)

namespace ns_ROCX000003 {
struct XOleCommandTarget {
    char pad[0x100];
    int sub_71921e();
};

int __stdcall f(XOleCommandTarget* p) {
    return ((XOleCommandTarget*)((char*)p - 0xf0))->sub_71921e();
}
}
