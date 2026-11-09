// from server: 50% by atomic.potato
extern "C" int __stdcall getsockopt(unsigned int, int, int, char*, int*);
extern "C" unsigned int __stdcall inet_addr(const char*);
extern "C" int __stdcall setsockopt(unsigned int, int, int, const char*, int);

struct CXTPRichRender_XTextHost
{
    int sub_00564aa0(unsigned int, int, int, int, int, int);
    int func_00564b60(unsigned int, int, int, int, int, int);
};

int CXTPRichRender_XTextHost::func_00564b60(unsigned int a1, int a2, int a3, int a4, int a5, int a6)
{
    int v1;
    int v2;
    int v3;
    int v4;
    int v5;
    int v6;
    int result;

    v1 = 4;
    getsockopt(a1, 0, 4, (char*)&v2, &v1);
    v3 = a2;
    v1 = 4;
    setsockopt(a1, 0, 4, (const char*)&v3, 4);
    v4 = inet_addr((const char*)&v2);
    v5 = v2;
    v6 = v3;
    result = sub_00564aa0(a1, v5, v4, v6, a3, a4);
    v1 = v2;
    setsockopt(a1, 0, 4, (const char*)&v1, 4);
    return result;
}
