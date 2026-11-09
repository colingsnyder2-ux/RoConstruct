// from server: 85% by tajop
struct Server
{
    static int __fastcall continuation(int value);
    static int f();
};

int Server::f()
{
    return continuation(0);
}
