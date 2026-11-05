// from server: 66% by atomic.potato
extern "C" int __stdcall Target0();
extern "C" int __stdcall Target1();
extern "C" int __stdcall Target2();

struct GeoPairConnector
{
    int padding;
    int value;
    int get();
};

int GeoPairConnector::get()
{
    int value = this->value;
    switch (value - 3)
    {
    case 0:
        return Target2();
    case 1:
        return Target1();
    case 2:
        return Target0();
    default:
        return 0;
    }
}
