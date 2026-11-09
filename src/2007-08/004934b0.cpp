// from server: 56% by tajop
struct S {
    virtual ~S();
    int m4;
    void* first;
    void* last;
    void* end;
};

S::~S()
{
    if (first)
        operator delete(first);
    first = 0;
    last = 0;
    end = 0;
}
