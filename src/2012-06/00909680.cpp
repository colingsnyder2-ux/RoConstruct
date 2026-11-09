// from server: 15% by atomic.potato
struct Body {
    int f(const void* value);
};

extern "C" int __stdcall callee_62c370(const void*, const void*);
extern "C" void callee_908fd0(Body*);

int Body::f(const void* value)
{
    char* destination = reinterpret_cast<char*>(this) + 0x74;
    if (callee_62c370(destination, value))
    {
        callee_908fd0(this);
        destination[0] = reinterpret_cast<const char*>(value)[0];
        destination[1] = reinterpret_cast<const char*>(value)[1];
        destination[2] = reinterpret_cast<const char*>(value)[2];
        destination[3] = reinterpret_cast<const char*>(value)[3];
        destination[4] = reinterpret_cast<const char*>(value)[4];
        destination[5] = reinterpret_cast<const char*>(value)[5];
        destination[6] = reinterpret_cast<const char*>(value)[6];
        destination[7] = reinterpret_cast<const char*>(value)[7];
        destination[8] = reinterpret_cast<const char*>(value)[8];
        destination[9] = reinterpret_cast<const char*>(value)[9];
        destination[10] = reinterpret_cast<const char*>(value)[10];
        destination[11] = reinterpret_cast<const char*>(value)[11];
        destination[12] = reinterpret_cast<const char*>(value)[12];
        destination[13] = reinterpret_cast<const char*>(value)[13];
        destination[14] = reinterpret_cast<const char*>(value)[14];
        destination[15] = reinterpret_cast<const char*>(value)[15];
        destination[16] = reinterpret_cast<const char*>(value)[16];
        destination[17] = reinterpret_cast<const char*>(value)[17];
        destination[18] = reinterpret_cast<const char*>(value)[18];
        destination[19] = reinterpret_cast<const char*>(value)[19];
        destination[20] = reinterpret_cast<const char*>(value)[20];
        destination[21] = reinterpret_cast<const char*>(value)[21];
        destination[22] = reinterpret_cast<const char*>(value)[22];
        destination[23] = reinterpret_cast<const char*>(value)[23];
        destination[24] = reinterpret_cast<const char*>(value)[24];
        destination[25] = reinterpret_cast<const char*>(value)[25];
        destination[26] = reinterpret_cast<const char*>(value)[26];
        destination[27] = reinterpret_cast<const char*>(value)[27];
        destination[28] = reinterpret_cast<const char*>(value)[28];
        destination[29] = reinterpret_cast<const char*>(value)[29];
        destination[30] = reinterpret_cast<const char*>(value)[30];
        destination[31] = reinterpret_cast<const char*>(value)[31];
        destination[32] = reinterpret_cast<const char*>(value)[32];
        destination[33] = reinterpret_cast<const char*>(value)[33];
        destination[34] = reinterpret_cast<const char*>(value)[34];
        destination[35] = reinterpret_cast<const char*>(value)[35];
    }
    return 0;
}
