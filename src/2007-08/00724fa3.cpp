// from server: 49% by colin
struct CXTIconHandle {
    int sub_724fa3(int);
};

struct Inner {
    char pad[0x30];
    int sub_724ed2(int);
};

extern "C" {
    void __stdcall EnterCriticalSection(void*);
}

struct Lock {
    void* cs;
    char flag;
    void sub_41db80();
};

int CXTIconHandle::sub_724fa3(int idx)
{
    Lock lock;
    lock.cs = (char*)this + 0x18;
    EnterCriticalSection((char*)this + 0x18);
    int count = *(int*)((char*)this + 0x34);
    lock.flag = 1;
    int result;
    if (idx > count || idx < 0) {
        lock.sub_41db80();
        result = 0;
    } else if (idx == count) {
        int v = *(int*)((char*)this + 8);
        lock.sub_41db80();
        result = v;
    } else {
        int v = ((Inner*)((char*)this + 0x30))->sub_724ed2(idx);
        int r = *(int*)v;
        lock.sub_41db80();
        result = r;
    }
    return result;
}
