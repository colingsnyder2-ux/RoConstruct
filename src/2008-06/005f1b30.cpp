// from server: 100% by king_originala
struct TimeValue {
    __int64 seconds;
    int nanoseconds;
};

extern int __cdecl readTime(TimeValue*, int);

void __cdecl remainingTime(TimeValue target, unsigned long* result)
{
    TimeValue now;
    readTime(&now, 1);

    if ((target.seconds == now.seconds
             ? target.nanoseconds - now.nanoseconds
             : (target.seconds > now.seconds ? 1 : -1)) <= 0) {
        *result = 0;
        return;
    }

    if (now.nanoseconds > target.nanoseconds) {
        target.nanoseconds += 1000000000;
        --target.seconds;
    }

    *result = (long)(target.seconds - now.seconds) * 1000
            + (target.nanoseconds - now.nanoseconds + 500000) / 1000000;
}
