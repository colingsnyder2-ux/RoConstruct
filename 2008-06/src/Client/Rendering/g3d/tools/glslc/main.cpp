/**
 @file glslc/main.cpp

  A faux compiler that prints out error messages for GLSL files

  TODO: support a '.glsl' format that combines pixel & vertex shader and checks link errors
  TODO: --depend

 @maintainer Morgan McGuire, matrix@graphics3d.com
 @created 2004-07-19
 @edited  2004-07-19
 */
#include <G3DAll.h>
#ifdef G3D_WIN32
#include "../contrib/Win32Window/Win32Window.h"
#include "../contrib/Win32Window/Win32Window.cpp"
#endif

enum Mode {VERTEX, FRAGMENT, BOTH};

void printHelp();
void printVersion();

/** Compiles the .frag or .vert source file.  If compilation is successful, returns 0.
    Otherwise returns -1 and prints formatted errors.  Linking is *not* checked.*/
int check(Mode, const std::string&, const std::string&);

int main(int argc, char** argv);


int check(Mode mode, const std::string& srcFile) {
    std::string v, f;
    if (mode == VERTEX) {
        v = srcFile;
        f = "";
    } else {
        v = "";
        f = srcFile;
    }

    VertexAndPixelShaderRef shader = VertexAndPixelShader::fromFiles(v, f, false);

    if (shader->ok()) {
        return 0;
    } else {
        std::string m;
        if (mode == VERTEX) {
            m = shader->vertexErrors();
        } else {
            m = shader->pixelErrors();
        }

        if (m == "") {
            // Error must have been a linking error; ignore it
            return 0;
        }

        printf("%s", m.c_str());

        return -100;
    }
}


int main(int argc, char** argv) {

    // Argument parsing

    if ((argc == 1) ||
        ((argc >= 2) && (std::string("--help") == argv[1]))) {
        printHelp();
        return 0;
    }

    if ((argc == 2) && (std::string("--version") == argv[1])) {
        printVersion();
        return 0;
    }

    std::string src = "";
    std::string dst = "";

    // Figure out source and dest filenames
    if (argc >= 4) {
        if (std::string("-o") != argv[1]) {
            printf("Invalid command line to GLSLCheck.  Expected '-o' or"
                " filename as 1st argument, found: '%s'\n", argv[1]);
            return -1;
        }
        dst = argv[2];
        src = argv[3];
    } else {
        src = argv[1];
    }

    if (! fileExists(src)) {
        printf("GLSLCheck error : input file '%s' not found\n", src.c_str());
        return -4;
    }

    if (endsWith(dst, "/") || endsWith(dst, "\\")) {
        if (! fileExists(dst.substr(0, dst.size() - 1))) {
            printf("GLSLCheck error : output directory '%s' not found\n", dst.c_str());
            return -5;
        }

        // Add the filename part of src to dst, since dst is a directory
        dst = dst + filenameBaseExt(src);
    }


    Mode mode;
    if (endsWith(toLower(src), ".vert")) {
        mode = VERTEX;
    } else if (endsWith(toLower(src), ".frag")) {
        mode = FRAGMENT;
    } else {
        printf("Invalid filename; source file must end with .vert or .frag\n");
        return -2;
    }

    // We must create a GL context before loading extensions.
    GWindowSettings settings;
    settings.visible = false;
    settings.width = 200;
    settings.height = 200;

    GWindow* window;
    #ifdef G3D_WIN32
        window = new Win32Window(settings);
    #else
        window = new SDLWindow(settings);
    #endif
    GLCaps::loadExtensions();

    if (! VertexAndPixelShader::fullySupported()) {
        printf("GLSL not supported by your graphics card and driver.\n");
        return -3;
    }

    int result = check(mode, src);

    if ((result == 0) && (dst != "")) {
        copyFile(src, dst);
    }

    delete window;
    return result;
}


void printVersion() {
    printf("glslc 1.0 compiled " __DATE__ " at " __TIME__ " using G3D %d \n", G3D_VER);
    printf("Copyright 2004 Morgan McGuire\n");
}


void printHelp() {
    printf(
        "glslc [--help] [--version] [-o destfilename] sourcefilename \n"
        "\n"
        "Checks OpenGL GLSL vertex and fragment programs for syntax errors and copies\n"
        "them to a distribution directory.  Can be used with a MSVC Custom Build rule\n"
        "or Makefile to perform compile-time checking of run-time loaded shaders.\n"
        "\n"
        "sourcefilename  A .frag or .vert file to check for errors.\n"
        "destfilename    The output directory (ends with /) or filename to copy\n"
        "                the source to, if it has no errors."
        "\n"
        "GLSLCheck is distributed with the G3D library\n"
        "http://g3d-cpp.sf.net\n\n");

    printVersion();
}
