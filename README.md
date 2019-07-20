# TomasuloAlgorithm
##C++ Tomasulo Algorithm Datapath/Simulator


___

###This program follows the algorithm as stated by the following sources
1. Computer Architecture : A Quantitative Approach (5th Edition) by Hennessy, John L., Patterson, David A.
2. https://en.wikipedia.org/wiki/Tomasulo_algorithm#Implementation_concepts
3. Dr. Chandra professor at Cal Poly Pomona





___

#INSTRUCTIONS FOR USE OF THIS PROGRAM:
**1. SETUP RESERVATION STATION ARCHITECTURE:**

 a. Define the constants for the # of Reservation Stations
     
     // NUMBER OF RESERVATION STATIONS
     const int Num_ADD_RS = 4;
     const int Num_MULT_RS = 2;
     const int Num_DIV_RS = 3;
 
 b. Define latency's
    
    // RESERVATION STATION LATENCY
    const int ADD_Lat = 4;
    const int MULT_Lat = 12;
    const int DIV_Lat = 38;
    // Datapath Latency
    const int ISSUE_Lat = 1;
    const int WRITEBACK_Lat = 1;
    
 c. Initialize Reservation Station Objects
 
     //// Input reservation station architecture
     ReservationStation
             ADD1(AddOp, OperandInit),
             ADD2(AddOp, OperandInit),
             ADD3(AddOp, OperandInit),
             ADD4(AddOp, OperandInit);
     ReservationStation
             MULT1(MultOp, OperandInit),
             MULT2(MultOp, OperandInit);
     ReservationStation
             DIV1(DivOp, OperandInit),
             DIV2(DivOp, OperandInit),
             DIV3(DivOp, OperandInit);
     
** Note: Currently only 12 registers are being used. To add more registers to the architecture
you must edit both the `RegisterStatus` objects and `Register` objects  **

    // Initialize register status objects
    RegisterStatus
            F0(RegStatusEmpty),F1(RegStatusEmpty),
            F2(RegStatusEmpty),F3(RegStatusEmpty),
            F4(RegStatusEmpty), F5(RegStatusEmpty),
            F6(RegStatusEmpty),F7(RegStatusEmpty),
            F8(RegStatusEmpty),F9(RegStatusEmpty),
            F10(RegStatusEmpty),F11(RegStatusEmpty),
            F12(RegStatusEmpty);
    // Pack register status objects into vector
    vector<RegisterStatus> RegisterStatus =
            {F0, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12};

    // Initialize register file vector
    vector<int> Register = {ZERO_REG,1,2,3,4,5,6,7,8,9,10,11,12};

**2. INITIALIZE PROGRAM:**

 a.Input the MIPS like instructions to your given program `Ex. ADD F1,F2,F3 // rd <- rs + rt`
  
    // Input program instructions
      Instruction
              //(rd,rs,rt,opcode)
              I0(1,2,3,AddOp),
              I1(4,1,5,AddOp),
              I2(6,7,8,SubOp),
              I3(9,4,10,MultOp),
              I4(11,12,6,DivOp),
              I5(8,1,5,MultOp),
              I6(7,2,3,MultOp);
 
**3. COMPILE AND RUN PROGRAM**

 a. compile using provided makefile with "make all" command
 
 b. run program
 
**4. OUTPUT:**
     
 a. Displays the register content of each clock cycle

     Register Content:
     5000 5 2 3 10 5 -1 6 25 100 10 -12 12
     
 b. Displays the timing diagram of the ISSUE EXECUTE WRITEBACK for each instruction at each clock cycle
 
     Inst      Issue     Execute   WB        SystemClock
                                                      47
      
     0         1         2-5         6         
     1         2         7-10        11        
     2         3         4-7         8         
     3         4         12-23        24        
     4         5         9-46        47        
     5         6         7-18        19        
     6         20        21-32        33        
 
___

 
# Here is the example program that has been tested
 
Instructions for provided example test program:
 
    I0: ADD     F1,F2,F3        
    I1: ADD     F4,F1,F5        // Data Dependency on I0
    I2: SUB     F6,F7,F8        
    I3: MULT    F9,F4,F10       // Data Dependency on I1
    I4: DIV     F11,F12,F6      // Data Dependency on I2
    I5: MULT    F8,F1,F5        // Data Dependency on I0
    I6: MULT    F7,F2,F3
 
Code for defining given example test program

    Instruction
                //(rd,rs,rt,opcode)
                I0(1,2,3,AddOp),
                I1(4,1,5,AddOp),
                I2(6,7,8,SubOp),
                I3(9,4,10,MultOp),
                I4(11,12,6,DivOp),
                I5(8,1,5,MultOp),
                I6(7,2,3,MultOp);
                
Initial Register File Values
    
    F0 = 5000 (This is zero for our purpose)
    F1 = 1
    F2 = 2
    F3 = 3
    F4 = 4
    F5 = 5
    F6 = 6
    F7 = 7 
    F8 = 8 
    F9 = 9
    F10 = 10
    F11 = 11
    F12 = 12
    
Code for defining given initial register file values

    // Initialize register file vector
    vector<int> Register = {ZERO_REG,1,2,3,4,5,6,7,8,9,10,11,12};
    
Expected Output w/ given reservation station architecture (This was checked by hand)

    Register Content:
    5000 5 2 3 10 5 -1 6 25 100 10 -12 12
    
    Inst      Issue     Execute   WB        SystemClock
                                                      47
      
     0         1         2-5         6         
     1         2         7-10        11        
     2         3         4-7         8         
     3         4         12-23        24        
     4         5         9-46        47        
     5         6         7-18        19        
     6         20        21-32        33    

**NOTE: By changing the number of reservation stations you can see the timing change.
This program has been tested with several different reservation station architectures**
