#include "App.h"

#define LOAD_ALL 0

void App::loadScene() {
    const std::string path = "";

    const Matrix3 rot180 = Matrix3::fromAxisAngle(Vector3::unitY(), toRadians(180));

    double x = -5;

    RealTime t0 = System::time();

    if (true) {
        ArticulatedModelRef model = ArticulatedModel::fromFile("sphere.ifs", 1);

        SuperShader::Material& material = model->partArray[0].triListArray[0].material;
        model->partArray[0].triListArray[0].twoSided = false;
        material.diffuse = Color3::white() * 1.0f;
        material.specular = Color3::white() * 0.7f;
        material.specularExponent = Color3::white() * 60;
        model->updateAll();

        entityArray.append(Entity::create(model, CoordinateFrame(Vector3(x,0,-2))));
    }

#if LOAD_ALL
    if (true) {
        CoordinateFrame xform;

        xform.rotation[0][0] = xform.rotation[1][1] = xform.rotation[2][2] = 0.008f;

        xform.rotation = xform.rotation * rot180;
        xform.translation = Vector3(0, 0, 0.5);
        std::string path = "ghost/";
        ArticulatedModelRef model = ArticulatedModel::fromFile(path + "SpaceFighter01.3ds", xform);

        // Override the textures in the file with more interesting ones

        TextureRef diffuse = Texture::fromFile(path + "diffuse.jpg");
        {
            SuperShader::Material& material = model->partArray[0].triListArray[0].material;
            material.emit = Texture::fromFile(path + "emit.jpg");
            material.diffuse.map = diffuse;
            material.diffuse.constant = Color3::white() * 0.8f;
            material.transmit = Color3::black();
            material.specular = Texture::fromFile(path + "specular.jpg");
            material.reflect = Color3::black();
            material.specularExponent = Color3::white() * 40;
        }

        {
            SuperShader::Material& material = model->partArray[0].triListArray[1].material;
            material.emit = Color3::black();
            material.diffuse.map = diffuse;
            material.diffuse.constant = Color3::white() * 0.5f;
            material.transmit = Color3::black();
            material.specular = Color3::green() * .5f;
            material.reflect = Color3::white() * 0.4f;
            material.specularExponent = Color3::white() * 40;
        }

        model->updateAll();

        entityArray.append(Entity::create(model, CoordinateFrame(rot180, Vector3(x,2,0))));
        Log::common()->printf("Ghost: %gs\n", System::time() - t0); t0 = System::time();
    }

    if (true) {
        ArticulatedModelRef model = ArticulatedModel::fromFile("sphere.ifs", 1);

        {
            SuperShader::Material& material = model->partArray[0].triListArray[0].material;
            model->partArray[0].triListArray[0].twoSided = false;

            ArticulatedModel::Part& part = model->partArray.last();

            // Spherical texture map (there will be a seam on the back)
            part.texCoordArray.resize(part.geometry.normalArray.size());
            for (int i = 0; i < part.geometry.normalArray.size(); ++i) {
                const Vector3& N = part.geometry.normalArray[i];
                part.texCoordArray[i].x = 0.5 + atan2(N.x, N.z) / G3D_TWO_PI;
                part.texCoordArray[i].y = 0.5 - N.y / 2.0;
            }

            material.diffuse  = Texture::fromFile("earth/diffuse.jpg");
            material.specular = Texture::fromFile("earth/specular.png");
            material.emit     = Texture::fromFile("earth/emit.png");

            material.specularExponent = Color3::white() * 30;
        }

        // Cloud layer
        {
            ArticulatedModel::Part& part = model->partArray.next();
            ArticulatedModelRef temp = ArticulatedModel::fromFile("sphere.ifs", 1.02f);
            part = temp->partArray.last();
            part.name = "Clouds";
            SuperShader::Material& material = part.triListArray[0].material;

            // Spherical texture map (there will be a seam on the back)
            part.texCoordArray.resize(part.geometry.normalArray.size());
            for (int i = 0; i < part.geometry.normalArray.size(); ++i) {
                const Vector3& N = part.geometry.normalArray[i];
                part.texCoordArray[i].x = 0.5 + atan2(N.x, N.z) / G3D_TWO_PI;
                part.texCoordArray[i].y = 0.5 - N.y / 2.0;
            }

            material.diffuse   = Texture::fromFile("earth/cloud-diffuse.jpg");
            material.transmit  = Texture::fromFile("earth/cloud-transmit.jpg");
            material.specularExponent = Color3::white() * 10;
        }

        model->updateAll();
        entityArray.append(Entity::create(model, CoordinateFrame(Vector3(x,0,0))));
        x += 2;
        Log::common()->printf("Earth: %gs\n", System::time() - t0); t0 = System::time();
    }

    {
        ArticulatedModelRef model = ArticulatedModel::fromFile("sphere.ifs", 1);

        SuperShader::Material& material = model->partArray[0].triListArray[0].material;
        model->partArray[0].triListArray[0].twoSided = true;
        material.diffuse = Color3::yellow() * .5f;
        material.transmit = Color3(.5f,.3f,.3f);
        material.reflect = Color3::white() * .1f;
        material.specular = Color3::white() * .7f;
        material.specularExponent = Color3::white() * 40;
        model->updateAll();

        entityArray.append(Entity::create(model, CoordinateFrame(Vector3(x,0,0))));
        x += 2;
        Log::common()->printf("Sphere: %gs\n", System::time() - t0); t0 = System::time();
    }


     if (true) {
        ArticulatedModelRef model = ArticulatedModel::createEmpty();

        model->name = "Maple Leaf";
        ArticulatedModel::Part& part = model->partArray.next();
        part.cframe = CoordinateFrame();
        part.name = "root";
    
        const double S = 1.0;
        part.geometry.vertexArray.append(
            Vector3(-S,  S, 0),
            Vector3(-S, -S, 0),
            Vector3( S, -S, 0),
            Vector3( S,  S, 0));

        part.geometry.normalArray.append(
            Vector3::unitZ(),
            Vector3::unitZ(),
            Vector3::unitZ(),
            Vector3::unitZ());

        double texScale = 1;
        part.texCoordArray.append(
            Vector2(0,0) * texScale,
            Vector2(0,1) * texScale,
            Vector2(1,1) * texScale,
            Vector2(1,0) * texScale);

        part.tangentArray.append(
            Vector3::unitX(),
            Vector3::unitX(),
            Vector3::unitX(),
            Vector3::unitX());

        ArticulatedModel::Part::TriList& triList = part.triListArray.next();
        triList.indexArray.clear();
        triList.indexArray.append(0, 1, 2);
        triList.indexArray.append(0, 2, 3);

        triList.twoSided = true;

        triList.material.diffuse = Texture::fromFile("maple.tga");

        triList.computeBounds(part);

        part.indexArray = triList.indexArray;

        part.computeIndexArray();
        part.updateVAR();
        part.updateShaders();

        entityArray.append(Entity::create(model, CoordinateFrame(Vector3(x,0,0))));
        x += 2;
     }

    if (false) {
        ArticulatedModelRef model = ArticulatedModel::fromFile("sphere.ifs", 1);

        SuperShader::Material& material = model->partArray[0].triListArray[0].material;
        model->partArray[0].triListArray[0].twoSided = false;
        material.diffuse = Color3::white() * 0.7f;
        material.specular = Color3::white() * .5f;
        material.specularExponent = Color3::white() * 60;
        model->updateAll();

        entityArray.append(Entity::create(model, CoordinateFrame(Vector3(x,0,-2))));
    }

    if (true) {
        CoordinateFrame xform;

        xform.rotation[0][0] = xform.rotation[1][1] = xform.rotation[2][2] = 0.04f;

        xform.rotation = xform.rotation * rot180;
        xform.translation = Vector3(-0.35f, -1.45f, 2.25f);
        ArticulatedModelRef model = ArticulatedModel::fromFile("legocar.3ds", xform);
        entityArray.append(Entity::create(model, CoordinateFrame(rot180, Vector3(x,0,0))));
        x += 2;
    }

    {
        ArticulatedModelRef model = ArticulatedModel::fromFile("jackolantern.ifs", 1);

        SuperShader::Material& material = model->partArray[0].triListArray[0].material;
        material.diffuse = Color3::fromARGB(0xF28900) * 0.9f;
        material.transmit = Color3::black();
        material.reflect = Color3::black();
        material.specular = Color3::white() * .05f;
        material.specularExponent = Color3::white() * 10;
        model->updateAll();

        entityArray.append(Entity::create(model, CoordinateFrame(rot180, Vector3(x,0,0))));
        x += 2;
    }

    {
        // Animated, hierarchical part
        ArticulatedModelRef ball = ArticulatedModel::fromFile("dodeca.ifs");
        ArticulatedModelRef child = ArticulatedModel::fromFile("tetra.ifs", .2f);

        ArticulatedModelRef model = ArticulatedModel::createEmpty();
        model->name = "Spinner";

        {
            ArticulatedModel::Part& part = model->partArray.next();
            part = ball->partArray.last();
            part.name = "Top";
            part.subPartArray.append(2);
            part.cframe = CoordinateFrame(Vector3(0,0.5f,0));
        }
        {
            ArticulatedModel::Part& part = model->partArray.next();
            part = ball->partArray.last();
            part.name = "Bottom";
            part.cframe = CoordinateFrame(Vector3(0,-0.5f,0));
        }
        {
            ArticulatedModel::Part& part = model->partArray.next();
            part = child->partArray.last();
            part.name = "Nose";
            part.cframe = CoordinateFrame(Vector3(0,0,.5f));
            part.parent = 0;
            SuperShader::Material& material = part.triListArray[0].material;
            material.diffuse = Color3::red();
        }

        entityArray.append(Entity::create(model, CoordinateFrame(Vector3(x,0,0))));
        x += 2;
    }

    {
        ArticulatedModelRef model = ArticulatedModel::fromFile("teapot.ifs", 1.5);

        Color3 brass = Color3::fromARGB(0xFFFDDC01);

        SuperShader::Material& material = model->partArray[0].triListArray[0].material;
        material.diffuse = brass * .3f;
        material.reflect = brass * .4f;
        material.specular = Color3::white() * .8f;
        material.specularExponent = Color3::white() * 25;
        model->updateAll();

        CoordinateFrame cframe(Vector3(x,-.25f,0));
        cframe.lookAt(Vector3(5,0,5));
        entityArray.append(Entity::create(model, cframe));
        x += 2;
    }

    {
        CoordinateFrame xform;

        xform.rotation[0][0] = xform.rotation[1][1] = xform.rotation[2][2] = 0.004f;
        xform.translation.x = 3.5;
        xform.translation.y = 1;
        ArticulatedModelRef model = ArticulatedModel::fromFile("imperial.3ds", xform);

        entityArray.append(Entity::create(model, CoordinateFrame(rot180, Vector3(x - 2, 1, 0))));
    }


     if (true) {
        ArticulatedModelRef model = ArticulatedModel::createEmpty();

        model->name = "Stained Glass";
        ArticulatedModel::Part& part = model->partArray.next();
        part.cframe = CoordinateFrame();
        part.name = "root";
    
        const float S = 1.0f;
        part.geometry.vertexArray.append(
            Vector3(-S,  S, 0),
            Vector3(-S, -S, 0),
            Vector3( S, -S, 0),
            Vector3( S,  S, 0));

        part.geometry.normalArray.append(
            Vector3::unitZ(),
            Vector3::unitZ(),
            Vector3::unitZ(),
            Vector3::unitZ());

        double texScale = 1;
        part.texCoordArray.append(
            Vector2(0,0) * texScale,
            Vector2(0,1) * texScale,
            Vector2(1,1) * texScale,
            Vector2(1,0) * texScale);

        part.tangentArray.append(
            Vector3::unitX(),
            Vector3::unitX(),
            Vector3::unitX(),
            Vector3::unitX());

        ArticulatedModel::Part::TriList& triList = part.triListArray.next();
        triList.indexArray.clear();
        triList.indexArray.append(0, 1, 2);
        triList.indexArray.append(0, 2, 3);

        triList.twoSided = true;
        triList.material.emit.constant = Color3::black();

        triList.material.diffuse.constant = Color3::white() * 0.05f;

        GImage normalBumpMap;
        computeNormalMap(GImage("stained-glass-bump.png"), normalBumpMap, false, true);
        triList.material.normalBumpMap =         
            Texture::fromGImage("Bump Map", normalBumpMap, TextureFormat::AUTO, Texture::CLAMP);

        triList.material.bumpMapScale = 0.02f;

        triList.material.specular.constant = Color3::white() * 0.4f;
        triList.material.specular.map = Texture::fromFile("stained-glass-mask.png", TextureFormat::AUTO, Texture::CLAMP);
        triList.material.specularExponent.constant = Color3::white() * 60;

        triList.material.reflect.constant = Color3::white() * 0.2f;
        triList.material.reflect.map = Texture::fromFile("stained-glass-mask.png", TextureFormat::AUTO, Texture::CLAMP);

        triList.material.transmit.constant = Color3::white();
        triList.material.transmit.map = Texture::fromFile("stained-glass-transmit.png", TextureFormat::AUTO, Texture::CLAMP);

        triList.computeBounds(part);

        part.indexArray = triList.indexArray;

        part.computeIndexArray();
        part.updateVAR();
        part.updateShaders();

        entityArray.append(Entity::create(model, CoordinateFrame(Vector3(x,0,0))));
        x += 2;
     }

     if (false) {
         // 2-sided test
        ArticulatedModelRef model = ArticulatedModel::createEmpty();

        model->name = "White Square";
        ArticulatedModel::Part& part = model->partArray.next();
        part.cframe = CoordinateFrame();
        part.name = "root";
    
        const double S = 1.0;
        part.geometry.vertexArray.append(
            Vector3(-S,  S, 0),
            Vector3(-S, -S, 0),
            Vector3( S, -S, 0),
            Vector3( S,  S, 0));

        part.geometry.normalArray.append(
            Vector3::unitZ(),
            Vector3::unitZ(),
            Vector3::unitZ(),
            Vector3::unitZ());

        double texScale = 1;
        part.texCoordArray.append(
            Vector2(0,0) * texScale,
            Vector2(0,1) * texScale,
            Vector2(1,1) * texScale,
            Vector2(1,0) * texScale);

        part.tangentArray.append(
            Vector3::unitX(),
            Vector3::unitX(),
            Vector3::unitX(),
            Vector3::unitX());

        ArticulatedModel::Part::TriList& triList = part.triListArray.next();
        triList.indexArray.clear();
        triList.indexArray.append(0, 1, 2);
        triList.indexArray.append(0, 2, 3);

        triList.twoSided = true;
        triList.material.emit.constant = Color3::black();

        triList.material.diffuse.constant = Color3::white();
        triList.computeBounds(part);

        part.indexArray = triList.indexArray;

        part.computeIndexArray();
        part.updateVAR();
        part.updateShaders();

        entityArray.append(Entity::create(model, CoordinateFrame(rot180, Vector3(x,0,0))));
        x += 2;
    }
#endif
    if (true) {
        ArticulatedModelRef model = ArticulatedModel::createEmpty();

        model->name = "Ground Plane";
        ArticulatedModel::Part& part = model->partArray.next();
        part.cframe = CoordinateFrame();
        part.name = "root";
    
        const float S = 10.0;
        part.geometry.vertexArray.append(
            Vector3(-S, 0, -S),
            Vector3(-S, 0, S),
            Vector3(S, 0, S),
            Vector3(S, 0, -S));

        double texScale = 5;
        part.texCoordArray.append(
            Vector2(0,0) * texScale,
            Vector2(0,1) * texScale,
            Vector2(1,1) * texScale,
            Vector2(1,0) * texScale);

        ArticulatedModel::Part::TriList& triList = part.triListArray.next();
        triList.indexArray.clear();
        triList.indexArray.append(0, 1, 2);
        triList.indexArray.append(0, 2, 3);

        triList.twoSided = true;
        triList.material.emit.constant = Color3::black();

        triList.material.specular.constant = Color3::black();
        triList.material.specularExponent.constant = Color3::white() * 60;
        triList.material.reflect.constant = Color3::black();

        triList.material.diffuse.constant = Color3::white() * 0.8f;
        triList.material.diffuse.map = Texture::fromFile("stone.jpg", TextureFormat::AUTO, Texture::TILE,
            Texture::TRILINEAR_MIPMAP, Texture::DIM_2D, 1.0f, Texture::DEPTH_NORMAL, 4.0f);

        GImage normalBumpMap;
        computeNormalMap(GImage("stone-bump.png"), normalBumpMap, false, true);
        triList.material.normalBumpMap =         
            Texture::fromGImage("Bump Map", normalBumpMap, TextureFormat::AUTO, Texture::TILE,
            Texture::TRILINEAR_MIPMAP, Texture::DIM_2D, Texture::DEPTH_NORMAL, 1.0f);

        triList.material.bumpMapScale = 0.04f;

        triList.computeBounds(part);

        part.indexArray = triList.indexArray;

        part.computeIndexArray();
        part.computeNormalsAndTangentSpace();
        part.updateVAR();
        part.updateShaders();

        entityArray.append(Entity::create(model, CoordinateFrame(Vector3(0,-1,0))));
    }


//		"contrib/ArticulatedModel/3ds/f16/f16b.3ds"
//		"contrib/ArticulatedModel/3ds/cube.3ds"
//		"contrib/ArticulatedModel/3ds/jeep/jeep.3ds", 0.1
//		"contrib/ArticulatedModel/3ds/house/house.3ds", 0.01
//		"contrib/ArticulatedModel/3ds/delorean/delorean.3ds", 0.1
//		"contrib/ArticulatedModel/3ds/car35/car35.3ds", 0.1
//		"d:/users/morgan/projects/3ds/fs/fs.3ds"
    lighting = Lighting::create();
    {
        skyParameters = LightingParameters(G3D::toSeconds(1, 00, 00, PM));
    
        skyParameters.skyAmbient = Color3::white();

        if (sky.notNull()) {
            lighting->environmentMap = sky->getEnvironmentMap();
            lighting->environmentMapColor = skyParameters.skyAmbient;
        } else {
            lighting->environmentMapColor = Color3::black();
        }

        lighting->ambientTop = Color3(0.7f, 0.7f, 1.0f) * skyParameters.diffuseAmbient;
        lighting->ambientBottom = Color3::brown() * skyParameters.diffuseAmbient;

        lighting->emissiveScale = skyParameters.emissiveScale;

        lighting->lightArray.clear();

        lighting->shadowedLightArray.clear();

        GLight L = skyParameters.directionalLight();
        // Decrease the blue since we're adding blue ambient
        L.color *= Color3(1.2f, 1.2f, 1);
        L.position = Vector4(Vector3(0,1,1).direction(), 0);

        lighting->shadowedLightArray.append(L);
    }
}
