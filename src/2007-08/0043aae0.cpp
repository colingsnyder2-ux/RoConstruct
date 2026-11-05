// from server: 41% by colin
extern "C" void __stdcall _invalid_parameter_noinfo();

struct Inner {
    char pad[0x74];
    unsigned int field74;
    unsigned int field78;
    unsigned int field7c;
};

struct S {
    char pad[4];
    Inner inner;
    void func(unsigned int arg);
};

extern "C" void __stdcall sub_464ec0(void* out, void* self);
extern "C" void __stdcall sub_43a080(void* a, void* b, void* c, void* d, void* e, void* f);

void S::func(unsigned int arg)
{
    Inner* p;
    sub_464ec0(&p, &this->inner);

    unsigned int edi = p->field7c;
    Inner* esi = (Inner*)((char*)p + 0x74);

    if (esi->field74 > edi)
        _invalid_parameter_noinfo();

    unsigned int edx = esi->field74;
    if (edx > esi->field78)
    {
        _invalid_parameter_noinfo();
        edx = esi->field74;
    }

    struct Local {
        void* a;
        void* b;
        void* c;
    } local;
    local.a = (void*)0x43aae0;
    local.b = (void*)this;
    local.c = (void*)arg;

    sub_43a080(&local, esi, (void*)edx, (void*)edi, esi, &local);
}
