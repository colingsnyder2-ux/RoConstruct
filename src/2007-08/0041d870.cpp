// from server: 90% by colin
struct CNameItem {
    void* field0;
    unsigned char field4;
    void construct();
};

extern "C" void __stdcall EnterCriticalSection(void*);

void CNameItem::construct()
{
    __try {
        EnterCriticalSection(field0);
    } __finally {
    }
    field4 = 1;
}
