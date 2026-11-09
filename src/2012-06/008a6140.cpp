// from server: 56% by atomic.potato
extern "C" void* __cdecl sub_basic_string_ctor(void*, const char*);

struct StudsTool
{
    StudsTool(const char*);
};

StudsTool::StudsTool(const char* value)
{
    sub_basic_string_ctor((char*)this, value);
}
