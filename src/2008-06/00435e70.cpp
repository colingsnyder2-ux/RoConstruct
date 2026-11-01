// from server: 100% by king_originala
struct Input {
    char padding[0x5c];
    int value;
};

struct Handler {
    void handle(int value);
};

struct CDeclarationView {
    char padding[0xb0];
    Handler* handler;

    void process(Input* input, int* result);
};

void CDeclarationView::process(Input* input, int* result)
{
    if (handler)
        handler->handle(input->value);
    *result = 0;
}
