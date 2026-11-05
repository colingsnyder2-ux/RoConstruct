// from server: 100% by atomic.potato
struct Inner {
    int get();
};

struct Outer {
    Inner* getInner(int index);
    int method(int* out);
};

int Outer::method(int* out)
{
    int i = 0;
    while (i < 6) {
        Inner* p = getInner(i);
        out[i] = p->get();
        i++;
    }
    return (int)out;
}
