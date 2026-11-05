// from server: 100% by king_originala
struct S;
extern "C" void __stdcall prepare(S *);
extern unsigned char descriptor;

struct S {
    unsigned char padding[0x168];
    int value;

    void setValue(int);
    void setAutomatic();
    void clear();
    void notify(const void *);
};

void S::setValue(int n)
{
    if (n == -1) {
        setAutomatic();
        return;
    }
    if (n == 0) {
        clear();
        return;
    }
    if (n > value) {
        prepare(this);
        value = n;
        notify(&descriptor);
    }
}
