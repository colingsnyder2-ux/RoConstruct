// from server: 67% by colin
struct Prop;

struct Arg
{
    char pad0[4];
    void* ptr4;
    char pad8[4];
    void* ptrC;
};

struct Descriptor
{
    char pad[0xe8];
    Prop* prop;
    void* method(Arg* arg);
};

extern "C" void* __stdcall sub_53e7a0(void*);
extern "C" void* __fastcall sub_4431c0(Prop*);

void* Descriptor::method(Arg* arg)
{
    Prop* p = this->prop;
    void* result;
    if (p != 0)
    {
        void* v = arg->ptrC;
        void* v2 = *(void**)((char*)v + 4);
        result = sub_53e7a0((char*)v2 + 4);
    }
    else
    {
        result = 0;
    }
    if (result != 0)
    {
        void* r = sub_4431c0((Prop*)result);
        if (r != 0)
        {
            void* v = arg->ptr4;
            void* v2 = (char*)v + 4;
            return sub_53e7a0(v2);
        }
    }
    return 0;
}
