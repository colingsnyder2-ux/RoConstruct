// from server: 9% by atomic.potato
extern "C" void __stdcall _invalid_parameter_noinfo();

struct Inner {
    Inner* next;
    Inner* prev;
};

struct List {
    char pad0[8];
    Inner* head;
    char pad1[8];
    int count;
};

struct Src {
    char pad0[4];
    char flag4;
    char pad5[3];
    int f8;
    char pad12[0x10];
    int f1c;
    char pad20[0x10];
    int f30;
    int f34;
    char pad38[4];
    int f3c;
    int f40;
    float f44;
};

struct Vec {
    char pad0[0xc];
    void* begin;
    void* end;
};

struct S {
    char pad0[4];
    char flag4;
    char pad5[3];
    List list8;
    char pad24[0x18];
    int f3c;
    int f40;
    float f44;
    int f48;

    void func(Src* src);
};

extern void G1_func_004ab1a0();
extern void G1_func_0057da80();
extern void G1_func_007f385a();

void S::func(Src* src)
{
    Inner* node;
    Inner* first;
    Inner* cur;
    int i;
    int n;
    Vec* vec;
    int a;
    int b;

    node = list8.head;
    if (node)
        node = node->next;
    else
        node = 0;

    vec = (Vec*)((char*)src + 0x30);
    n = (src->f34 - src->f30) >> 3;

    G1_func_0057da80();

    f3c = src->f3c;
    f40 = src->f40;
    f44 = src->f44;

    first = list8.head;
    cur = first->next;
    first->next = first;
    list8.head->prev = list8.head;
    list8.count = 0;

    while (cur != list8.head)
    {
        Inner* nxt = cur->next;
        G1_func_007f385a();
        cur = nxt;
    }

    G1_func_004ab1a0();

    flag4 = src->flag4;

    first = list8.head;
    cur = first->next;

    i = 0;
    n = (*(int*)((char*)vec + 0x10) - *(int*)((char*)vec + 0xc)) >> 3;

    if (n == 0)
        return;

    do
    {
        if (i >= (unsigned)((src->f34 - src->f30) >> 3))
            _invalid_parameter_noinfo();

        if (*(int*)(src->f30 + i * 8 + 4) == src->f1c)
        {
            Inner* nn;
            if (node)
                nn = node->next;
            else
                nn = 0;

            if (i >= (unsigned)((*(int*)((char*)vec + 0x10) - *(int*)((char*)vec + 0xc)) >> 3))
                _invalid_parameter_noinfo();

            *(Inner**)(*(int*)((char*)vec + 0xc) + i * 8) = nn;
            *(int*)(*(int*)((char*)vec + 0xc) + i * 8 + 4) = src->f1c;
            i++;
        }
        else
        {
            if (node == 0)
                _invalid_parameter_noinfo();

            if (cur == list8.head)
                _invalid_parameter_noinfo();

            cur = cur->next;

            if (src->f8 == 0)
                _invalid_parameter_noinfo();

            if (src->f1c == 0)
                _invalid_parameter_noinfo();

            src->f1c = *(int*)src->f1c;
        }

        n = (*(int*)((char*)vec + 0x10) - *(int*)((char*)vec + 0xc)) >> 3;
    } while (i < n);
}
