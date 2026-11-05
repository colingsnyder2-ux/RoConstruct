// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
extern double __cdecl readTime();
extern const float timeScale;
extern void __cdecl markerCallback();

struct Queue {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void *next();
    virtual void process(void *);
};

struct Owner {
    void finish(void (__cdecl *)());
};

struct S {
    unsigned char reserved[12];
    Queue *queue;
    void run(int, int, float);
};

void S::run(int, int, volatile float duration)
{
    double deadline = readTime() + duration * timeScale;
    do {
        void *item = queue->next();
        if (!item)
            break;
        queue->process(item);
    } while (readTime() < deadline);

    reinterpret_cast<Owner *>(
        reinterpret_cast<char *>(this) - 0x134
    )->finish(markerCallback);
}
