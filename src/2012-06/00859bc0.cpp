// from server: 100% by Intel
struct UString_sink_stream_buffer {
    int get_flag();
};

int UString_sink_stream_buffer::get_flag() {
    return (static_cast<unsigned int>(*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 88)) >> 2) & 1;
}
