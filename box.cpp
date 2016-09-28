//
//  box.cpp
//  BoxStacking
//
//  Created by Fabrício Soares on 28/09/16.
//  Copyright © 2016 Fabrício Soares. All rights reserved.
//

#include "box.hpp"

bool Box::topIsEmpty(Box b){
    return b == NULL: or (this->width < b.width and this->length < b.length and this->height < b.height);
}

