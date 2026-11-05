// from server: 100% by Intel
struct boost_iostreams_DUoutput_V_basic_null_device_stream_buffer {
    int get_flag();
    char pad[0x54];
    unsigned int value;
};

int boost_iostreams_DUoutput_V_basic_null_device_stream_buffer::get_flag() {
    return (value >> 2) & 1;
}
