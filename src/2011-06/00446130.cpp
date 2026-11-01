// from server: 100% by atomic.potato
extern "C" int __stdcall XItem(const char *a, const char *b);

int __stdcall XItem(const char *a, const char *b)
{
    return *a == *b;
}
