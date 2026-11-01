// from server: 100% by tester
typedef unsigned int DWORD;
typedef int BOOL;
typedef unsigned int UINT;
typedef unsigned int WPARAM;
typedef long LPARAM;

extern "C" __declspec(dllimport) BOOL __stdcall PostMessageA(void*, UINT, WPARAM, LPARAM);

struct ChatEnter {
    char pad[0x14];
    void* m_pTarget;
    void Process(void* b, void* a);
};

void ChatEnter::Process(void* b, void* a) {
    int* p = (int*)a;
    if (p[0] == 9 && p[2] == 0x2f) {
        void* t = *(void**)((char*)m_pTarget + 0x20);
        PostMessageA(t, 0x468, 0, 0);
        int* r = (int*)b;
        r[0] = 1;
        r[1] = 0;
    } else {
        int* r = (int*)b;
        r[0] = 0;
        r[1] = 0;
    }
}
