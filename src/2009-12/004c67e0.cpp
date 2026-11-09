// from server: 48% by atomic.potato
typedef int streampos_value;

extern "C" void __stdcall clear_ios(void*, int, bool);
extern "C" streampos_value __stdcall tellg_istream(void*, streampos_value*);

struct istreamDataStream_004c67e0
{
    char reserved[0x24];
    void* stream;

    int f();
};

int istreamDataStream_004c67e0::f()
{
    streampos_value position;
    clear_ios(stream, 0, false);
    tellg_istream(stream, &position);
    return position;
}
