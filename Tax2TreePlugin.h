#ifndef TAX2TREEPLUGIN_H
#define TAX2TREEPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>

class Tax2TreePlugin : public Plugin
{
public: 
 std::string toString() {return "Tax2Tree";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::map<std::string, std::string> parameters;
};

#endif
