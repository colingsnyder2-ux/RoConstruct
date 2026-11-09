// from server: 100% by colin
extern "C" int __cdecl sub_7A8BEA(int, int, int, int, int);

struct RBX_Network_Server {
    bool f(int);
};

bool RBX_Network_Server::f(int a) {
    int r = sub_7A8BEA(a, 0, 0xb78e40, 0xb8e9f0, 0);
    return r != 0;
}
