// from server: 100% by tester
// roc-flags: /Od /Ob1 /GS- /MT
struct It {
    void* node;
    void* tree;
    It& operator++();
    It operator++(int);
};
It It::operator++(int) { It t = *this; ++*this; return t; }
