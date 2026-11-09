// from server: 100% by king_originala
extern void (__thiscall *constructString)(void*, const char*);

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Alloc>
    class basic_string {
        unsigned char storage[28];
    public:
        basic_string(const T*);
        ~basic_string();
    };

    template<class T, class Traits, class Alloc>
    __forceinline basic_string<T, Traits, Alloc>::basic_string(const T* text)
    {
        constructString(this, text);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;

    class exception {
        void* data;
        int owned;
    public:
        virtual ~exception();
    };

    class runtime_error : public exception {
        string message;
    public:
        runtime_error(const string&);
        virtual ~runtime_error();
    };
}

struct Frame {
    float rotation[9];
    float position[3];
};

struct Quaternion {
    float x, y, z, w;
    void apply(Frame*);
};

struct Stream {
    bool readBits(void*, int, bool);
    bool readNormQuat(float&, float&, float&, float&);
};

extern Stream& __cdecl readPosition(Stream&, float*);
extern Stream& __cdecl readFlag(Stream&, bool&);
extern void __cdecl applyOrientation(int, Frame*);
extern void __cdecl finishFrame(Frame*);

Stream& __cdecl readFrame(Stream& stream, Frame& frame)
{
    readPosition(stream, frame.position);

    bool compressed;
    readFlag(stream, compressed);

    if (compressed) {
        int orientation = 0;
        if (!stream.readBits(&orientation, 6, true))
            throw std::runtime_error("BitStream >> CoordinateFrame orientId failed");
        applyOrientation(orientation, &frame);
    } else {
        Quaternion rotation;
        rotation.x = 0.0f;
        rotation.y = 0.0f;
        rotation.z = 0.0f;
        rotation.w = 1.0f;

        if (!stream.readNormQuat(rotation.w, rotation.x, rotation.y, rotation.z))
            throw std::runtime_error("BitStream >> CoordinateFrame ReadNormQuat failed");

        rotation.apply(&frame);
        finishFrame(&frame);
    }

    return stream;
}
