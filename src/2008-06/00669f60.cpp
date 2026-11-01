// from server: 100% by atomic.potato
extern "C" void __cdecl sub_669f10(int* out, const char* data, int len);

int __cdecl f(char* p) {
    int len;
    char* data;
    if (*(unsigned int*)(p + 0x18) >= 0x10) {
        len = *(int*)(p + 0x14);
        data = *(char**)(p + 4);
    } else {
        len = *(int*)(p + 0x14);
        data = p + 4;
    }
    int result = 0;
    sub_669f10(&result, data, len);
    return result;
}
