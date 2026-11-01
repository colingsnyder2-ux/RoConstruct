// from server: 92% by colin
struct NonFactoryProduct {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    void method();
};

void NonFactoryProduct::method() {
    if (field10 != 0) {
        int* p = (int*)((char*)field4 + fieldC * 4);
        int* obj = (int*)*p;
        if (*obj != 0) {
            int (*fn)(int, int) = (int (*)(int, int))obj[0];
            int r = fn(obj[1], 1);
            obj[1] = r;
        }
        *obj = 0;
        obj[2] = 0;
        fieldC++;
        if ((unsigned int)field8 <= (unsigned int)fieldC) {
            fieldC = 0;
        }
        field10--;
        if (field10 == 0) {
            fieldC = 0;
        }
    }
}
