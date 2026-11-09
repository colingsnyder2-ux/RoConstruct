// from server: 52% by atomic.potato
extern "C" int __stdcall Parent(int);

struct CXTPCustomizeSheet
{
    int f();
};

int CXTPCustomizeSheet::f()
{
    int value = Parent(0);
    while (value && value != 0)
        value = Parent(value);
    return value == 0 ? 0 : 1;
}
