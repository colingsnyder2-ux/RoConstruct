// from server: 100% by king_originala
struct S {
    char padding[16];
    int* finish;

    bool empty();
    void destroy(int* first, int* last);
    void pop_back();
};

#pragma optimize("", off)
void S::pop_back()
{
    if (!empty()) {
        destroy(finish - 1, finish);
        --finish;
    }
}
