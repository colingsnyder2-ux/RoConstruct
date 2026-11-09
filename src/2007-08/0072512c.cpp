// from server: 37% by Yeetserama
struct CXTIconHandle {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    int method(int a1, int a2);
};

extern "C" int __stdcall HeapReAlloc(int, int, int, int, int);

int CXTIconHandle::method(int a1, int a2)
{
    if (a1 == 0) {
        int (__stdcall *fn)(int) = *(int (__stdcall **)(int))this;
        return fn(a2);
    }
    if (a2 == 0) {
        int (__stdcall *fn)(int) = *(int (__stdcall **)(int))((char*)this + 4);
        fn(a1);
        return 0;
    }
    return HeapReAlloc(0, 0, field4, a1, a2);
}
