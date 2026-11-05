// from server: 35% by atomic.potato
extern "C" int (__cdecl *g_fn_00b226e4)(const char*, const char*);

struct Elem_004cdd50
{
    char pad[0x1c];
};

struct Iter_004cdd50
{
    Elem_004cdd50* cur;
    Elem_004cdd50* end;
    Elem_004cdd50** out;
    const char* key;
};

void func_004cdd50(Iter_004cdd50* it)
{
    Elem_004cdd50* c = it->cur;
    if (c == it->end)
    {
        *it->out = c;
        return;
    }
    const char* k = it->key;
    int (__cdecl *fn)(const char*, const char*) = g_fn_00b226e4;
    while (!fn((const char*)c, k))
    {
        c = (Elem_004cdd50*)((char*)c + 0x1c);
        it->cur = c;
        if (c == it->end)
            break;
    }
    *it->out = c;
}
