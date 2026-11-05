// from server: 100% by Intel
struct VWiniInetRequest_source {
    int stream_buffer();
};

int VWiniInetRequest_source::stream_buffer() {
    return (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x5C) >> 2) & 1;
}
