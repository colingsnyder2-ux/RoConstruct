// from server: 100% by colin
struct RakPeer {
    int field0;
    unsigned int field4;
    int sub_4c6df0(int, char*);
    int sub_4c5170(int, int);
    int sub_4b92e0(int);
    int func_004c6e70(int, int);
};

int RakPeer::func_004c6e70(int a1, int a2)
{
    char local;
    int result;
    int idx;

    idx = sub_4c6df0(a1, &local);
    result = idx;
    if (local != 0) {
        return -1;
    }
    if ((unsigned int)result >= field4) {
        sub_4b92e0(*(int*)a2);
        return field4 - 1;
    }
    sub_4c5170(*(int*)a2, result);
    return result;
}
