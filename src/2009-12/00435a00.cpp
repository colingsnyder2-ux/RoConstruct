// from server: 100% by atomic.potato
extern "C" int __stdcall XItem(const unsigned char* a, const unsigned char* b)
{
    return *a == *b;
}
