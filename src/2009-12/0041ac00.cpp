// from server: 63% by atomic.potato
extern "C" int __fastcall sub_0081bff0(void *);

struct CNameItem
{
    int f(int);
};

int CNameItem::f(int value)
{
    int result = sub_0081bff0(this);
    if (result)
    {
        result = sub_0081bff0(this);
        return (*(int (**)(int *, int))(*(int **)result + 0x78))((int *)result, value);
    }
    return -1;
}
