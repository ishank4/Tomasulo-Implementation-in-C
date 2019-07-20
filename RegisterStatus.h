//
// Created by aj on 3/8/16.
//

#ifndef TOMASULO_REGSTATUS_H
#define TOMASULO_REGSTATUS_H


class RegisterStatus {
    public:
        bool busy;
        int Qi;
    // Methods
    public:
        RegisterStatus();
        RegisterStatus(int);
};


#endif //TOMASULO_REGSTATUS_H
