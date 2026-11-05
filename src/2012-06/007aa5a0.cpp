// from server: 73% by atomic.potato
struct KeyframeSequence_007aa5a0
{
    char pad0[212];
    unsigned char flag;
    char pad1[27];
    float value[3];

    void get(float* result);
};

void KeyframeSequence_007aa5a0::get(float* result)
{
    float* source;
    if (flag)
        source = reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 240);
    else
        source = reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 252);

    unsigned long* sourceWords = reinterpret_cast<unsigned long*>(source);
    unsigned long* resultWords = reinterpret_cast<unsigned long*>(result);
    resultWords[0] = sourceWords[0];
    resultWords[1] = sourceWords[1];
    resultWords[2] = sourceWords[2];
}
