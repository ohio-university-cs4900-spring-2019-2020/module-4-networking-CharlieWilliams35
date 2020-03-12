#pragma once

#include "GLView.h"
#include "NetMessengerClient.h"
#include "WorldContainer.h"

namespace Aftr
{
   class Camera;

/**
   \class GLViewModule4
   \author Scott Nykl 
   \brief A child of an abstract GLView. This class is the top-most manager of the module.

   Read \see GLView for important constructor and init information.

   \see GLView

    \{
*/

class GLViewModule4 : public GLView
{
public:
   static GLViewModule4* New( const std::vector< std::string >& outArgs );
   virtual ~GLViewModule4();
   virtual void updateWorld(); ///< Called once per frame
   virtual void loadMap(); ///< Called once at startup to build this module's scene
   virtual void createModule4WayPoints();
   WorldContainer* getWorldContainer();
   virtual void onResizeWindow( GLsizei width, GLsizei height );
   virtual void onMouseDown( const SDL_MouseButtonEvent& e );
   virtual void onMouseUp( const SDL_MouseButtonEvent& e );
   virtual void onMouseMove( const SDL_MouseMotionEvent& e );
   virtual void onKeyDown( const SDL_KeyboardEvent& key );
   virtual void onKeyUp( const SDL_KeyboardEvent& key );
   virtual void createRandomObject();
   //virtual void createNewModel(std::string model, Vector v);
  // virtual std::string get_model();

protected:
   GLViewModule4( const std::vector< std::string >& args );
   virtual void onCreate(); 
   NetMessengerClient* client;
   unsigned int numObjects;
};

/** \} */

} //namespace Aftr
