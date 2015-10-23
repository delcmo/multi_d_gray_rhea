#ifndef MULTI_D_GRAY_RHEAAPP_H
#define MULTI_D_GRAY_RHEAAPP_H

#include "MooseApp.h"

class MultiDGrayRheaApp;

template<>
InputParameters validParams<MultiDGrayRheaApp>();

class MultiDGrayRheaApp : public MooseApp
{
public:
  MultiDGrayRheaApp(InputParameters parameters);
  virtual ~MultiDGrayRheaApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* MULTI_D_GRAY_RHEAAPP_H */
