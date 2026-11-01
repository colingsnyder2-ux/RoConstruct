// from server: 100% by colin
namespace ns_ROCX00001f {
struct ArrowToolBase {
    char f0;
    char f1;
    char f2;
    char f3;
    int isIdle() const;
};

int ArrowToolBase::isIdle() const {
    if (f0 || f1 || f2 || f3)
        return 1;
    return 0;
}
}
