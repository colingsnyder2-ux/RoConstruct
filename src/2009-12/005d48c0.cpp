// from server: 33% by atomic.potato
extern "C" int __stdcall CloseHandle(void*);

struct Inner1 { char pad[0x20]; };
struct Inner2 { char pad[0x20]; };

struct S {
    char pad0[0x1c];
    void* field1c;
    Inner1 inner20;
    Inner2 inner40;
    void dtor();
};

void sub_5d2f80(Inner2*);
void sub_5d2ff0(Inner1*);
void sub_5d15a0(S*);

void S::dtor()
{
    sub_5d2f80(&inner40);
    sub_5d2ff0(&inner20);
    void* p = field1c;
    field1c = 0;
    if (p) CloseHandle(p);
    *(void**)this = (void*)0x9c1188;
    sub_5d15a0(this);
}
