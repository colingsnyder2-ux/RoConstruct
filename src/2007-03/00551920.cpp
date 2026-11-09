// from server: 100% by tester
struct BoundFuncDesc
{
    int value;
    int isValid() const;
};

int BoundFuncDesc::isValid() const
{
    int v = value;
    if (v == 1 || v == 2 || v == 3 || v == 4 || v == 5 || v == 6)
        return 1;
    return 0;
}
