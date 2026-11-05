// from server: 100% by king_originala
extern "C" void (__cdecl* _invalid_parameter_noinfo)();

struct Iterator {
    void* owner;
    unsigned int position;
};

struct Range {
    void* owner;
    unsigned int reserved[2];
    unsigned int first;
    unsigned int last;

    Iterator erase(Iterator first, Iterator last);
};

struct S {
    unsigned char reserved[0xe8];
    unsigned int last;

    void f();
};

void S::f()
{
    Iterator finish;
    finish.position = last;

    Range* range = reinterpret_cast<Range*>(reserved + 0xd8);
    if (range->first > finish.position)
        _invalid_parameter_noinfo();

    Iterator start;
    start.position = range->first;
    finish.owner = range->owner;

    if (start.position > range->last)
        _invalid_parameter_noinfo();

    start.owner = range->owner;
    range->erase(start, finish);
}
