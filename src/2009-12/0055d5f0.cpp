// from server: 41% by atomic.potato
struct NetworkOwnerJob
{
    int value;
    int next;
    int previous;
    int reserved;
    NetworkOwnerJob();
};

NetworkOwnerJob::NetworkOwnerJob()
{
    value = 0;
    next = (int)this + 4;
    previous = (int)this + 4;
    reserved = 0;
}
