// from server: 100% by king_originala
struct Iterator {
    void* owner;
    void* position;
};

struct S {
    char padding[16];
    void* finish;

    unsigned size() const;
    unsigned capacity() const;
    Iterator end();
    void* append(void* position, unsigned count, const int& value);
    Iterator insert(Iterator position, const int& value);
    void push_back(const int& value);
};

#pragma optimize("", off)
void S::push_back(const int& value)
{
    if (size() < capacity())
        finish = append(finish, 1, value);
    else {
        Iterator position;
        position = end();
        insert(position, value);
    }
}
#pragma optimize("", on)
