// from server: 26% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct QListData {
    void* begin;
    void* end;
    void* alloc;
};

struct QStringRef {
    void* d;
    int size;
};

struct QListImpl {
    void* vtable;
    void* begin;
    void* end;
};

struct Notifier {
    void func(int, int);
};

struct VInstance {
    char pad[0xc0];
    void* notifier;
    void func(int, int);
};

void __stdcall helper1(void*);
void __stdcall helper2(void*, void*);
void __stdcall helper3(void*);

void Notifier::func(int a, int b)
{
    VInstance* self = (VInstance*)((char*)this - 0xc0);
    if (self->notifier == 0)
        return;

    QListImpl* list = 0;
    helper1(&list);

    void* it = list->begin;
    void* end = list->end;

    if (it > end)
        _invalid_parameter_noinfo();

    while (it != end) {
        if (it >= list->end)
            _invalid_parameter_noinfo();

        void* item = *(void**)it;
        void* v = *(void**)((char*)item + 0xbc);

        void* tmp[2];
        helper2(tmp, item);
        helper2((char*)tmp + 8, v);

        void* obj = *(void**)((char*)tmp + 0x44);
        helper3((char*)obj + 0x44);

        self->func(a, b);

        if (it >= list->end)
            _invalid_parameter_noinfo();

        it = (char*)it + 8;
    }

    if (list != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)list + 4), -1) == 1) {
            void* vt = *(void**)list;
            void (*fn)(void*) = *(void (**)(void*))((char*)vt + 4);
            fn(list);
            if (_InterlockedExchangeAdd((volatile long*)((char*)list + 8), -1) == 1) {
                void* vt2 = *(void**)list;
                void (*fn2)(void*) = *(void (**)(void*))((char*)vt2 + 8);
                fn2(list);
            }
        }
    }
}
