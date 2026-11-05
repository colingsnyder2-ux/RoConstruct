// from server: 23% by atomic.potato
struct GfxBinding {
    char pad[12];
    int* begin;
    int* end;
    bool empty() const;
};

bool GfxBinding::empty() const {
    return end - begin == 0;
}
