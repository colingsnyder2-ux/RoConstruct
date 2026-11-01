// from server: 100% by king_originala
extern const float landedDuration;

struct First
{
    virtual void first();
};

struct Second
{
    virtual void second();
};

struct Base : First, Second
{
    unsigned int state;

    Base(void* owner);
};

struct Duration
{
    float duration;

    Duration();
};

__forceinline Duration::Duration()
    : duration(landedDuration)
{
}

struct Landed : Base, Duration
{
    Landed(void* owner);
    virtual void first();
    virtual void second();
};

Landed::Landed(void* owner)
    : Base(owner), Duration()
{
}
