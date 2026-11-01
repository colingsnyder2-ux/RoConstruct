// from server: 100% by king_originala
#pragma optimize("", off)

struct Bucket;

struct Result
{
    void* container;
    void** position;

    int f(const Result& other) const;
    Result offset(int distance) const;
};

struct Bucket
{
    unsigned char padding[12];
    void* value;

    int check() const;
    Result get();
    void update(void* container, void** position, int flag, int argument);
    Result target(Result iterator, int argument);
};

Result Bucket::target(Result iterator, int argument)
{
    int distance = !check() ? 0 : iterator.f(get());
    update(iterator.container, iterator.position, 1, argument);
    return get().offset(distance);
}
