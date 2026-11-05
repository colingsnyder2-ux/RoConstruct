// from server: 64% by atomic.potato
struct WordPair
{
    unsigned short first;
    unsigned short second;
};

extern "C" void __cdecl sub_4e1aa0(void*, unsigned short);

void* __cdecl function_004e1b00(void* value, const WordPair* pair)
{
    sub_4e1aa0(value, pair->first);
    sub_4e1aa0(value, pair->second);
    return value;
}

extern "C" void* __cdecl sub_4f6f60(void*);
extern "C" void __cdecl sub_53feb0(void*, void*);
extern "C" void __cdecl sub_4f19f0(void*, void*);

void __cdecl function_004f8570(void* a, void* b)
{
    char buf[12];
    sub_4f6f60(buf);
    sub_53feb0(buf, buf);
    sub_4f19f0(buf, b);
}
