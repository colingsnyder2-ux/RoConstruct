// from server: 93% by atomic.potato
struct Configuration
{
    int value0;
    int value4;
    int value18;
    int value1c;

    void ConfigurationFunction();
};

extern "C" void Configuration_Continuation();

void Configuration::ConfigurationFunction()
{
    value0 = 0xbc0a24;
    value4 = 0xbc0a18;
    value18 = 0xbc0a0c;
    value1c = 0xbc0a00;
    Configuration_Continuation();
}
