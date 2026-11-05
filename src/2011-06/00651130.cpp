// from server: 85% by atomic.potato
struct Source
{
    char pad0[24];
    unsigned int size;
    char pad1[4];
    char *data;
};

extern "C" char *__cdecl sub_0064f230(char *, char *);

int __cdecl sub_00651130(Source *source, char *buffer, int, char **result)
{
    char *p = source->size >= 0x10 ? source->data : (char *)source + 4;
    char *value = sub_0064f230(buffer, p);
    *result = *(char **)value;
    return 1;
}
