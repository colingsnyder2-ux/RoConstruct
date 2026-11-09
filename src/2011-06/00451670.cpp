// from server: 60% by atomic.potato
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

void sub_4170C0(void*);
void* sub_401C30();

struct MergeBinder {
    void* field0;
    void Remove();
};

void MergeBinder::Remove() {
    void* p = field0;
    if (p != 0) {
        sub_4170C0(p);
        void* q = sub_401C30();
        EnterCriticalSection(q);
        field0 = *(void**)((char*)q + 0x18);
        *(void**)((char*)q + 0x18) = p;
        LeaveCriticalSection(q);
    }
}
