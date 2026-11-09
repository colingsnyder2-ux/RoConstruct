// from server: 40% by atomic.potato
struct ChatLine {
    char pad0[8];
    void sub_7c9390(int, void*, int, int);
    void func(int*);
};

void ChatLine::func(int* a) {
    int v = *a;
    void* p = &a;
    char b = 0;
    sub_7c9390(v, &p, b, 0);
}
