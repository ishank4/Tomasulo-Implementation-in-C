//
// Created by aj on 3/8/16.
//

#ifndef TOMASULO_RS_H
#define TOMASULO_RS_H


class ReservationStation {
    public:
        bool busy;
        int Qj;
        int Qk;
        int Vj;
        int Vk;
        int lat;
        int op;
        int result;
        bool resultReady;
        int instNum;
        int ISSUE_Lat;
        int WRITEBACK_Lat;

    //**** Methods
    public:
        ReservationStation();
        ReservationStation(int, int);
};


#endif //TOMASULO_RS_H
