#include <iostream>
// OT includes
#include <OT.hxx>
#include "ottemplate/MyClassImplementation.hxx"
#include "ottemplate/MyClass.hxx"

using namespace OT;
using namespace OTTEMPLATE;

int main(int argc, char **argv)
{
  MyClass a;
  std::cout << a << std::endl;
  return 0;
}

