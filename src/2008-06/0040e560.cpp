// from server: 100% by king_originala
struct Receiver {
    void forward(int value);
};

struct CBrowserView {
    char padding[0x54];
    void* receiver;

    void initial(int value);
    Receiver* lookup();
    void method(int value);
};

void CBrowserView::method(int value) {
    initial(value);
    if (receiver) {
        void* p = receiver;
        void** table = *(void***)p;
        void (__thiscall *fn)(void*, int) =
            (void (__thiscall *)(void*, int))table[0x58 / 4];
        fn(p, value);
    } else if (lookup()) {
        lookup()->forward(value);
    }
}
