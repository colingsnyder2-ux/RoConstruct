// from server: 100% by colin
extern float g_float_93cc40;

struct DataBlock {
    char data[0x24];
};

struct Inner {
    char data[0x24];
    float a;
    float b;
    float c;
};

struct Sender {
    void* vtable;
    char pad[0x0C];
    char data[0x24];
    float a;
    float b;
    float c;
    float f40;
    int f44;
};

struct Obj {
    Inner* getInner();
};

void __cdecl init(Sender* out)
{
    Inner* in = ((Obj*)*(void**)out)->getInner();
    DataBlock* dst = (DataBlock*)((char*)out + 0x10);
    *(DataBlock*)dst = *(DataBlock*)in;
    ((Inner*)dst)->a = in->a;
    ((Inner*)dst)->b = in->b;
    ((Inner*)dst)->c = in->c;
    out->f40 = g_float_93cc40;
    out->f44 = 0;
}
