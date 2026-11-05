// from server: 16% by colin
struct RBXName {
    static const RBXName& declare(const char*);
};

struct CreatorBase {
    virtual void v0();
    virtual void v1();
};

struct Creator : CreatorBase {
    Creator();
    ~Creator();
};

struct CreatorList {
    void* begin;
    void* end;
    void* cap;
    void insert(void*, const void*, const void*);
    void* at(unsigned int);
};

extern "C" void __stdcall _invalid_parameter_noinfo();

extern char g_name1;
extern char g_name2;
extern char g_flag1;
extern char g_flag2;
extern int  g_flag3;

extern void __cdecl sub_725520(void*, void*);
extern void __cdecl sub_4918C0();
extern void* __cdecl sub_487170();
extern void* __cdecl sub_52CB30();
extern void __cdecl sub_554DE0();
extern void __cdecl sub_492360();
extern void __cdecl sub_402A60();

CreatorList* getCreators();

Creator::Creator()
{
    sub_725520(&g_name1, (void*)0x492120);
    sub_4918C0();

    CreatorList* creators = getCreators();
    unsigned int idx = 0;
    if (creators->begin != 0) {
        idx = (unsigned int)(((char*)creators->end - (char*)creators->begin) >> 3);
    }
    unsigned int need = idx + 1;
    if (need > idx) {
        if (creators->begin == 0 || idx >= (unsigned int)(((char*)creators->end - (char*)creators->begin) >> 3)) {
            _invalid_parameter_noinfo();
        }
        void* slot = (char*)creators->begin + idx * 8;
        if (*(void**)slot != 0) {
            return;
        }
    }

    if ((g_flag3 & 1) == 0) {
        g_flag3 |= 1;
        sub_725520(&g_name2, (void*)0x4879A0);
        void* a = sub_487170();
        void* b = sub_52CB30();
        g_flag1 = (a == b);
    }

    if (g_flag1 == 0) {
        sub_725520(&g_name2, (void*)0x4879A0);
        void* a = sub_487170();
        void* tmp = 0;
        sub_554DE0();
        if (tmp != 0) {
            void* slot = (char*)creators->begin + idx * 8;
            *(void**)slot = tmp;
            sub_402A60();
        }
    }
}

Creator::~Creator()
{
}
