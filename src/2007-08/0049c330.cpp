// from server: 100% by colin
// roc 2007-08 0049c330  unit: RBX::Network::Server  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0049c330

int g_counter_8be5dc;

struct Server
{
    int increment();
};

int Server::increment()
{
    return ++g_counter_8be5dc;
}
