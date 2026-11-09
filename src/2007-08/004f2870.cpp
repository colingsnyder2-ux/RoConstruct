// from server: 15% by colin
extern "C" {
    int __stdcall InterlockedDecrement(int volatile*);
    int __stdcall InterlockedIncrement(int volatile*);
    void __cdecl _invalid_parameter_noinfo();
}

extern int dword_8B5188;
extern int dword_897A60;
extern int dword_8BFBE0;
extern void* dword_77E6D8;
extern void* dword_77D2E8;
extern void* dword_77D2EC;

void __cdecl sub_4FCC00(void*, int);
void __cdecl sub_4F1D60(void*, void*, void*, void*, void*);
void __cdecl sub_4F0740(void*, void*, void*, void*, void*);
void __cdecl sub_4FC880(void*, int);
void __cdecl sub_4F2000(void*, void*);
void __cdecl sub_4CD890(void*);
void __cdecl sub_4EF860(void*, int, int);
void __cdecl sub_4EFC00(void*, void*);
void __cdecl sub_4F1E60(void*, void*, void*, void*);
void __cdecl sub_4FBA10(void*);
void __cdecl sub_4FBE30(void*, void*);
void* __cdecl sub_62FEF6(unsigned int);
void __cdecl sub_62FC62(void*);

struct AggregatingSceneManager {
    char pad[0xc];
    void* vec_begin;
    void* vec_end;
    void* vec_cap;
    void method(int, int, int);
};

void AggregatingSceneManager::method(int a, int b, int c)
{
    int count = 0;
    if (vec_begin) {
        count = ((char*)vec_end - (char*)vec_begin) >> 2;
    }
    if ((unsigned)(count * 4) < (unsigned)dword_897A60) {
        return;
    }
    int n = 0;
    if (vec_begin) {
        n = ((char*)vec_end - (char*)vec_begin) >> 2;
    }
    n = n / dword_897A60;
    int cap = 1;
    int* pcap = &cap;
    if (n > 1) {
        pcap = &n;
    }
    sub_4FCC00((char*)this + 0x28, *pcap);
    void* end = vec_end;
    if (vec_begin > end) {
        ((void(__stdcall*)())dword_77E6D8)();
    }
    void* beg = vec_begin;
    if (beg > vec_end) {
        ((void(__stdcall*)())dword_77E6D8)();
    }
    sub_4F1D60((char*)this + 0x28, beg, end, this, this);
    end = vec_end;
    if (vec_begin > end) {
        ((void(__stdcall*)())dword_77E6D8)();
    }
    beg = vec_begin;
    if (beg > vec_end) {
        ((void(__stdcall*)())dword_77E6D8)();
    }
    sub_4F0740((char*)this + 0x28, beg, end, this, this);
    sub_4FC880((char*)this + 0x28, 5);
    void* iter = 0;
    void* it = 0;
    void* itEnd = 0;
    (void)iter; (void)it; (void)itEnd;
    (void)a; (void)b; (void)c;
}
