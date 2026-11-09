// from server: 73% by atomic.potato
struct S
{
    char padding[12];
    int value;
    char padding2[460];
    S* next;
    bool f(const S&);
};

bool S::f(const S& other)
{
    int value = other.value;
    S* current = this;
    for (;;)
    {
        if (current->value == value)
            return true;
        current = current->next;
        if (!current)
            return false;
    }
}
