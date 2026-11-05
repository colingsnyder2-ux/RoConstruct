// from server: 58% by atomic.potato
struct RecordPauseVerb
{
    int unused;
    int *value;

    int get();
};

int RecordPauseVerb::get()
{
    return value[40];
}
