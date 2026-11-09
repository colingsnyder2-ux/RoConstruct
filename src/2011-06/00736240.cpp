// from server: 72% by atomic.potato




struct Sub {
    char pad0[0x78];
    int field78;
};

struct TextureContentProvider {
    char pad0[0x40];
    Sub sub;
    char pad1[0x30];
    unsigned int count_b4;
    unsigned int count_b8;
    void method_72d780();
    void method_735450();
    void func(int);
};

void TextureContentProvider::func(int) {
    count_b8++;
    if (count_b8 >= count_b4) {
        sub.field78 = 0;
        method_72d780();
        method_735450();
    }
}
