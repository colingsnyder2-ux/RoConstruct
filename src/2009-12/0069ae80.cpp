// from server: 32% by atomic.potato
struct S
{
    char pad[0x50];
    int* value;
    int f();
};

int S::f()
{
    int* p = value;
    if (p)
        return (p[4] - p[3]) >> 3;
    return 0;
}

struct T
{
    char pad[0x50];
    void* field_50;
    char pad2[0x288];
    int field_2DC;
    void func(char);
};

void T::func(char arg)
{
    if (arg != 0)
        return;

    void* p = field_50;
    if (p != 0)
    {
        int n = ((int*)p)[4] - ((int*)p)[3];
        n >>= 3;
        if (n > 0)
        {
            void* q = *(void**)((char*)p + 0xC);
            void* r = *(void**)q;
            if (r != 0)
            {
                char buf[0x50];
                extern void construct_string(void*, const char*);
                construct_string(buf, (const char*)0x9d258c);
                void* out = 0;
                extern void call_632b80(void*, void*);
                call_632b80(r, &out);
                extern void* call_7f4aaa(void*, void*, void*, void*, void*);
                void* res = call_7f4aaa(out, 0, (void*)0xaffe40, (void*)0xb38e28, 0);
                extern void destroy_string(void*);
                destroy_string(buf);
                if (res != 0)
                {
                    extern void call_699da0(void*, void*);
                    call_699da0(this, res);
                    return;
                }
            }
        }
    }

    extern void call_69ad10(void*);
    call_69ad10(this);

    int count = ((S*)this)->f();
    int i = 0;
    if (count > 0)
    {
        do
        {
            void* p2 = field_50;
            int n2 = ((int*)p2)[4] - ((int*)p2)[3];
            n2 >>= 3;
            if (i >= n2)
            {
                extern void invalid_param();
                invalid_param();
            }
            void* item = *(void**)((char*)p2 + 0xC);
            void* v = ((void**)item)[i];
            extern void* call_7f4aaa2(void*, void*, void*, void*, void*);
            void* a = call_7f4aaa2(v, 0, (void*)0xaffe40, (void*)0xb13524, 0);
            void* p3 = field_50;
            int n3 = ((int*)p3)[4] - ((int*)p3)[3];
            n3 >>= 3;
            if (i >= n3)
            {
                extern void invalid_param2();
                invalid_param2();
            }
            void* item3 = *(void**)((char*)p3 + 0xC);
            void* v3 = ((void**)item3)[i];
            extern void* call_7f4aaa3(void*, void*, void*, void*, void*);
            void* b = call_7f4aaa3(v3, 0, (void*)0xaffe40, (void*)0xb2f038, 0);
            void* p4 = field_50;
            int n4 = ((int*)p4)[4] - ((int*)p4)[3];
            n4 >>= 3;
            if (i >= n4)
            {
                extern void invalid_param3();
                invalid_param3();
            }
            void* item4 = *(void**)((char*)p4 + 0xC);
            void* v4 = ((void**)item4)[i];
            extern void* call_7f4aaa4(void*, void*, void*, void*, void*);
            void* c = call_7f4aaa4(v4, 0, (void*)0xaffe40, (void*)0xb1c3ec, 0);
            if (b != 0 && c != 0)
            {
                void** vt = *(void***)b;
                void (*fn)(void*, void*) = (void (*)(void*, void*))vt[0];
                char tmp[0x30];
                fn(b, tmp);
                void* p5 = *(void**)((char*)this + 0x120);
                void** vt2 = *(void***)p5;
                void (*fn2)(void*, void*, void*) = (void (*)(void*, void*, void*))vt2[1];
                void* r2 = 0;
                fn2(p5, &r2, tmp);
                extern void call_6de4c0(void*, void*);
                call_6de4c0(r2, tmp);
            }
            if (a != 0)
            {
                // store a somewhere
            }
            i++;
            count = ((S*)this)->f();
        } while (i < count);
    }

    if (field_2DC <= 0)
        field_2DC = 1;
    else
        field_2DC = 0;
}
