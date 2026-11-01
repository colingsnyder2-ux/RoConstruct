// from server: 100% by king_originala
struct Worker {
    void finish();
    void clear();
    void update();
};

struct DataModel {
    char padding0[0x0C];
    Worker* worker;
    char padding1[0x51];
    unsigned char enabled;

    void process(int unused, int value, int action);
};

void DataModel::process(int unused, int value, int action)
{
    if (enabled) {
        switch (action) {
        case 0:
            if (value == 1)
                worker->clear();
            break;
        case 1:
            worker->update();
            break;
        case 2:
            worker->finish();
            break;
        }
    }
}
