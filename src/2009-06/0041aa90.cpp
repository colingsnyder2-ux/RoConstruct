// from server: 100% by why2
extern "C" long (__stdcall *InterlockedDecrement)(long volatile*);

struct CInstanceRecord_CNameItem {
    void Release();
};

void CInstanceRecord_CNameItem::Release() {
    *(int*)this = 0x8afff4;
    InterlockedDecrement((long volatile*)0xa3a1bc);
}
