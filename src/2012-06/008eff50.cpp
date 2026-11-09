// from server: 51% by atomic.potato
struct RBX_AdvLuaDragger {
    char pad[8];
    int* end;
    void assign(int** out, int* first, int* last);
};

void RBX_AdvLuaDragger::assign(int** out, int* first, int* last)
{
    *out = first;
    if (first != last) {
        int* p = this->end;
        if (last != p) {
            do {
                *first = *last;
                ++last;
                ++first;
            } while (last != p);
        }
        this->end = first;
    }
}
