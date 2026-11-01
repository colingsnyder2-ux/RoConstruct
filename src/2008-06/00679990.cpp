// from server: 100% by king_originala
extern "C" void (__cdecl *_invalid_parameter_noinfo)();
extern void __cdecl release(void *) throw();
extern void __cdecl sort_values(float *, float *, int);
extern const float unavailable;

struct Record {
    float value;
    unsigned char rest[16];
};

struct Buffer {
    void *proxy;
    unsigned int reserved[2];
    float *first;
    float *last;
    float *limit;

    Buffer(int);
    void clear();
    void append(const Record &);
    ~Buffer() throw();
};

struct S {
    int count;
    int reserved;
    Record records[100];

    float median(int);
};

Buffer::~Buffer() throw()
{
    if (first)
        release(first);
    first = 0;
    last = 0;
    limit = 0;
    release(proxy);
}

float S::median(int n)
{
    if (n > 99 || count < n)
        return unavailable;

    Buffer values(n);
    values.clear();

    for (int i = 1; i <= n; ++i)
        values.append(records[(count - i) % 100]);

    float *end = values.last;
    if (values.first > values.last)
        _invalid_parameter_noinfo();

    void *owner = values.proxy;
    float *begin = values.first;
    if (values.first > values.last)
        _invalid_parameter_noinfo();

    if (!owner || owner != values.proxy)
        _invalid_parameter_noinfo();

    sort_values(begin, end, end - begin);

    unsigned int middle = n / 2;
    if (middle >= static_cast<unsigned int>(values.last - values.first))
        _invalid_parameter_noinfo();

    return values.first[middle];
}
