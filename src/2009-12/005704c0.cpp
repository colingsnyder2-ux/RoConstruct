// from server: 100% by atomic.potato
struct CSHA1
{
    unsigned int value;
};

unsigned int CSHA1_valueFunction(CSHA1 *value)
{
    return value->value + (value->value >> 3);
}
