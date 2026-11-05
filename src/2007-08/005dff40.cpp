// from server: 27% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct AllocNode {
    AllocNode* next;
    AllocNode* prev;
    AllocNode* parent;
    char color;
    char pad[3];
};

struct TreeAlloc {
    AllocNode* head;
    int count;
};

extern "C" AllocNode* __cdecl sub_5a93b0(AllocNode*);
extern "C" void __cdecl sub_5dfc60(void*, int, int);
extern "C" void __cdecl sub_5dfcd0(void*, void*, int);
extern "C" int __cdecl sub_5dfe90(int);
extern "C" void __cdecl sub_62fc62(void*);
extern "C" void* __cdecl sub_56c3b0(void*);
extern "C" void __cdecl sub_56c0a0(void*, int, const char*, int, int);
extern "C" void __cdecl sub_5b3a60(void*, void*, void*, void*, void*);

struct Vec {
    int* begin;
    int* end;
    int* cap;
};

struct VMotorFeature {
    char pad0[0xc];
    Vec v1;
    Vec v2;
    void dump();
};

void VMotorFeature::dump()
{
    TreeAlloc t1, t2, t3, t4;
    Vec a, b;
    int i;
    int j;
    int k;

    sub_5a93b0((AllocNode*)&t1);
    t1.head->color = 1;
    t1.head->next = t1.head;
    t1.head->prev = t1.head;
    t1.head->parent = t1.head;
    t1.count = 0;

    sub_5a93b0((AllocNode*)&t2);
    t2.head->color = 1;
    t2.head->next = t2.head;
    t2.head->prev = t2.head;
    t2.head->parent = t2.head;
    t2.count = 0;

    sub_5a93b0((AllocNode*)&t3);
    t3.head->color = 1;
    t3.head->next = t3.head;
    t3.head->prev = t3.head;
    t3.head->parent = t3.head;
    t3.count = 0;

    sub_5a93b0((AllocNode*)&t4);
    t4.head->color = 1;
    t4.head->next = t4.head;
    t4.head->prev = t4.head;
    t4.head->parent = t4.head;
    t4.count = 0;

    a.begin = 0;
    a.end = 0;
    a.cap = 0;
    sub_5dfc60(&a, 0x10000, 0);

    b.begin = 0;
    b.end = 0;
    b.cap = 0;
    sub_5dfc60(&b, 0x10000, 0);

    for (i = 0; i < 0x10000; i++) {
        int cnt = 0;
        int* p;
        if (this->v1.begin == 0 || i >= (this->v1.end - this->v1.begin) / 4)
            _invalid_parameter_noinfo();
        p = this->v1.begin + i;
        {
            int* q = (int*)*p;
            while (q != 0) {
                q = (int*)q[1];
                cnt++;
            }
        }
        if (a.begin == 0 || i >= (a.end - a.begin) / 4)
            _invalid_parameter_noinfo();
        a.begin[i] = cnt;

        if (this->v1.begin == 0 || i >= (this->v1.end - this->v1.begin) / 4)
            _invalid_parameter_noinfo();
        {
            int* p2 = this->v1.begin + i;
            if (b.begin == 0 || i >= (b.end - b.begin) / 4)
                _invalid_parameter_noinfo();
            b.begin[i] = sub_5dfe90(*p2);
        }
    }

    sub_5dfcd0(a.begin, a.end, (a.end - a.begin) / 4);
    sub_5dfcd0(b.begin, b.end, (b.end - b.begin) / 4);

    {
        void* s = sub_56c3b0(&t1);
        sub_56c0a0(*(void**)s, 1, "CURRENT HASH DISTRIBUTION", 0, 0);
    }

    {
        int idx = 0;
        for (j = 0x10000; j < 0x650000; j += 0x10000) {
            void* s = sub_56c3b0(&t1);
            int val = a.begin[(j / 0x10000) - 1];
            sub_56c0a0(*(void**)s, 1, "Slot: %d      Count: %d", idx, val);
            idx++;
        }
    }

    {
        void* s = sub_56c3b0(&t1);
        sub_56c0a0(*(void**)s, 1, "TOP HASH DISTRIBUTION", 0, 0);
    }

    for (k = 0; k < 0x64; k++) {
        void* s = sub_56c3b0(&t1);
        int val = a.begin[0xffff - k];
        sub_56c0a0(*(void**)s, 1, "Slot: %d      Count: %d", k, val);
    }

    {
        void* s = sub_56c3b0(&t1);
        sub_56c0a0(*(void**)s, 1, "TOP GRID COLLISIONS DISTRIBUTION", 0, 0);
    }

    for (k = 0; k < 0x64; k++) {
        void* s = sub_56c3b0(&t1);
        int val = b.begin[0xffff - k];
        sub_56c0a0(*(void**)s, 1, "Slot: %d      Count: %d", k, val);
    }

    if (b.begin != 0) {
        sub_62fc62(b.begin);
        b.begin = 0;
        b.end = 0;
        b.cap = 0;
    }
    if (a.begin != 0) {
        sub_62fc62(a.begin);
        a.begin = 0;
        a.end = 0;
        a.cap = 0;
    }

    {
        void* s = sub_56c3b0(&t4);
        sub_5b3a60(*(void**)s, &t4, &t4, &t4, &t4);
    }
    {
        void* s = sub_56c3b0(&t3);
        sub_5b3a60(*(void**)s, &t3, &t3, &t3, &t3);
    }
    {
        void* s = sub_56c3b0(&t2);
        sub_5b3a60(*(void**)s, &t2, &t2, &t2, &t2);
    }
    {
        void* s = sub_56c3b0(&t1);
        sub_5b3a60(*(void**)s, &t1, &t1, &t1, &t1);
    }
}
