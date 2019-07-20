//
// Created by aj on 3/8/16.
//

#include "RegisterStatus.h"

RegisterStatus::RegisterStatus(){
    busy = false;
    Qi = 0;
}
RegisterStatus::RegisterStatus(int RegStatusEmpty) {
    Qi = RegStatusEmpty;
}
