// from server: 40% by atomic.potato
struct CRobloxView
{
    int field_210;
    int f(int);
};

int CRobloxView::f(int value)
{
    struct V
    {
        int (**vtable)();
    };

    V* object;
    int result;

    result = field_210 != 0;
    object = (V*)value;
    return object->vtable[1]();
}
