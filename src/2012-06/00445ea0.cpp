// from server: 4% by atomic.potato
typedef void *HANDLE;
typedef unsigned long DWORD;
typedef int BOOL;
typedef unsigned int UINT;
typedef unsigned int UINT_PTR;
typedef long LONG;

extern "C" HANDLE __stdcall OpenEventA(DWORD, BOOL, const char *);
extern "C" DWORD __stdcall GetLastError(void);
extern "C" LONG __stdcall InterlockedIncrement(LONG volatile *);
extern "C" BOOL __stdcall SetEvent(HANDLE);
extern "C" BOOL __stdcall PostMessageA(HANDLE, UINT, unsigned int, int);
extern "C" UINT_PTR __stdcall SetTimer(HANDLE, UINT_PTR, UINT, void *);

struct S {
    char pad0[0x20];
    HANDLE h20;
    char pad24[0xec - 0x24];
    void *p_ec;
    char padf0[0x100 - 0xf0];
    char f100;
    char pad101[0x110 - 0x101];
    char f110;
    char pad111[0x1f4 - 0x111];
    char f1f4;
    char pad1f5[0x2ec - 0x1f5];
    int f2ec;
    int f2f0;
    char pad2f4[0x340 - 0x2f4];
    char f340;
    char pad341[0x470 - 0x341];
    char f470;
    char pad471[0x4b4 - 0x471];
    char f4b4;
    int method(int);
};

int S::method(int arg) {
    if (OpenEventA(0x50008200, 0xe801, (const char *)0) == 0) {
        return -1;
    }
    return 0;
}
