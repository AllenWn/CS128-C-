#include "space.hpp"
#include <iostream>



char Space::GetSpace() const { 
    return space_;
}
 void Space::SetSpace(char icon) {
    if (icon == 'X' || icon == '0' || icon == 'space') {
        space_ = icon;
    }
 }
