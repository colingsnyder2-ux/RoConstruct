// from server: 100% by why2
struct XOleCommandTarget {
    char pad[0x100];
    int sub_71921e();
};

int __stdcall f(XOleCommandTarget* p) {
    return ((XOleCommandTarget*)((char*)p - 0xf0))->sub_71921e();
}
