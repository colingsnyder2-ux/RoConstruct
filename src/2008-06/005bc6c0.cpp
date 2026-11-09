// from server: 100% by king_originala
struct ResourcePair {
    void clear();
};

extern "C" void __stdcall prepare(ResourcePair* pair, ResourcePair** slot);

extern "C" int __stdcall callback(ResourcePair* pair, int, int, int, int)
{
    prepare(pair, &pair);
    if (pair)
        pair->clear();
    return 0;
}
