// from server: 100% by tester
struct VProfilingItem_BoundFuncDesc {
    char pad[4];
    unsigned char field6;
    unsigned char field7;
    int getter();
};

int VProfilingItem_BoundFuncDesc::getter() {
    if (field6 != 0)
        return 1;
    return field7 != 0 ? -1 : 0;
}
