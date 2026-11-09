// from server: 100% by why2
struct XOleCommandTarget {
    char pad[0x100];
    int sub_719224();
};

int __stdcall f(XOleCommandTarget* p)
{
    return ((XOleCommandTarget*)((char*)p - 0xF0))->sub_719224();
}
