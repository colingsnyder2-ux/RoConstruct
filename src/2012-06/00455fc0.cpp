// from server: 47% by Intel
// roc 2012-06 00455fc0  unit: CPropGrid::UpdateItemsJob  size: 280 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00455fc0
//
// 00455fc0  8b442404             mov eax, dword ptr [esp + 4]
// 00455fc4  56                   push esi
// 00455fc5  8bf1                 mov esi, ecx
// 00455fc7  dd8630020000         fld qword ptr [esi + 0x230]
// 00455fcd  dc4008               fadd qword ptr [eax + 8]
// 00455fd0  8b8628020000         mov eax, dword ptr [esi + 0x228]
// 00455fd6  83e800               sub eax, 0
// 00455fd9  dd9e38020000         fstp qword ptr [esi + 0x238]
// 00455fdf  0f84ae000000         je 0x456093
// 00455fe5  83e801               sub eax, 1
// 00455fe8  747a                 je 0x456064
// 00455fea  83e801               sub eax, 1
// 00455fed  0f85dc000000         jne 0x4560cf
// 00455ff3  3805b380e500         cmp byte ptr [0xe580b3], al
// 00455ff9  743d                 je 0x456038
// 00455ffb  8a8e24020000         mov cl, byte ptr [esi + 0x224]
// 00456001  84c9                 test cl, cl
// 00456003  7533                 jne 0x456038
// 00456005  a19c80e500           mov eax, dword ptr [0xe5809c]
// 0045600a  85c0                 test eax, eax
// 0045600c  7415                 je 0x456023
// 0045600e  6a77                 push 0x77
// 00456010  68e83db500           push 0xb53de8
// 00456015  68d83db500           push 0xb53dd8
// 0045601a  ffd0                 call eax
// 0045601c  83c40c               add esp, 0xc
// 0045601f  84c0                 test al, al
// 00456021  7515                 jne 0x456038
// 00456023  0fb615b380e500       movzx edx, byte ptr [0xe580b3]
// 0045602a  68903eb500           push 0xb53e90
// 0045602f  52                   push edx
// 00456030  e85bc25100           call 0x972290
// 00456035  83c408               add esp, 8
// 00456038  8b8618020000         mov eax, dword ptr [esi + 0x218]
// 0045603e  6a00                 push 0
// 00456040  6a00                 push 0
// 00456042  c7862802000000000000 mov dword ptr [esi + 0x228], 0
// 0045604c  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0045604f  6865040000           push 0x465
// 00456054  51                   push ecx
// 00456055  ff15243cb200         call dword ptr [0xb23c24]
// 0045605b  b801000000           mov eax, 1
// 00456060  5e                   pop esi
// 00456061  c20400               ret 4
// 00456064  8b961c020000         mov edx, dword ptr [esi + 0x21c]
// 0045606a  52                   push edx
// 0045606b  ff150c23b200         call dword ptr [0xb2230c]
// 00456071  8b8620020000         mov eax, dword ptr [esi + 0x220]
// 00456077  6aff                 push -1
// 00456079  50                   push eax
// 0045607a  ff15e421b200         call dword ptr [0xb221e4]
// 00456080  c7862802000002000000 mov dword ptr [esi + 0x228], 2
// 0045608a  b801000000           mov eax, 1
// 0045608f  5e                   pop esi
// 00456090  c20400               ret 4
// 00456093  803db380e50000       cmp byte ptr [0xe580b3], 0
// 0045609a  7433                 je 0x4560cf
// 0045609c  a19c80e500           mov eax, dword ptr [0xe5809c]
// 004560a1  85c0                 test eax, eax
// 004560a3  7415                 je 0x4560ba
// 004560a5  6a7d                 push 0x7d
// 004560a7  68e83db500           push 0xb53de8
// 004560ac  680016b500           push 0xb51600
// 004560b1  ffd0                 call eax
// 004560b3  83c40c               add esp, 0xc
// 004560b6  84c0                 test al, al
// 004560b8  7515                 jne 0x4560cf
// 004560ba  0fb60db380e500       movzx ecx, byte ptr [0xe580b3]
// 004560c1  68303eb500           push 0xb53e30
// 004560c6  51                   push ecx
// 004560c7  e8c4c15100           call 0x972290
// 004560cc  83c408               add esp, 8
// 004560cf  b801000000           mov eax, 1
// 004560d4  5e                   pop esi
// 004560d5  c20400               ret 4

typedef unsigned long DWORD;
typedef int BOOL;
typedef void* HWND;
typedef void* HANDLE;

extern "C" BOOL __stdcall SetEvent(HANDLE hEvent);
extern "C" DWORD __stdcall WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds);
extern "C" BOOL __stdcall PostMessageA(HWND hWnd, unsigned int Msg, unsigned int wParam, long lParam);

typedef int (__cdecl *LogFunc_t)(const char*, int);

struct UpdateItemsJob {
    int Execute(void* param);
};

int UpdateItemsJob::Execute(void* param) {
    double* pParam = static_cast<double*>(param);
    double val = *(double*)((char*)this + 0x230);
    val += pParam[1];
    *(double*)((char*)this + 0x238) = val;

    int state = *(int*)((char*)this + 0x228);
    if (state == 0) {
        if (*(unsigned char*)0xE580B3 != 0) {
            unsigned char flag = *(unsigned char*)((char*)this + 0x224);
            if (flag == 0) {
                int (__stdcall *callback)(int, const char*, const char*) = *(int (__stdcall **)(int, const char*, const char*))0xE5809C;
                if (callback) {
                    if (callback(0x77, (const char*)0xB53DE8, (const char*)0xB53DD8)) {
                        return 1;
                    }
                }
                unsigned char gFlag = *(unsigned char*)0xE580B3;
                LogFunc_t logFunc = (LogFunc_t)0x972290;
                logFunc((const char*)0xB53E90, gFlag);
            }
        }
        void* pObj = *(void**)((char*)this + 0x218);
        *(int*)((char*)this + 0x228) = 0;
        HANDLE hEvent = *(HANDLE*)((char*)pObj + 0x20);
        PostMessageA((HWND)hEvent, 0x465, 0, 0);
        return 1;
    }

    if (state == 1) {
        HANDLE hEvent = *(HANDLE*)((char*)this + 0x21C);
        SetEvent(hEvent);
        HWND hWnd = *(HWND*)((char*)this + 0x220);
        PostMessageA(hWnd, 0x465, (unsigned int)-1, 0);
        *(int*)((char*)this + 0x228) = 2;
        return 1;
    }

    if (state == 2) {
        if (*(unsigned char*)0xE580B3 != 0) {
            int (__stdcall *callback)(int, const char*, const char*) = *(int (__stdcall **)(int, const char*, const char*))0xE5809C;
            if (callback) {
                if (callback(0x7D, (const char*)0xB53DE8, (const char*)0xB51600)) {
                    return 1;
                }
            }
            unsigned char gFlag = *(unsigned char*)0xE580B3;
            LogFunc_t logFunc = (LogFunc_t)0x972290;
            logFunc((const char*)0xB53E30, gFlag);
        }
        return 1;
    }

    return 1;
}
