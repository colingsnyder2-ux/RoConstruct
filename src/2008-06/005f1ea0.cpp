// from server: 100% by king_originala
struct TimeValue {
    __int64 seconds;
    int nanoseconds;
};

extern int __cdecl readTime(TimeValue*, int);
extern void __cdecl remainingTime(TimeValue, unsigned long*);

extern unsigned long (__stdcall * const WaitForSingleObject)(void*, unsigned long);
extern int (__stdcall * const ReleaseSemaphore)(void*, long, long*);
extern int (__stdcall * const ReleaseMutex)(void*);

struct S {
    void* semaphore;
    void* event;
    void* mutex;
    int pending;
    int consumed;
    int waiters;

    bool wait(const TimeValue*);
};

bool S::wait(const TimeValue* target)
{
    unsigned long (__stdcall *waitFunction)(void*, unsigned long) =
        WaitForSingleObject;
    unsigned long timeout;
    TimeValue now;
    bool success;

    do {
        remainingTime(*target, &timeout);
        unsigned long result = waitFunction(event, timeout);
        success = result == 0;
        if (result != 0x102)
            break;
        readTime(&now, 1);
    } while ((target->seconds == now.seconds
              ? target->nanoseconds - now.nanoseconds
              : (target->seconds > now.seconds ? 1 : -1)) > 0);

    waitFunction(mutex, 0xffffffffUL);

    int oldWaiters = waiters;
    int oldPending = pending;

    if (oldWaiters != 0) {
        if (!success) {
            if (consumed != 0)
                --consumed;
            else
                pending = oldPending + 1;
        }

        if (--waiters == 0) {
            if (consumed != 0) {
                ReleaseSemaphore(semaphore, 1, 0);
                oldWaiters = 0;
            } else if (pending != 0) {
                pending = 0;
            }
        }
    } else {
        if ((pending = oldPending + 1) == 0x7fffffff) {
            waitFunction(semaphore, 0xffffffffUL);
            consumed -= pending;
            ReleaseSemaphore(semaphore, 1, 0);
            pending = 0;
        }
    }

    ReleaseMutex(mutex);

    if (oldWaiters == 1) {
        if (oldPending != 0) {
            do {
                waitFunction(event, 0xffffffffUL);
            } while (--oldPending != 0);
        }
        ReleaseSemaphore(semaphore, 1, 0);
    }

    return success;
}
