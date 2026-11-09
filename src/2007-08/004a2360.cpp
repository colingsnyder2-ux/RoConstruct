// from server: 47% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct ArgStorage {
    void* ptr;
    int   a;
    int   b;
};

struct VecElem {
    int a;
    int b;
    int c;
};

struct Container {
    VecElem* begin;
    VecElem* end;
    VecElem* cap;
};

struct FuncDesc {
    void* vptr;
    Container items;
    int     field10;
};

extern "C" void __cdecl sub_417800();
extern "C" void* __cdecl sub_4A0440(int, int);
extern "C" void* __cdecl sub_4A17F0(void*, void*, void*, void*, void*, int, int, int);
extern "C" void* __cdecl sub_4A1BA0(void*, void*, void*, void*);
extern "C" void* __cdecl sub_4A1EA0(void*, void*, int, void*);
extern "C" void  __cdecl sub_62FC62(void*);
extern "C" void* __cdecl sub_44BA40(void*);

void FuncDesc_method(FuncDesc* self, int a2, int a3, ArgStorage* a4)
{
    ArgStorage local;
    local.ptr = a4->ptr;
    local.a   = a4->a;
    local.b   = a4->b;

    if (local.b != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)local.ptr + 4), 1);
    }

    int count = 0;
    if (self->items.begin != 0) {
        count = (int)((char*)self->items.end - (char*)self->items.begin) / 12;
    }

    if (a3 != 0) {
        int cur;
        if (self->items.begin != 0) {
            cur = 0;
        } else {
            cur = (int)((char*)self->items.end - (char*)self->items.begin) / 12;
        }
        if ((unsigned)(0x15555555 - cur) < (unsigned)a3) {
            sub_417800();
        }

        int cur2;
        if (self->items.begin == 0) {
            cur2 = 0;
        } else {
            cur2 = (int)((char*)self->items.end - (char*)self->items.begin) / 12;
        }
        if ((unsigned)count >= (unsigned)(cur2 + a3)) {
            goto after_grow;
        }

        int half = (unsigned)count >> 1;
        if ((unsigned)(0x15555555 - half) < (unsigned)count) {
            count = 0;
        } else {
            count = count + half;
        }

        int cur3;
        if (self->items.begin == 0) {
            cur3 = 0;
        } else {
            cur3 = (int)((char*)self->items.end - (char*)self->items.begin) / 12;
        }
        if ((unsigned)count < (unsigned)(cur3 + a3)) {
            void* r = sub_44BA40(self);
            count = (int)r + a3;
        }

        void* mem = sub_4A0440(count, 0);
        void* p = sub_4A17F0(mem, self->items.begin, self->items.end, self, mem, a2, 0, 0);
        void* q = sub_4A1EA0(self, p, a3, &local);
        void* r2 = sub_4A17F0(self->items.end, self->items.begin, self->items.end, self, q, a2, 0, 0);

        int cur4;
        if (self->items.begin == 0) {
            cur4 = 0;
        } else {
            cur4 = (int)((char*)self->items.end - (char*)self->items.begin) / 12;
        }
        a3 = a3 + cur4;

        if (self->items.begin != 0) {
            sub_4A1BA0(self->items.begin, self->items.end, self, r2);
            sub_62FC62(self->items.begin);
        }

        self->items.cap   = (VecElem*)((char*)q + count * 12);
        self->items.end   = (VecElem*)((char*)q + a3 * 12);
        self->items.begin = (VecElem*)q;
        goto done;
    }

after_grow:
    {
        void* p = sub_4A17F0(self->items.end, self->items.begin, self->items.end, self, self->items.end, a2, 0, 0);
        void* q = sub_4A1EA0(self, p, a3, &local);
        void* r2 = sub_4A17F0(self->items.end, self->items.begin, self->items.end, self, q, a2, 0, 0);

        int cur4;
        if (self->items.begin == 0) {
            cur4 = 0;
        } else {
            cur4 = (int)((char*)self->items.end - (char*)self->items.begin) / 12;
        }
        a3 = a3 + cur4;

        if (self->items.begin != 0) {
            sub_4A1BA0(self->items.begin, self->items.end, self, r2);
            sub_62FC62(self->items.begin);
        }

        self->items.cap   = (VecElem*)((char*)q + count * 12);
        self->items.end   = (VecElem*)((char*)q + a3 * 12);
        self->items.begin = (VecElem*)q;
    }

done:
    if (local.b != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)local.ptr + 4), -1);
    }
}
