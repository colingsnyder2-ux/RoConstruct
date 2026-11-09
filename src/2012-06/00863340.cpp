// from server: 93% by Intel
extern "C" void __stdcall CloseHandle(int);

struct VWiniInetRequest_source_stream_buffer {
    int* field_0;
    VWiniInetRequest_source_stream_buffer* func(int);
};

VWiniInetRequest_source_stream_buffer* VWiniInetRequest_source_stream_buffer::func(int arg) {
    int* current = field_0;
    if (current) {
        if (current != (int*)-1) {
            CloseHandle((int)current);
        }
    }
    field_0 = (int*)arg;
    return this;
}
