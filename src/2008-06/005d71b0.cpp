// from server: 100% by king_originala
struct TimerService {
    unsigned long slots[77];
    TimerService();
    ~TimerService();
};

struct Pair {
    unsigned long first;
    unsigned long second;
    Pair(unsigned long value);
    ~Pair();
};

__forceinline Pair::Pair(unsigned long value) : second(value)
{
}

struct Hasher {
    Hasher();
    ~Hasher();
};

struct S : TimerService {
    Pair pair;
    Hasher hasher;
    S();
};

S::S()
    : TimerService(),
      pair((
          slots[0] = 0x0083d1a4,
          slots[4] = 0x0083d194,
          slots[5] = 0x0083d18c,
          slots[8] = 0x0083d184,
          slots[9] = 0x0083d174,
          slots[17] = 0x0083d164,
          slots[25] = 0x0083d154,
          slots[33] = 0x0083d144,
          slots[41] = 0x0083d134,
          slots[49] = 0x0083d124,
          slots[76] = 0x0083d118,
          pair.first = 0,
          0)),
      hasher()
{
}
