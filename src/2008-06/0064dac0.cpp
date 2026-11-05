// from server: 100% by king_originala
extern "C" unsigned long __stdcall crc32(
    unsigned long crc, const unsigned char* buffer, unsigned int length);

struct BufferState
{
    const unsigned char* begin;
    unsigned long reserved0;
    unsigned long value0;
    const unsigned char* end;
    unsigned long reserved1;
    unsigned long value1;
};

struct S
{
    BufferState* state;
    bool enabled;
    unsigned long crc;
    unsigned long value0;
    unsigned long value1;

    void update(const unsigned char** first, const unsigned char** last,
                bool useFirst);
};

void S::update(const unsigned char** first, const unsigned char** last,
               bool useFirst)
{
    BufferState* p = state;
    const unsigned char* begin = p->begin;
    const unsigned char* end = p->end;

    if (enabled)
    {
        const unsigned char* buffer;
        unsigned int length;

        if (useFirst)
        {
            buffer = *first;
            length = begin - buffer;
        }
        else
        {
            buffer = *last;
            length = end - buffer;
        }

        if (length > 0)
            crc = crc32(crc, buffer, length);
    }

    value0 = p->value0;
    value1 = p->value1;
    *first = begin;
    *last = end;
}
