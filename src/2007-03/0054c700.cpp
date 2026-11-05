// from server: 100% by tester
struct UString_sink_stream_buffer
{
    int getFlag() const;
};

int UString_sink_stream_buffer::getFlag() const
{
    return (*(unsigned int*)((char*)this + 0x5c) >> 4) & 1;
}