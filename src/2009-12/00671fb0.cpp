// from server: 100% by atomic.potato
struct DataModel {
    void f(void *);
    unsigned char enabled[2802];
};

extern "C" int __stdcall helper(void *);

void DataModel::f(void *p)
{
    if (enabled[2801] && *(int *)p)
        helper(p);
}
