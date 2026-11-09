// from server: 77% by atomic.potato
extern "C" void __cdecl sub_972d70(void *, const char *, const void *);
extern "C" void __cdecl sub_983144(void *, const char *);

extern const char global_b9fa88[];
extern const char global_cd806c[];

void __cdecl function_0083a6e0(const char *value)
{
    char buffer[40];
    sub_972d70(buffer, global_b9fa88, value);
    sub_983144(buffer, global_cd806c);
}
