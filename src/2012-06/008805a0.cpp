// from server: 44% by atomic.potato
typedef unsigned int DWORD;

struct StringStream;
struct String;

int __stdcall StringStream_str(const StringStream *);

struct StringStream
{
    char data[136];
};

struct S
{
    int f(StringStream *);
};

int S::f(StringStream *stream)
{
    StringStream *p = (StringStream *)((char *)this + 136);
    return (int)StringStream_str(p);
}
