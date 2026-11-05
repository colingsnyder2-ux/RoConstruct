// from server: 100% by colin
struct RakPeer {
    int field0;
    int field4;
    int sub_4c5b10(int, unsigned char*);
    int sub_4c5d40(int, int);
    int sub_4c5e60(int, int, int);
    int func(int, int);
};

int RakPeer::func(int a, int b) {
    unsigned char flag;
    int result = sub_4c5b10(a, &flag);
    if (flag != 0) {
        return -1;
    }
    if ((unsigned int)result >= (unsigned int)field4) {
        int* p = (int*)b;
        sub_4c5d40(p[0], p[1]);
        return field4 - 1;
    }
    int* p = (int*)b;
    sub_4c5e60(p[0], p[1], result);
    return result;
}
