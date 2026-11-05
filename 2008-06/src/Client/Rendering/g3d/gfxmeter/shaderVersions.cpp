#include "../include/G3DAll.h"

void shaderVersions(
    std::string& regStr,
    std::string& asmStr,
    std::string& glslStr) {

    Array<std::string> reg, xasm;

    glslStr = "None";

    if (GLCaps::supports("GL_NV_register_combiners")){
        if (GLCaps::supports("GL_NV_register_combiners2")) {
            reg.append("NV rc2");
        } else {
            reg.append("NV rc");
        }
    }

    if (GLCaps::supports("GL_NV_texture_shader")) {
        if (GLCaps::supports("GL_NV_texture_shader2")) {
            if (GLCaps::supports("GL_NV_texture_shader3")) {
                reg.append("NV ts3");
            } else {
                reg.append("NV ts2");
            }
        } else {
            reg.append("NV ts");
        }
    }


    if (GLCaps::supports("GL_ATI_fragment_shader")) {
        reg.append("ATI fs");
    }


    if (GLCaps::supports("GL_EXT_vertex_shader")) {
        reg.append("EXT vs");
    }

    if (GLCaps::supports("GL_ARB_fragment_program")) {
        // arbfp1;
        xasm.append("ARB fp1");
    }

    if (GLCaps::supports("GL_ARB_vertex_program")) {
        // arbvp1
        xasm.append("ARB vp1");
    }

    if (GLCaps::supports("GL_NV_fragment_program")) {
        if (GLCaps::supports("GL_NV_fragment_program2")) {
            xasm.append("NV fp40");
        } else {
            xasm.append("NV fp30");
        }
    }

    if (GLCaps::supports("GL_NV_vertex_program")) {
        if (GLCaps::supports("GL_NV_vertex_program2")) {
            if (GLCaps::supports("GL_NV_vertex_program3")) {
                xasm.append("NV vp3");
            } else {
                xasm.append("NV vp2");
            }
        } else {
            xasm.append("NV vp");
        }
    }


    if (GLCaps::supports_GL_ARB_shader_objects() && 
        GLCaps::supports_GL_ARB_shading_language_100() &&
        GLCaps::supports_GL_ARB_fragment_shader() &&
        GLCaps::supports_GL_ARB_vertex_shader()) {
        glslStr = "1.00";
    }

    if (reg.length() == 0) {
        regStr = "None";
    } else {
        regStr = stringJoin(reg, ", ");
    }


    if (xasm.length() == 0) {
        asmStr = "None";
    } else {
        asmStr = stringJoin(xasm, ", ");
    }

}