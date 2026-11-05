// from server: 44% by atomic.potato
struct AggregateChunk
{
    unsigned char padding[0xa8];
    unsigned char field_a8;
    unsigned char f();
};

unsigned char AggregateChunk::f()
{
    return field_a8;
}
