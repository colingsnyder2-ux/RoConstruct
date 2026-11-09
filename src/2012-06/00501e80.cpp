// from server: 58% by tajop



struct Elem72 {
    float v[18];
};

struct Elem72Array {
    Elem72* first_;
    Elem72* last_;
    unsigned int size() const { return (unsigned int)(last_ - first_); }
    Elem72* data() const { return first_; }
};

struct Target {
    void draw(int a, Elem72* first, unsigned int count, int b, int c, int d, int e, int f);
};

struct SpecializedMeshGen {
    char pad[0x48];
    Elem72Array elems_;
    void flush(Target* target, int a, int b, int c, int d, int e, int f);
};

void SpecializedMeshGen::flush(Target* target, int a, int b, int c, int d, int e, int f)
{
    target->draw(a, elems_.data(), elems_.size(), b, c, d, e, f);
}
