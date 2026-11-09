// from server: 40% by atomic.potato
struct S {
    char pad[0x1c];
    char str[0x1c];
    void f(char* a, char* b, char* c, char* d);
};

extern "C" void __stdcall copy_string(char* dst, const char* src);

void S::f(char* a, char* b, char* c, char* d)
{
    char tmp1[0x1c];
    char tmp2[0x1c];
    copy_string(tmp1, this->str);
    copy_string(tmp2, (char*)this);
    char* p = *(char**)d;
    char* q = *(char**)p;
    char* r = *(char**)c;
    char* s = *(char**)r;
    ((void (__stdcall*)(char*))s)(q);
}
