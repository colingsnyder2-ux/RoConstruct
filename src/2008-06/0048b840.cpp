// from server: 100% by king_originala
struct Iterator {
    void* owner;
    const char* position;
    void check(int count);
};

bool equal(const char* first, const char* last, Iterator other)
{
    Iterator checked = other;
    checked.check(last - first);

    const char* cursor = first;
    if (first != last) {
        int offset = other.position - first;
        do {
            if (*cursor != cursor[offset])
                return false;
            ++cursor;
        } while (cursor != last);
    }
    return true;
}
