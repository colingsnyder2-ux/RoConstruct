// from server: 100% by atomic.potato
extern "C" const char G1_sym_00477120[];
extern "C" int __stdcall G1_func_00405560(const char *, const char *, const char *, const char *);

int __stdcall func_00477120(const char *a, const char *b, const char *c)
{
    return G1_func_00405560(a, G1_sym_00477120, b, c);
}
