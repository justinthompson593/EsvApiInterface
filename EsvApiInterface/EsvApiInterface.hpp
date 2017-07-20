//
//  EsvApiInterface.hpp
//  EsvApiInterface
//
//  Created by Justin Thompson on 7/19/17.
//  Copyright © 2017 Justin Thompson. All rights reserved.
//

#ifndef EsvApiInterface_hpp
#define EsvApiInterface_hpp

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class EsvApiInterface {
	
	
public:
	EsvApiInterface();
	
	string url = "http://www.esvapi.org/v2/rest/";
	string function = "passageQuery";				// passageQuery, query, verse
	
	
	
	
	
	
};



#endif /* EsvApiInterface_hpp */


