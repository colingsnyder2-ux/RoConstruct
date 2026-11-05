// from server: 100% by colin
extern "C" int __cdecl sub_719C7A(int, int, int, int, int);

struct RBX_Network_Server {
    int f(int);
};

int RBX_Network_Server::f(int a) {
    int r = sub_719C7A(a, 0, 0x9dbe40, 0x9f22fc, 0);
    return r != 0;
}
