// from server: 100% by tester
int g_counter_8be5dc;

struct Server
{
    int increment();
};

int Server::increment()
{
    return ++g_counter_8be5dc;
}
