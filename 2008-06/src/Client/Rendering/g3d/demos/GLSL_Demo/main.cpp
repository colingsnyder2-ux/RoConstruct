/**
 @file GLSL_Demo/main.cpp
 @maintainer Morgan McGuire, matrix@graphics3d.com
 @created 2004-06-25
 @edited  2006-01-29
 */

#include "header.h"

int main(int argc, char** argv) {
	GAppSettings settings;
    settings.window.fsaaSamples = 4;
	settings.window.width = 800;
	settings.window.height = 600;
    settings.useNetwork = false;
	App(settings).run();
	return 0;
}

App::App(const GAppSettings& settings) : GApp(settings) {
    window()->setCaption("GLSL Demo");
}


static TextureRef loadBumpAsNormalMap(const std::string& filename) {
	GImage normal;
	computeNormalMap(GImage(filename), normal, true, true);
	return Texture::fromGImage(filename, normal);
}

void App::main() {
//	setDebugMode(false);
//	debugController.setActive(false);

    debugLog->println("Loading textures\n");

    sky = Sky::create(renderDevice, dataDir + "sky/");

    // Find the path to our runtime files
    std::string path = "GLSL_Demo/";
    if (! fileExists(path + "bump.frag")) {
        path = "";
    }

    bumpShader = Shader::fromFiles(path + "bump.vert", path + "bump.frag");

    textureMap = Texture::fromFile(path + "rockwall.tga");
    normalBumpMap = loadBumpAsNormalMap(path + "rockwall-bump.tga");
    debugLog->println("Launching Viewer\n");

	Viewer(this).run();
}

