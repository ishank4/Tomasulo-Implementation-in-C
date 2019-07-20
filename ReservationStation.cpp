//
// Created by aj on 3/8/16.
//

#include "ReservationStation.h"

ReservationStation::ReservationStation(){
    busy = false;
    op = 0;
    lat = 0;
    result = 0;
    resultReady = false;
    Qj = 1;
    Qk = 1;
    Vj = 0;
    Vk = 0;
    instNum = 100000;
    ISSUE_Lat = 0;
    WRITEBACK_Lat = 0;
}
ReservationStation::ReservationStation(int OP, int RSoperandAvailable){
    busy = false;
    op = OP;
    lat = 0;
    result = 0;
    resultReady = false;
    Qj = RSoperandAvailable;
    Qk = RSoperandAvailable;
    Vj = 0;
    Vk = 0;
    instNum = 100000;
    ISSUE_Lat = 0;
    WRITEBACK_Lat = 0;

}