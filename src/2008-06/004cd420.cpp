// from server: 100% by king_originala
struct S;
struct Sender;

struct Context
{
    char padding[0x2d50];
    int value;
};

struct Manager
{
    Sender* getSender();
};

struct ServiceProvider
{
    char padding[0x2e4];
    Manager* manager;
};

ServiceProvider* __cdecl func_00491e50(Context*);
double __cdecl sub_508410();
extern const double interval;

struct Receiver
{
    char storage[0x130];
    int result;

    Receiver(S*, int);
    ~Receiver();
    void update(void*);
};

struct Sender
{
    void send(Receiver*, int*, void*);
};

struct S
{
    void* vtable;
    Context* context;
    int state;
    int reserved;
    double lastTime;

    void* sub_4ca040();
    int sub_4cd420(int);
};

int S::sub_4cd420(int)
{
    Receiver receiver(this, context->value);
    ServiceProvider* provider = func_00491e50(context);
    if (provider)
    {
        Sender* sender = provider->manager->getSender();
        void* value = sub_4ca040();
        if (value)
        {
            double now = sub_508410();
            if (now > lastTime + interval)
            {
                receiver.update(value);
                lastTime = now;
            }
            else
            {
                value = 0;
            }
        }
        sender->send(&receiver, &state, value);
    }
    return receiver.result;
}
