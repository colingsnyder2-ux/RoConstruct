// from server: 55% by Intel
typedef int DWORD;

struct VAnimationTrack {
    DWORD data0;
    DWORD data1;
    void* BoundFuncDesc(void* arg1, void* arg2);
};

extern "C" int __stdcall func_4c8700(void* ptr, int val);
extern "C" void __stdcall func_8f7830(VAnimationTrack* instance, int a, int b);

void* VAnimationTrack::BoundFuncDesc(void* arg1, void* arg2) {
    func_4c8700((char*)this + 4, 0);
    DWORD val1 = *(DWORD*)((char*)arg1 + 20);
    DWORD val2 = *(DWORD*)((char*)arg2 + 16);
    func_8f7830(this, val1, val2);
    return arg2;
}
