// from server: 54% by atomic.potato
extern "C" void sub_008fec40(void*, void*);

struct LuaWriter
{
    char data[32];
    void f(void*);
};

void LuaWriter::f(void* p)
{
    sub_008fec40(data + 32, &p);
}
