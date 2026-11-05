// from server: 100% by king_originala
struct Stream
{
    void write(const void* data, int bits, bool rightAligned);
};

void encode(Stream* stream, unsigned int value)
{
    if (value - 1u <= 2u)
    {
        stream->write(&value, 2, true);
    }
    else
    {
        unsigned char zero = 0;
        stream->write(&zero, 2, true);
        unsigned int fullValue = value;
        stream->write(&fullValue, 32, true);
    }
}
