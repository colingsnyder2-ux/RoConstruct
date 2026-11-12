// from server: 100% by EspClaude
// roc 2007-08 0046f5d0  unit: std::D::DU?$char_traits::V?$basic_string::?$Set  size: 203 bytes
#include <string>

extern "C" __declspec(dllimport) const unsigned char* __stdcall glGetString(unsigned int name);

bool sub_46C9B0();
bool sub_46C8C0();

static bool s_checked;
static bool s_supported;

bool CheckGenerateMipmap()
{
    if (!s_checked)
    {
        s_checked = true;
        std::string s((const char*)glGetString(0x1F03));
        if (s.find("GL_SGIS_generate_mipmap") == std::string::npos || sub_46C9B0())
        {
            s_supported = false;
        }
        else
        {
            bool broken = sub_46C8C0();
            s_supported = true;
            if (broken)
                s_supported = false;
        }
    }
    return s_supported;
}
