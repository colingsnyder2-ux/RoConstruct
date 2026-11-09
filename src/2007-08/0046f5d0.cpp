// from server: 64% by colin
// roc 2007-08 0046f5d0  unit: std::D::DU?$char_traits::V?$basic_string::?$Set  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0046f5d0

extern "C" {
    unsigned int __stdcall glGetString(unsigned int name);
}

namespace std {
    class string {
    public:
        string(const char*);
        ~string();
        unsigned int find(const char*, unsigned int, unsigned int) const;
        static const unsigned int npos;
    };
}

extern "C" unsigned int __stdcall sub_46C9B0();
extern "C" unsigned int __stdcall sub_46C8C0();

extern unsigned char byte_8BD02D;
extern unsigned char byte_8BD02C;

bool CheckGenerateMipmap()
{
    if (byte_8BD02D == 0)
    {
        byte_8BD02D = 1;
        const char* ext = (const char*)glGetString(0x1F03);
        std::string s(ext);
        unsigned int pos = s.find("GL_SGIS_generate_mipmap", 0, 0x17);
        if (pos != std::string::npos)
        {
            byte_8BD02C = 0;
        }
        else
        {
            if (sub_46C9B0() & 0xFF)
            {
                byte_8BD02C = 0;
            }
            else
            {
                byte_8BD02C = 1;
                if (!(sub_46C8C0() & 0xFF))
                {
                    byte_8BD02C = 1;
                }
            }
        }
    }
    return byte_8BD02C != 0;
}
