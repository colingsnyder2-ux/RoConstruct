#include "header.h"

BumpEffect::BumpEffect() {
    // TODO: put shaders into directory
    std::string base = "D:/games/cpp/source/tools/BumpMapViewer/bump";
	_vertexAndPixelShader = VertexAndPixelShader::fromFiles(base + ".vert", base + ".frag");
	bumpScale = 0.04;
}


BumpEffectRef BumpEffect::create() {
    return new BumpEffect();
}


void BumpEffect::beforePrimitive(RenderDevice* rd) {

    rd->pushState();
    // Pick up the current object and world space matrices
    CoordinateFrame camera = rd->getCameraToWorldMatrix();
    CoordinateFrame cframe = rd->getObjectToWorldMatrix();

    args.set("wsLightPos",      light);
    args.set("osEyePos",        cframe.pointToObjectSpace(camera.translation));
    args.set("wsEyePos",        camera.translation);
    args.set("objectToWorld",   cframe);
    args.set("texture",         textureMap);
    args.set("normalBumpMap",   normalMap);
    args.set("reflectivity",    0.2);
	args.set("specularity",     0.4);
	args.set("bumpScale",       bumpScale);
    args.set("environmentMap",  environmentMap);

    rd->setVertexAndPixelShader(_vertexAndPixelShader, args);
}

void BumpEffect::afterPrimitive(RenderDevice* rd) {
    rd->popState();
}

void BumpEffect::load(const FileSet& f) {
	if (f.alpha == "") {
		textureMap = Texture::fromFile(f.color);
	} else {
		textureMap = Texture::fromTwoFiles(f.color, f.alpha);
	}

	if (f.bump != "") {
		normalMap = loadBumpAsNormalMap(f.bump);
	} else {
		normalMap = NULL;
	}

	description.clear();
	if (f.text != "") {
		FILE* fl = fopen(f.text.c_str(), "rt");
		
		const int buflen = 2048;
		char buf[buflen];
		while (! feof(fl)) {
			if (fgets(buf, buflen, fl)) {
				description.append(buf);
			}
		}
		fclose(fl);
	}
}


TextureRef BumpEffect::loadBumpAsNormalMap(const std::string& filename) {
	GImage normal;
	computeNormalMap(GImage(filename), normal);
	return Texture::fromGImage(filename, normal);
}
