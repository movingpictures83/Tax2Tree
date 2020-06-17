#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "Tax2TreePlugin.h"

void Tax2TreePlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile, std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
}

void Tax2TreePlugin::run() {}

void Tax2TreePlugin::output(std::string file) {
// t2t decorate -t test_consistency.ntree -m test_consistency.cons -o tree.txt
 std::string outputfile = file;
 std::string myCommand = "";
myCommand += "t2t";
myCommand += " decorate -t ";
myCommand += parameters["taxonomy"];
myCommand += " -m ";
myCommand += parameters["consensus"];
myCommand += " -o ";
myCommand += outputfile;
std::cout<<myCommand<<std::endl;
 system(myCommand.c_str());
}

PluginProxy<Tax2TreePlugin> Tax2TreePluginProxy = PluginProxy<Tax2TreePlugin>("Tax2Tree", PluginManager::getInstance());
