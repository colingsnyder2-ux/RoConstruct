/**
 @file BumpMapViewer/main.cpp
 @maintainer Morgan McGuire, matrix@graphics3d.com
 @created 2004-06-25
 @edited  2004-06-25
 */

#include "header.h"

const char* filetype[] = {".jpg", ".tga", ".bmp", ".pcx", ".ico", NULL};

int main(int argc, char** argv) {
	GAppSettings settings;
    settings.debugFontName = "";
	settings.window.width = 1024;
	settings.window.height = 768;
	App(settings).run();
	return 0;
}


App::App(const GAppSettings& settings) : GApp(settings) {
    window()->setCaption("G3D Parallax Bump Mapping");
}


void App::main() {
	setDebugMode(true);
	debugController.setActive(false);

    sky = Sky::create(renderDevice, dataDir + "sky/");
//    sky = Sky::create(renderDevice,"D:/games/data/sky/", "test/testcube_*.jpg");
//    sky = Sky::create(renderDevice,"D:/games/data/sky/", "desert/desert_*.jpg");

	getTextureFilenames(fileArray);
	
	for (int f = 0; f < fileArray.size(); ++f) {
		debugPrintf("%s\n", fileArray[f].color.c_str());
	}

	Viewer(this).run();
}


////////////////////////////////////////////////////////////////////////////////////////////////////

void App::getTextureFilenames(Array<FileSet>& fileArray) {

	Array<std::string> allImageFiles;
	for (int f = 0; filetype[f]; ++f) {
		getFiles(std::string("*") + filetype[f], allImageFiles);
	}

	// Put the files in a set for fast lookup
	Set<std::string> allFiles;
	for (int f = 0; f < allImageFiles.size(); ++f) {
		allFiles.insert(allImageFiles[f]);
	}

	allImageFiles.sort();

	for (int f = 0; f < allImageFiles.size(); ++f) {
		std::string filename = allImageFiles[f];
		std::string ext = filenameExt(filename);
		std::string base = (ext != "") ? filename.substr(0, filename.length() - ext.length() - 1) : filename;

		// Skip bump and alpha textures
		if (! (endsWith(base, "-bump") || endsWith(base, "-alpha"))) {
			fileArray.next().color = filename;
			fileArray.last().bump  = findFile(base + "-bump", allFiles);
			fileArray.last().alpha = findFile(base + "-alpha", allFiles);
			if (fileExists(base + ".txt")) {
				fileArray.last().text = base + ".txt";
			} else {
				fileArray.last().text = ""; 
			}
		}
	}

}


std::string App::findFile(const std::string& base, const Set<std::string>& allFiles) {
	for (int f = 0; filetype[f]; ++f) {
		if (allFiles.contains(base + filetype[f])) {
			return base + filetype[f];
		}
	}

	// Not found
	return "";
}
