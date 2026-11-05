// from server: 100% by tester
struct RakPeer {
    int sub_4bcb80(int, int, int, int);
    int func(int, int);
};

int RakPeer::func(int a, int b) {
    int result = sub_4bcb80(a, b, 0, 0);
    if (result == 0) {
        return -1;
    }
    return *(unsigned short*)(result + 0x1380);
}
