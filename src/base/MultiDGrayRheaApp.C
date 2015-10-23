#include "MultiDGrayRheaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<MultiDGrayRheaApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

MultiDGrayRheaApp::MultiDGrayRheaApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  MultiDGrayRheaApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  MultiDGrayRheaApp::associateSyntax(_syntax, _action_factory);
}

MultiDGrayRheaApp::~MultiDGrayRheaApp()
{
}

// External entry point for dynamic application loading
extern "C" void MultiDGrayRheaApp__registerApps() { MultiDGrayRheaApp::registerApps(); }
void
MultiDGrayRheaApp::registerApps()
{
  registerApp(MultiDGrayRheaApp);
}

// External entry point for dynamic object registration
extern "C" void MultiDGrayRheaApp__registerObjects(Factory & factory) { MultiDGrayRheaApp::registerObjects(factory); }
void
MultiDGrayRheaApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void MultiDGrayRheaApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { MultiDGrayRheaApp::associateSyntax(syntax, action_factory); }
void
MultiDGrayRheaApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
