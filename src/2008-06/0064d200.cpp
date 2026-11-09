// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Context {
    void f(int);
};

struct SimJob {
    SimJob(int);
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
};

struct Job {
    virtual void slot0();
    virtual void set(Context*);
    void bind(int);
    int value();
};

struct Stage {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual Context* context();
    void setJob(SimJob*);
    void f(Job*);
};

void Stage::f(Job* job)
{
    job->bind((int)this);
    job->set(context());
    context()->f(job->value());
    setJob(new SimJob((int)job));
}
