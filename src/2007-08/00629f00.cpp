// from server: 100% by colin
struct S {
};

extern int __cdecl sub_00629EA0(int*, char*, int);

int __cdecl f(char* p)
{
    unsigned int len;
    char* data;
    int result;

    len = *(unsigned int*)(p + 0x14);
    if (*(unsigned int*)(p + 0x18) >= 0x10) {
        data = *(char**)(p + 4);
    } else {
        data = p + 4;
    }

    result = 0;
    sub_00629EA0(&result, data, len);
    return result;
}
