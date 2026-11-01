// from server: 59% by atomic.potato
struct String
{
    String(const String&);
    String& operator=(const String&);
};

struct SoundChannel
{
    char pad[8];
    String m_string;
    SoundChannel* __cdecl f(const String&);
};

SoundChannel* SoundChannel::f(const String& value)
{
    m_string = value;
    return this;
}
