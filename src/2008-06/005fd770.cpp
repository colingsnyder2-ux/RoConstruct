// from server: 100% by king_originala
struct Matrix {
    char data[36];
    Matrix* copyFrom(const Matrix* source);
};

struct Frame {
    Matrix rotation;
    float f24, f28, f2c;
    Frame* initialize();
};

struct Helper {
    Frame* method();
};

struct Owner {
    Helper* getPart();
};

struct Tool {
    Frame* copyFrom(Frame* other);
};

Frame* Tool::copyFrom(Frame* other)
{
    volatile int flag = 0;
    Frame item;
    Helper* p = reinterpret_cast<Owner*>(
        reinterpret_cast<char*>(this) - 0x26c)->getPart();

    Frame* src;
    if (p)
        src = p->method();
    else
        src = item.initialize();

    other->rotation.copyFrom(&src->rotation);
    other->f24 = src->f24;
    other->f28 = src->f28;
    other->f2c = src->f2c;
    return other;
}
