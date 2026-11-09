/**
 @file Collision_Demo/Model.h

 @maintainer Morgan McGuire, matrix@graphics3d.com
 @created 2003-02-07
 @edited  2003-04-06
 */

#ifndef MODEL_H
#define MODEL_H

#include <G3DAll.h>

/**
 Indexed triangle model (could have been implemented as a subclass or wrapper for IFSModel;
 this demo predates the IFSModel class).
 */
class Model {
protected:
	VAR					                varVertex;
	VAR					                varNormal;

    Sphere                              boundingSphere;
    Box                                 boundingBox;

	Array<uint32>		                index;

    Array<Triangle>                     collisionTriangle;

    /**
     A table memoizing already loaded models.
     */
    static Table<std::string, Model*>  table;

    Model(const std::string& filename);

public:

    /**
     Models are cached in memory once loaded; this frees the
     memoization table at the end of the program.
     */
    static void freeModels();

    /** Do not include the DATA_DIR */
    static Model* getModel(const std::string& filename);

    virtual ~Model() {}
    void render() const;

    /**
     Assumes the sphere and velocity are in object space.
     @param sphere      The moving sphere
     @param velocity    Velocity of the sphere
     @param timeLimit   If no collision occurs before the time limit, return inf
     @param outLocation The point in space where the sphere contacts the object.
     @param outNormal   The surface normal at outLocation
     */
    GameTime timeUntilCollisionWithMovingSphere(
        const Sphere&       sphere,
        const Vector3&      velocity,
        GameTime            timeLimit,
        Vector3&            outLocation,
        Vector3&            outNormal) const;
};

#endif //MODEL_H
