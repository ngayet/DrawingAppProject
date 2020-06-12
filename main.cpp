//************************************************************************
//************************************************************************
// skeleton.cpp
// created: february 2019
// How to:
// - use 2 panels (one for controls, one for drawings)
// - manage basic events (so that controls impact drawings)
// with wxWidgets (3.0.2) 
// Author: Pascal Bertolino, UGA - GIPSA-lab laboratory, Grenoble - France
// Email pascal.bertolino@gipsa-lab.fr
// Web http://www.gipsa-lab.inpg.fr/~pascal.bertolino/
//
// tested with xWidget 3.0.2 under Linux and Windows 10
// Under Linux, compile then link as follows (with g++):
// g++ -c `wx-config --cxxflags` skeleton.cpp
// g++ -o skeleton skeleton.o `wx-config --libs`
//************************************************************************
//************************************************************************
// this skeleton includes 4 classes that are all derived from wxWidgets classes:
// the application class:	MyApp
// the main frame class:	MyFrame
// the left panel class:	MyControlPanel
// the right panel class:	MyDrawingPanel
//************************************************************************
//************************************************************************

#include "MyApp.hpp"

IMPLEMENT_APP(MyApp)


