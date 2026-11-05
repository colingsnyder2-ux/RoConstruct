// from server: 19% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct String {
    char pad[0x1c];
    String();
    String(const char*);
    String(const String&);
    ~String();
    String& operator=(const String&);
    void resize(unsigned int);
};

struct RefCounted {
    void AddRef();
    void Release();
};

struct Instance {
    char pad[0xc8];
};

struct Value {
    char pad[0xc0];
};

struct List {
    char pad[4];
    void* begin;
    void* end;
};

struct ScoreHud {
    char pad[0x108];
    void* field108;
    void update(int a, int b);
    void addEntry(const String& s);
    void method61db20(const String& s);
    void method620bb0(int a, int b);
};

extern "C" void __stdcall sub_492ab0(void*);
extern "C" void __stdcall sub_53e7a0(void*, void*);
extern "C" void __stdcall sub_630d36(void*, void*, void*, void*, void*);
extern "C" void __stdcall sub_4f3980(void*, void*);
extern "C" int __stdcall sub_40ccc0(void*);
extern "C" int __stdcall sub_487c10(void*);

extern void* g_8c7e28;

void ScoreHud::update(int a, int b)
{
    void* local24;
    sub_492ab0(&local24);
    int idx = 0;
    int off = 0;
    while (true) {
        void* p = local24;
        void* begin = *(void**)((char*)p + 4);
        if (!begin) break;
        void* end = *(void**)((char*)p + 8);
        int count = ((char*)end - (char*)begin) >> 3;
        if ((unsigned)count <= (unsigned)idx) break;
        void* elem = (char*)begin + idx * 8;
        void* obj = *(void**)elem;
        String s;
        sub_53e7a0(obj, &s);
        void* r = 0;
        if (obj) {
            void* v = *(void**)((char*)obj + 0xc0);
            if (v) {
                void* vb = *(void**)((char*)v + 4);
                if (vb) {
                    void* ve = *(void**)((char*)v + 8);
                    r = (void*)(((char*)ve - (char*)vb) >> 3);
                }
            }
        }
        int cnt = 0;
        void* pb = *(void**)((char*)p + 4);
        if (pb) {
            void* pe = *(void**)((char*)p + 8);
            cnt = ((char*)pe - (char*)pb) >> 3;
        }
        method620bb0(cnt, (int)r + 1);
        String s2;
        sub_53e7a0((void*)0x7bcffc, &s2);
        method61db20(s2);
        int n = sub_487c10(obj);
        for (int i = 0; i < n; i++) {
            void* v = *(void**)((char*)obj + 0xc0);
            void* vb = *(void**)((char*)v + 4);
            void* item = *(void**)((char*)vb + i * 8);
            String s3;
            sub_53e7a0((char*)item + 0xc8, &s3);
            method61db20(s3);
        }
        idx++;
        off += 0x10;
    }
    int n = sub_40ccc0(local24);
    for (int i = 0; i < n; i++) {
        void* v = *(void**)((char*)local24 + 4);
        void* item = *(void**)((char*)v + i * 0x10);
        if (*(int*)((char*)item + 0x14) > 0x10) {
            void* v2 = *(void**)((char*)local24 + 4);
            void* item2 = *(void**)((char*)v2 + i * 0x10);
            void* p2 = *(void**)((char*)item2 + 4);
            sub_630d36(p2, 0, (void*)0x881f4c, (void*)0x8b386c, 0);
        }
    }
}
