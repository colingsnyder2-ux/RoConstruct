// from server: 97% by EspClaude
// from server: 52% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: g3d-6.09 roc_claude_bcb80a0779564fad.cpp

// Candidate translation unit (score above; library headers required).
// Codegen analog for 2007-08 0x502b80: an IJG error_exit replacement that prints the
// message, destroys the codec, formats the message and throws it as an exception.
// cinfo->err slots +8 (output_message) and +0xc (format_message) are read off the target.
#include "G3D/platform.h"
#include <stdio.h>
#include <string>
#include <stdexcept>
extern "C" {
#include "IJG/jpeglib.h"
}

void roc_jpeg_error_exit_502b80(j_common_ptr cinfo)
{
    (*cinfo->err->output_message)(cinfo);
    jpeg_destroy(cinfo);
    char buffer[JMSG_LENGTH_MAX];
    (*cinfo->err->format_message)(cinfo, buffer);
    std::string message(buffer);
    throw std::runtime_error(message);
}
