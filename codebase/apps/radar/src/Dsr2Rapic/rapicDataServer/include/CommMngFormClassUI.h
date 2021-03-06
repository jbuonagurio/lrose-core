
//////////////////////////////////////////////////////////////
//
// Header file for CommMngFormClassUI
//
//    This file is generated by RapidApp 1.2
//
//    This class implements the user interface portion of a class
//    Normally it is not used directly.
//    Instead the subclass, CommMngFormClass is instantiated
//
//    To extend or alter the behavior of this class, you should
//    modify the CommMngFormClass files
//
//    Restrict changes to those sections between
//    the "//--- Start/End editable code block" markers
//
//    This will allow RapidApp to integrate changes more easily
//
//    This class is a ViewKit user interface "component".
//    For more information on how components are used, see the
//    "ViewKit Programmers' Manual", and the RapidApp
//    User's Guide.
//
//////////////////////////////////////////////////////////////
#ifndef COMMMNGFORMCLASSUI_H
#define COMMMNGFORMCLASSUI_H
#include <Vk/VkComponent.h>


//---- Start editable code block: headers and declarations


//---- End editable code block: headers and declarations


// Externally defined classes referenced by this class:

class CommMngTabbedDeck;


class CommMngFormClassUI : public VkComponent
{ 

  public:

    CommMngFormClassUI ( const char *, Widget );
    CommMngFormClassUI ( const char * );
    ~CommMngFormClassUI();
    void create ( Widget );
    const char *  className();

    //---- Start editable code block: CommMngFormClass public


    //---- End editable code block: CommMngFormClass public


  protected:


    // Classes created by this class

    class CommMngTabbedDeck *_deck;

    // Widgets created by this class

    Widget  _commMngFormClass1;


    //---- Start editable code block: CommMngFormClass protected


    //---- End editable code block: CommMngFormClass protected


  private: 

    // Array of default resources

    static String      _defaultCommMngFormClassUIResources[];

    //---- Start editable code block: CommMngFormClass private


    //---- End editable code block: CommMngFormClass private
};
//---- Start editable code block: End of generated code


//---- End editable code block: End of generated code

#endif

