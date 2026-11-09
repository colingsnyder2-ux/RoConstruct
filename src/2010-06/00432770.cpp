// from server: 57% by atomic.potato
struct CStandardOutputView
{
    int value;
    int padding;
    int next;
    void f(void (*callback)(int));
};

void CStandardOutputView::f(void (*callback)(int))
{
    int value = this->value;
    if (value != -1)
        callback(value);

    int next = this->next;
    if (next != 0 && next != -1)
        callback(next);
}
