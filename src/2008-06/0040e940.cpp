// from server: 100% by colin
struct Query {
    int (__stdcall **vtable)(Query*, short*);
};

struct Callback {
    virtual void invoke(int value);
};

struct CBrowserView {
    char padding[0xf0];
    Query* query;
    void invoke(Callback* callback);
};

void CBrowserView::invoke(Callback* callback) {
    short value;
    int result;
    if (query->vtable[31](query, &value) == 0 && value == -1)
        result = 1;
    else
        result = 0;
    callback->invoke(result);
}
