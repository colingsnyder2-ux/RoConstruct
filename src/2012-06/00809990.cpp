// from server: 16% by Intel
struct String {
    void* vftable;
    char _pad[24];
    String() {}
    String(const char*) {}
    String(const String&) {}
    ~String() {}

    int Function(int a2, int a3, int a4, int a5, int a6);
};

extern "C" int __stdcall StringCompare(const String*, const String*);
extern "C" void __cdecl LogFunction(int, const char*, int);
extern "C" void __stdcall VectorPushBack(void*, int*);
extern "C" void __stdcall VectorDestructor(void*);
extern "C" void __stdcall UnknownCall(void*);
extern "C" void __stdcall FreeMemory(void*);

int __stdcall sub_7AB080(int, int*, int);
int __stdcall sub_972290(const char*, int);
int __stdcall sub_982114(int);

int String::Function(int a2, int a3, int a4, int a5, int a6) {
    int v1 = 0;
    int v2 = 1;
    if (*(char*)0xE580B3) {
        if (!*reinterpret_cast<int*>(this)) {
            int (__cdecl *func)(int, int, int) = reinterpret_cast<int (__cdecl*)(int, int, int)>(*(int*)0xE5809C);
            if (func) {
                func(100, 0xBC4740, 0xBC488C);
            }
            sub_972290(reinterpret_cast<const char*>(0xBC4820), *(unsigned char*)0xE580B3);
        }
        if (*(char*)0xE580B3) {
            String s1(reinterpret_cast<const char*>(0xB722EC));
            String s2(reinterpret_cast<const char*>(a5));
            if (StringCompare(&s1, &s2)) {
                int (__cdecl *func2)(int, int, int) = reinterpret_cast<int (__cdecl*)(int, int, int)>(*(int*)0xE5809C);
                if (func2) {
                    func2(101, 0xBC4740, 0xBC480C);
                }
                sub_972290(reinterpret_cast<const char*>(0xBC4798), *(unsigned char*)0xE580B3);
            }
        }
    }
    int v4 = a4 - a3;
    int eax = 0x92492493 * v4;
    int edx = (eax + v4) >> 4;
    eax = edx >> 31;
    int v5 = edx + eax;
    if (v5 > v2) {
        int ebx = 28;
        int* vec = reinterpret_cast<int*>(*reinterpret_cast<int*>(this));
        while (true) {
            int v6 = sub_7AB080(1, &v1, a3 + ebx);
            int ecx = vec[1];
            int edx2 = vec[2];
            int v7 = (edx2 - ecx) >> 2;
            if (v6 >= v7) break;
            int esi = vec[v6];
            int v8 = a4 - a3;
            eax = 0x92492493 * v8;
            edx = (eax + v8) >> 4;
            eax = edx >> 31;
            v5 = edx + eax;
            ++v2;
            ebx += 28;
            if (v2 >= v5) break;
        }
    }
    int ebx2 = v1;
    int esi2 = *reinterpret_cast<int*>(this) + 16;
    VectorPushBack(reinterpret_cast<void*>(ebx2), &esi2);
    int esi3 = a3;
    v1 = 1;
    v2 = 0;
    if (esi3) {
        int edi = a4;
        if (esi3 != edi) {
            do {
                UnknownCall(reinterpret_cast<void*>(esi3));
                esi3 += 28;
            } while (esi3 != edi);
        }
        FreeMemory(reinterpret_cast<void*>(esi3));
    }
    return ebx2;
}
