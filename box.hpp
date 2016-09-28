//
//  box.hpp
//  BoxStacking
//
//  Created by Fabrício Soares on 28/09/16.
//  Copyright © 2016 Fabrício Soares. All rights reserved.
//

#ifndef box_hpp
#define box_hpp

#include <iostream>

class Box {
    int width, length, height;
    
public:
    Box(int w, int l, int h){
        width = w;
        length = l;
        height = h;
    }
    
    bool topIsEmpty(Box b);
    
    operator std::string() const{
        return "(" + std::to_string(width) + ", " + std::to_string(length) + ", " + std::to_string(height) + ")";
    }
    
};

#endif /* box_hpp */
