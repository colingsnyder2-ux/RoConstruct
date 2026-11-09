// from server: 100% by tester
struct ViewBase {
    double getValue(int);
};

double ViewBase::getValue(int) {
    extern double value;
    return value;
}
