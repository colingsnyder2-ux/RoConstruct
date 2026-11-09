// from server: 23% by atomic.potato
struct GfxBinding {
    char pad[12];
    int* begin;
    int* end;
    bool empty() const;
};

bool GfxBinding::empty() const {
    int* b = begin;
    int* e = end;
    int diff = (int)(e - b);
    int nonzero = (diff != 0);
    return nonzero == 0;
}
