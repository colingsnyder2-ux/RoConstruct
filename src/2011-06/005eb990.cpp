// from server: 45% by atomic.potato
struct S {
    int f(int, int);
};

int S::f(int a, int b) {
    int eax = a;
    if (!eax) {
        int edx = b;
        int ecx = *(int*)(*((int*)ecx + 4));
        eax = 0;
        int ecx2 = ecx + eax;
        *(int*)(edx) = ecx2;
        return 0;
    }
    int edx = b;
    int ecx = *(int*)(*((int*)ecx + 4));
    int eax2 = eax - 28;
    int ecx3 = ecx + eax2;
    *(int*)(edx) = ecx3;
    return 0;
}
