// from server: 100% by atomic.potato
struct S {
    int IsMatch();
};

int S::IsMatch()
{
    if (*((int*)this) == 10 && *((int*)((char*)this + 8)) == 27)
        return 1;
    return 0;
}
