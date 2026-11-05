// from server: 100% by tajop
struct X
{
    int a[9];
    virtual void x();
};

struct Y
{
    int b[4];
    virtual void y();
};

struct T : X, Y
{
    T(const T &);
};

struct C
{
    virtual void rethrow() const = 0;
};

struct D : T, C
{
    virtual void rethrow() const;
};

void D::rethrow() const
{
    throw *this;
}
