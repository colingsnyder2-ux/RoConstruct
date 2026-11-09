// from server: 62% by atomic.potato
extern "C" int __stdcall func_0078bf80(int, int, int);

struct HitTestFilter
{
    int field_0x1c;
    int method(int, int);
};

int HitTestFilter::method(int a, int b)
{
    int local = 0;
    int* p = (int*)field_0x1c;
    int* q = p ? (int*)((char*)p + 0x118) : 0;
    func_0078bf80(a, b, (int)q);
    return a;
}
