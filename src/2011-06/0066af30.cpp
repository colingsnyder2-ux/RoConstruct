// from server: 100% by atomic.potato
struct S {
    double value();
};

double S::value()
{
    int count = *(int*)((char*)this + 0x10);
    if (count > 0)
        return *(double*)((char*)this + 8) / (double)count;
    return 0.0;
}
