// from server: 91% by atomic.potato
struct Row {
    int a;
    int b;
    char pad[0x10];
};

extern "C" void __fastcall sub_5a9430(void* dst, void* src);

void copy_rows(Row* dst, Row* end, Row* src)
{
    while (dst != end) {
        dst->a = src->a;
        dst->b = src->b;
        sub_5a9430((char*)dst + 8, (char*)src + 8);
        dst = (Row*)((char*)dst + 0x18);
    }
}
