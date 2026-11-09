// from server: 51% by atomic.potato
struct S_0070f000 {
    char pad[8];
    int* end;
    void assign(int** out, int* first, int* last);
};

void S_0070f000::assign(int** out, int* first, int* last)
{
    *out = first;
    if (first != last) {
        int* p = end;
        if (last != p) {
            do {
                *first = *last;
                ++last;
                ++first;
            } while (last != p);
        }
        end = first;
    }
}
