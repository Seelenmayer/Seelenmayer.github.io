/**
 * @file src.h
 * @author Clayton Seelenmayer
 * @date May 1st 2017
 * @brief Database functions header.
 */

#include <occi.h>
#include <string>
#ifndef SRC_H
#define SRC_H
using namespace std;
using namespace oracle::occi;

//Methods
void CreateDatabase(oracle::occi::Connection *Conn);
void DeleteDatabase(oracle::occi::Connection *Conn);
void InsertData(oracle::occi::Connection *Conn);
void Populate(oracle::occi::Connection *Conn);
void Invoice(oracle::occi::Connection *Conn);
void NetWeight(oracle::occi::Connection *Conn);
void GrossProffit(oracle::occi::Connection *Conn);
void Help();

int CountOrders(oracle::occi::Connection *Conn);
int CountProducts(oracle::occi::Connection *Conn);
string* FindProductNames(oracle::occi::Connection *Conn);
float* FindProductWeights(oracle::occi::Connection *Conn);
string Sanitize(string oldQuery);

#endif