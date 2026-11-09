/**
 @file Collision_Demo/Scene.cpp

 Contains the shadow map implementation

 @maintainer Morgan McGuire, matrix@graphics3d.com
 @created 2003-02-07
 @edited  2004-09-05
 */

#include "Scene.h"
#include "Object.h"

extern GApp* app;

static const Vector3 gravity(0, -60, 0);

static Vector3 debugPoint = Vector3::zero();

/**
 How much energy is preserved in a collision.
 As gravity grows, this must shrink or it is hard to
 get the system to converge to zero energy (although
 it will be stable).
 */
static const double coefficientOfRestitution = 0.9;

/**
 Width and height of shadow map.
 */
static const int shadowMapSize = 512;

/**
 Light projection parameters.
 */
const double lightProjX = 17, lightProjY = 17, lightProjNear = 1, lightProjFar = 40;

/**
 Turn on to see what the light sees.
 */
static bool debugLightMap = false;


Scene::Scene() {
    sky = Sky::create(app->renderDevice, app->dataDir + "sky/");

    if (GLCaps::supports_GL_ARB_shadow()) {
        shadowMap = Texture::createEmpty(shadowMapSize, shadowMapSize, "Shadow map", TextureFormat::depth(),
            Texture::CLAMP, Texture::BILINEAR_NO_MIPMAP, Texture::DIM_2D, Texture::DEPTH_LEQUAL);
    }
}


Scene::~Scene() {
    clear();
}


void Scene::clear(){
    object.deleteAll();
    sim.deleteAll();
}


void Scene::renderingPass() const {
    int i;

    for (i = 0; i < object.size(); ++i) {
        object[i]->render();
    }

    for (i = 0; i < sim.size(); ++i) {
      sim[i]->render();
    }

    // Draw::sphere(Sphere(debugPoint, .1), app->renderDevice);
}


void Scene::generateShadowMap(
    const CoordinateFrame& lightViewMatrix) const {

    debugAssert(shadowMapSize < app->renderDevice->getHeight());
    debugAssert(shadowMapSize < app->renderDevice->getWidth());

    app->renderDevice->clear(debugLightMap, true, false);
    
    Rect2D rect = Rect2D::xywh(0, 0, shadowMapSize, shadowMapSize);

    app->renderDevice->pushState();
        app->renderDevice->setViewport(rect);

	    // Draw from the light's point of view
        app->renderDevice->setProjectionMatrix(Matrix4::orthogonalProjection(-lightProjX, lightProjX, -lightProjY, lightProjY, lightProjNear, lightProjFar));
        app->renderDevice->setCameraToWorldMatrix(lightViewMatrix);

        if (! debugLightMap) {
            app->renderDevice->disableColorWrite();
        }

        // We can choose to use a large bias or render from
        // the backfaces in order to avoid front-face self
        // shadowing.  Here, we use a large offset.
        app->renderDevice->setPolygonOffset(4);

        renderingPass();
    app->renderDevice->popState();

    shadowMap->copyFromScreen(rect);
}


void Scene::render(const LightingParameters& lighting) const {
    // Construct a projection and view matrix for the camera so we can 
    // render the scene from the light's point of view
    Matrix4 lightProjectionMatrix(Matrix4::orthogonalProjection(-lightProjX, lightProjX, -lightProjY, lightProjY, lightProjNear, lightProjFar));

    CoordinateFrame lightCFrame;
    lightCFrame.lookAt(-lighting.lightDirection, Vector3::unitY());
    lightCFrame.translation = lighting.lightDirection * 20;

    Matrix4 lightMVP = lightProjectionMatrix * lightCFrame.inverse();

    if (GLCaps::supports_GL_ARB_shadow()) {
        generateShadowMap(lightCFrame);
        if (debugLightMap) {
            return;
        }
    }  

    debugAssertGLOk();
    app->renderDevice->clear(sky == NULL, true, false);
    debugAssertGLOk();

    if (sky != NULL) {
		sky->render(lighting);
    }

    debugAssertGLOk();
    app->renderDevice->pushState();
    
        // Ambient and detail light pass. 
        app->renderDevice->enableLighting();
        app->renderDevice->setLight(0, GLight::directional(-lighting.lightDirection, Color3::white() * .25));
        app->renderDevice->setAmbientLightColor(lighting.ambient);
        app->renderDevice->setShadeMode(RenderDevice::SHADE_SMOOTH);
        renderingPass();

        // Sun light pass
        app->renderDevice->setAmbientLightColor(Color3::black());
        app->renderDevice->setDepthTest(RenderDevice::DEPTH_LEQUAL);
        app->renderDevice->disableDepthWrite();
        app->renderDevice->setLight(0, GLight::directional(lighting.lightDirection, lighting.lightColor));

        app->renderDevice->setBlendFunc(RenderDevice::BLEND_ONE, RenderDevice::BLEND_ONE);

        if (GLCaps::supports_GL_ARB_shadow()) {
            app->renderDevice->configureShadowMap(1, lightMVP, shadowMap);
        }
        renderingPass();
    app->renderDevice->popState();

    if (sky != NULL) {
        sky->renderLensFlare(lighting);
    }
    
}


void Scene::insertStatic(Object* obj) {
    object.append(obj);
}


void Scene::insertDynamic(SimSphere* s) {
    sim.append(s);
}


GameTime Scene::timeUntilCollisionWithMovingSphere(
    const Sphere&       sphere,
    const Vector3&      velocity,
    GameTime            timeLimit,
    Vector3&            outLocation,
    Vector3&            outNormal) const {

    GameTime outTime = inf();

    for (int i = 0; i < object.size(); ++i) {

        Vector3 testLocation, testNormal;
        GameTime testTime;

        testTime = object[i]->timeUntilCollisionWithMovingSphere(sphere, velocity, timeLimit, testLocation, testNormal);

        if (testTime < outTime) {
            outTime     = testTime;
            outLocation = testLocation;
            outNormal   = testNormal;
        }
    }

    return outTime;
}


// Support for special kinds of contact beyond collisions

/** Keeps resting objects from gaining energy. */
#define RESTING_CONTACT 1

/** Makes rolling objects stick to the surface along which they are rolling. */
#define ROLLING_CONTACT 1

/** Helps objects come to rest. */
#define SUPER_DAMPING   1

void Scene::simulate(GameTime duration) {

    for (int i = 0; i < sim.size(); ++i) {
        SimSphere* obj = sim[i];

        GameTime time = 0.0;

        // Don't get stuck with too many micro-collisions
        int count = 0;
        while ((time < duration) && (count < 10)) {

            // Detect collisions
            Vector3 collisionLocation, collisionNormal, acceleration = gravity;
            GameTime delta;

            delta = timeUntilCollisionWithMovingSphere(obj->sphere, obj->velocity, duration, collisionLocation, collisionNormal);

            #if (RESTING_CONTACT)
                // Resting contact and stuck in a surface
                if (fuzzyEq(delta, 0.0)) {
                    // Despite our best efforts, sometimes a sphere penetrates an object and
                    // becomes stuck.  When this occurs, the highest priority is resolving
                    // the interpenetration.  Our first method is to bump the object slightly 
                    // (it may just be resting on the surface) and see if that avoids the
                    // collision.
                    //
                    // If that fails, we'll redirect the object's velocity out of the surface
                    // and temporarily turn off all acceleration.

                    // Maximum distance at which interpenetration can be considered "resting"
                    // and not "stuck".
                    const double restingInterpenetration = 0.005;

                    if ((collisionLocation - obj->sphere.center).length() > 
                            obj->sphere.radius - restingInterpenetration) {

                        // The sphere is just resting on the surface, not stuck deeply within it.  Bump
                        // the sphere away from the surface and find another collision.
                        Sphere bumpedSphere(obj->sphere.center + collisionNormal * restingInterpenetration, obj->sphere.radius);
                        delta = timeUntilCollisionWithMovingSphere(bumpedSphere, obj->velocity, duration, collisionLocation, collisionNormal);

                        if (! fuzzyEq(delta, 0.0)) {
                            // Resting

                            // Move the sphere to the bumped location; we were
                            // indeed just resting (or rolling).
                            Vector3 deltaPosition = bumpedSphere.center - obj->sphere.center;
                            obj->sphere.center = bumpedSphere.center;

                            // This will add a little energy to the system, so take
                            // away what we added.  The increase in potential energy 
                            // was:
                            //
                            //   dPE = (dPosition dot acceleration) * mass
                            //
                            // We want a corresponding decrease in kinetic energy:
                            //
                            //   dKE = -dPE = KE1 - KE0
                            // where KE0 = 1/2 mass * v0^2, KE1 = 1/2 mass * v1^2
                            // 
                            //   v1 = sqrt(2(dPosition dot accleration) + v0^2)
                            double v0 = obj->velocity.length();

                            if (! fuzzyEq(v0, 0.0)) {
                                double v1 = sqrt(deltaPosition.dot(acceleration) + square(v0));
                                obj->velocity = obj->velocity * v1 / v0;
                            }
                        }

                        // If we didn't find a new collision that occurs after zero time, we'll
                        // fall into the following IF statement.
                    }


                    if (fuzzyEq(delta, 0.0)) {
                        // Stuck
                        //
                        // The object must really be stuck.  Ignore the collision as well,
                        // as acceleration due to gravity and move the sphere out of the
                        // surface by redirecting its velocity.
                
                        if (obj->velocity.squaredLength() < 1) {
                            // The velocity is too low to move it out on its own.
                            obj->velocity = collisionNormal;
                        } else {
                            // Redirect all velocity along the collision normal.
                            obj->velocity = obj->velocity.length() * collisionNormal;
                        }
                        delta = inf();
                        acceleration = Vector3::zero();
                    }
                }
            #endif
            

            if (fuzzyLt(time + delta, duration)) {
                debugAssert(isFinite(delta));

                debugPoint = collisionLocation;

                // A collision occurs this duration

                // Find the bounce direction
                Vector3 bounceDirection =
                    CollisionDetection::bounceDirection(obj->sphere, obj->velocity, delta, collisionLocation, collisionNormal);

                if (! bounceDirection.isFinite()) {
                    bounceDirection = Vector3::zero();
                }
                debugAssert(isFinite(bounceDirection.x));


                // Integrate forward
                {
                    // Integrate the sphere forward to just before the collision time. 
                    // We don't move to the actual collision time because roundoff could
                    // cause interpenetration, which would get us stuck on thin or sharp
                    // objects or cause us to miss a subsequent collision.
                    delta = max(0.0, delta - 0.0005);
                    obj->sphere.center += obj->velocity * delta;
                }


                // Avoid sticking on corners
                if ((bounceDirection.dot(collisionNormal) < -.9)) {
                    // The bounce direction is very close to opposite the collision
                    // normal and back along the original velocity, which means that 
                    // we're about to be sent right back into the same collision if
                    // we follow this bounce direction.  To fix this, we tweak the
                    // bounce direction towards the tangent.
                    //
                    // This situation usually occurs when we just brush the edge of an
                    // object and is rare.

                    Vector3 tangent = (obj->sphere.center - collisionLocation).direction();

                    bounceDirection = (bounceDirection + tangent * 0.5f).direction();     
                }

                // Apply acceleration, then change direction.  If we apply acceleration after
                // changing direction, the acceleration effects will be in the wrong direction
                // because they won't apply to the time period just simulated.
                obj->velocity = bounceDirection * (obj->velocity + delta * acceleration).length();
                
                double nv = obj->velocity.dot(collisionNormal);
                double an = acceleration.dot(collisionNormal);
                double av = acceleration.dot(obj->velocity);
                
                if (! acceleration.isZero()) {
                    // If acceleration is not zero, divide the acceleration-velocity
                    // dot product by the magnitude of acceleration, then divide
                    // *again* by the magnitude times the timestep.
                    // 
                    // We're going to use this value to determine if a sphere is 
                    // bouncing slightly and needs to come to rest.  The second division
                    // takes into account the fact that we need a larger cutoff
                    // velocity for "moving too slowly: bring this object to rest"
                    // when large accelerations are at play.
                    av /= duration * pow(acceleration.squaredLength(), 0.75f);
                }

                if ((an < 0) && (nv * duration <= 0.05) && ROLLING_CONTACT) {
                    // Rolling contact
                    //
                    // After collision the sphere is travelling mostly parallel
                    // to a surface and acceleration is pushing it back into
                    // the surface.  Change the velocity so the sphere rolls exactly 
                    // along the surface.
                    //
                    // Although this demo does not implement it, this is where rolling
                    // friction would be accounted for.
                    //
                    // The critical minimum velocity must *increase* as the duration
                    // (timestep) *decreases*.

                    debugAssert(collisionNormal.isUnit());

                    // Parallel direction.  Might be zero, so we check the length
                    // explicitly.
                    const Vector3  parallel   = obj->velocity - nv * collisionNormal;
                    double len = parallel.length();
                    if (len < 0.00001) {
                        obj->velocity = Vector3::zero();
                    } else {
                        obj->velocity = parallel * obj->velocity.length() / len;
                    }

                } else if (SUPER_DAMPING) {
                    // The velocity is small and opposite acceleration.  This
                    // sphere may be trying to come to rest; take more energy
                    // away than we normally do.

                    double d = -acceleration.dot(obj->velocity) / (acceleration.length() * obj->velocity.length());
                    double alpha = 1;

                    // TODO: take acceleration and duration into account
                    if ((d > .85) && (obj->velocity.length() < 5)) {
                        if (d > .95) {
                            alpha = .01;
                        } else if (d > .9) {
                            alpha = .05;
                        } else {
                            alpha = .1;
                        }
                    }

                    obj->velocity *= alpha * coefficientOfRestitution;

                } else {
                    // The collision was not part of rolling contact, so
                    // we reduce the velocity by the coefficient of restitution.
                    obj->velocity *= coefficientOfRestitution;
                    
                }

            } else {
                // No collision occurs; finish off this time interval
                delta = duration - time;
                obj->sphere.center += delta * obj->velocity;

                if (RESTING_CONTACT && obj->velocity.isZero() && ! acceleration.isZero()) {
                    GameTime t = timeUntilCollisionWithMovingSphere(obj->sphere, acceleration * duration, duration, collisionLocation, collisionNormal);
                    // See if acceleration will cause us to leave resting contact
                    if (t < 0.01) {
                        // If we accelerate, we'll immediately hit a surface
                        Vector3 bounceDirection =
                            CollisionDetection::bounceDirection(obj->sphere, acceleration * duration, t, collisionLocation, collisionNormal);
                        double align = bounceDirection.dot(acceleration.direction());
                        if (align < -.95) {
                            // The collision will cause us to bounce straight up; don't use the acceleration
                            acceleration = Vector3::zero();
                        }
                    }
                }

                // Apply acceleration over the time period we just simulated
                obj->velocity += acceleration * delta;
            }

            debugAssert(obj->velocity.isFinite());
            debugAssert(obj->sphere.center.isFinite());

            GameTime old = time;
            time += delta;
            
            // Make sure we make some progress
            if (time <= old) {
                time += duration / 20.0;
            }
            ++count;
        }

        // If a sphere leaves the simulation, bring it back
        if (obj->sphere.center.squaredLength() > 40 * 40) {
            obj->sphere.center = Vector3(0, obj->sphere.radius * 2, 0);
            obj->velocity = Vector3::random() * 25;
        }

    }
}


