// from server: 50% by atomic.potato
struct Elem {
    int m0;
    char pad[0x40];
};

struct Arr {
    Elem* begin;
    Elem* end;
    Elem* cap;
};

extern "C" void sub_524ff0(Arr* out, int n);
extern "C" int sub_6c13d0();
extern "C" void sub_4658b0(void* dst, void* src);
extern "C" void sub_982114(void* p);

struct S {
    void f(int a, int b, int c, int d);
};

void S::f(int a, int b, int c, int d)
{
    Arr arr;
    sub_524ff0(&arr, 3);
    Elem* p = arr.begin;
    p->m0 = sub_6c13d0();
    sub_4658b0(&p->m0 + 1, &a);
    Elem* p2 = (Elem*)((char*)arr.begin + 0x44);
    p2->m0 = sub_6c13d0();
    sub_4658b0(&p2->m0 + 1, &b);
    Elem* p3 = (Elem*)((char*)arr.begin + 0x88);
    p3->m0 = sub_6c13d0();
    sub_4658b0(&p3->m0 + 1, &c);
    void** vt = *(void***)arr.begin;
    void (*fn)(void*, void*, void*) = (void (*)(void*, void*, void*))vt[1];
    fn(arr.begin, this, &d);
    if (arr.begin) {
        Elem* e = arr.begin;
        Elem* last = arr.end;
        while (e != last) {
            int* q = (int*)((char*)e + 4);
            if (*q) {
                void (*df)(void*) = *(void (**)(void*))(*q + 4);
                df((char*)e + 8);
            }
            e = (Elem*)((char*)e + 0x44);
        }
        sub_982114(arr.begin);
    }
}
