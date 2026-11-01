// from server: 100% by king_originala
extern char descriptor;

struct S {
    char padding[0x1e8];
    bool enabled : 1;

    void notify(const char&);
    void setEnabled(bool value);
};

void S::setEnabled(bool value)
{
    if (enabled != value) {
        enabled = value;
        notify(descriptor);
    }
}
