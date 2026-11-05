// from server: 79% by atomic.potato
struct S {
    char pad0[4];
    void* stream;
    void skip_whitespace();
};

extern "C" int __stdcall sbumpc(void*);
extern "C" int __stdcall sgetc(void*);

extern unsigned char g_table[1];

void S::skip_whitespace() {
    int c;
    for (;;) {
        c = sgetc(stream);
        if (c == -1) break;
        if (g_table[(signed char)c] == 0) break;
        sbumpc(stream);
    }
}
