// from server: 100% by king_originala
extern "C" unsigned int __cdecl strlen(const char*);
extern long __cdecl checkValue(void*);
extern bool __cdecl checkAllowed(void*);

struct B
{
    void navigate(const char*, unsigned long, const char*, void*, const char*, int*);
};

struct S : B
{
    void navigate(const char*, unsigned long, const char*, void*, const char*, int*);
};

void S::navigate(const char* url, unsigned long flags, const char* target,
                 void* data, const char* headers, int* cancel)
{
    B::navigate(url, flags, target, data, headers, cancel);
    if (strlen(target) == 0 && checkValue((void*)url) &&
        !checkAllowed((void*)url))
        *cancel = 1;
}
