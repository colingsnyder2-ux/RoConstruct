// from server: 100% by atomic.potato
struct Workspace
{
    int* f();
    char pad[0xec];
    int* d0;
    char pad2[4];
    int* d1;
};

int* Workspace::f()
{
    return d0 ? d0 : d1;
}
