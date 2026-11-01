// from server: 100% by atomic.potato
struct UString_sink_stream_buffer {
    char pad0[0x14];
    void* field14;
    void dtor_helper();
    void cleanup();
};

extern "C" void __cdecl sub_614D20();
extern void* g_89e638;
extern void* g_89e63c;
extern void* g_89e640;

void UString_sink_stream_buffer::cleanup()
{
    dtor_helper();
    field14 = g_89e640;
    field14 = g_89e63c;
    ((void (__cdecl*)(void*))g_89e638)(&field14);
}
