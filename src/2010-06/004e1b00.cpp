// from server: 100% by atomic.potato
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
