// from server: 100% by king_originala
struct Task {
    virtual void run() = 0;
    virtual void release(int) = 0;
};

struct S {
    long handle(unsigned int, unsigned int, Task*, int&);
    int process(void*, unsigned int, unsigned int, Task*, long*, int);
};

int S::process(void*, unsigned int message, unsigned int wParam,
               Task* task, long* result, int map)
{
    if (map == 0) {
        if (message == 2) {
            map = 1;
            *result = handle(2, wParam, task, map);
            if (map)
                return 1;
        } else if (message == 0x465) {
            task->run();
            task->release(1);
            *result = 0;
            return 1;
        }
    }
    return 0;
}
