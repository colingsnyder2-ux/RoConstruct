// from server: 53% by colin
struct CComObjectBase {
    void* vfptr;
    void* field4;
};

struct CComObject {
    void* vfptr;
    void* field4;
    int method(int arg);
};

extern "C" void* __stdcall sub_62FF44();
extern "C" void* __stdcall sub_62FF3E(void*);
extern "C" void* __stdcall sub_62FF02();
extern "C" void __stdcall sub_62FF38(void*, int);
extern "C" int __stdcall sub_448120(void*, int);

int CComObject::method(int arg)
{
    void* p1;
    void* p2;
    int result;
    void* obj;

    p1 = sub_62FF44();
    p2 = sub_62FF3E(p1);
    result = 0;

    obj = sub_62FF02();
    obj = *(void**)((char*)obj + 4);
    result = sub_448120(obj, 0);

    result = (result == 0) ? 0x80004005 : 0x7fffbffb;

    if (p2 != 0) {
        *(void**)((char*)p2 + 4) = p1;
    }

    if (*(void**)((char*)&p2 + 4) != 0) {
        sub_62FF38(*(void**)((char*)&p2 + 8), 0);
    }

    return result;
}
