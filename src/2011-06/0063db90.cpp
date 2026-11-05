// from server: 100% by atomic.potato
struct ArrowToolBase {
    char f0;
    char f1;
    char f2;
    char f3;
    char f4;
    char f5;
    char f6;
    char f7;
    char f8;
    char f9;
    char f10;
    int isIdle() const;
};

int ArrowToolBase::isIdle() const {
    if (f0 || f1 || f2 || f3 || f4 || f5 || f6 || f7 || f8 || f9 || f10)
        return 1;
    return 0;
}
