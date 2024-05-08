/* 
    These functions are compulsory for search algorithms but they are specific
    to problems. More clearly, you must must update their blocks but do not change
    their input and output parameters.
    
    Also, you can add new functions at the end of file by declaring them in GRAPH_SEARCH.h
*/

#include "GRAPH_SEARCH.h"
#include "data_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//______________________________________________________________________________
State* Create_State()
{
    srand(time(NULL));
	State *state = (State*)malloc(sizeof(State));
    if(state==NULL)
    	Warning_Memory_Allocation(); 
   
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            state->Lights[i][j] = rand()%2;
        }
    }
    printf("Initial State: \n");
    Print_State(state);
   	       
    return state;    
}

//______________________________________________________________________________
void Print_State(const State *const state)
{
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            printf("%d ", state->Lights[i][j]);
        }
        printf("\n");
    }
}

void ApplyAction(const enum ACTIONS action, State *state){
    switch (action){
        case Toggle_0_0:
            StateValueChanger(state, 0, 0);
            break;
        case Toggle_0_1:
            StateValueChanger(state, 0, 1);
            break;
        case Toggle_0_2:
            StateValueChanger(state, 0, 2);
            break;
        case Toggle_0_3:
            StateValueChanger(state, 0, 3);
            break;
        case Toggle_1_0:
            StateValueChanger(state, 1, 0);
            break;
        case Toggle_1_1:    
            StateValueChanger(state, 1, 1);
            break;
        case Toggle_1_2:
            StateValueChanger(state, 1, 2);
            break;
        case Toggle_1_3:
            StateValueChanger(state, 1, 3);
            break;
        case Toggle_2_0:
            StateValueChanger(state, 2, 0);
            break;
        case Toggle_2_1:
            StateValueChanger(state, 2, 1);
            break;
        case Toggle_2_2:
            StateValueChanger(state, 2, 2);
            break;
        case Toggle_2_3:
            StateValueChanger(state, 2, 3);
            break;
        case Toggle_3_0:
            StateValueChanger(state, 3, 0);
            break;
        case Toggle_3_1:
            StateValueChanger(state, 3, 1);
            break;
        case Toggle_3_2: 
            StateValueChanger(state, 3, 2);
            break;
        case Toggle_3_3:
            StateValueChanger(state, 3, 3);
            break;
        
    }
}
//______________________________________________________________________________
void Print_Action(const enum ACTIONS action)
{
   switch(action){
        case Toggle_0_0: printf("Toggle_0_0"); break;
        case Toggle_0_1: printf("Toggle_0_1"); break;
        case Toggle_0_2: printf("Toggle_0_2"); break;
        case Toggle_0_3: printf("Toggle_0_3"); break;
        case Toggle_1_0: printf("Toggle_1_0"); break;
        case Toggle_1_1: printf("Toggle_1_1"); break;
        case Toggle_1_2: printf("Toggle_1_2"); break;
        case Toggle_1_3: printf("Toggle_1_3"); break;
        case Toggle_2_0: printf("Toggle_2_0"); break;
        case Toggle_2_1: printf("Toggle_2_1"); break;
        case Toggle_2_2: printf("Toggle_2_2"); break;
        case Toggle_2_3: printf("Toggle_2_3"); break;
        case Toggle_3_0: printf("Toggle_3_0"); break;
        case Toggle_3_1: printf("Toggle_3_1"); break;
        case Toggle_3_2: printf("Toggle_3_2"); break;
        case Toggle_3_3: printf("Toggle_3_3"); break; 
    }        
}

//______________________________________________________________________________
int Result(const State *const parent_state, const enum ACTIONS action, Transition_Model *const trans_model)
{
    State new_state;
    State temp_state = *parent_state;
	ApplyAction(action, &temp_state);
    new_state = temp_state;
	     //    A    B    C    D    E    F    G    H    I    L    M    N    O    P    R    S    T    U    V    Z       
	           
         /*if(PATH_COSTS[parent_state->Lights[action]<=0) 
              return FALSE;
         else{
              new_state.city = action;
              trans_model->new_state = new_state;
              trans_model->step_cost = PATH_COSTS[parent_state->city][action]; 
         }     
         return TRUE; */
    trans_model->new_state = new_state;
    trans_model->step_cost = 1;

    return 1;

                                                     
}

//______________________________________________________________________________
float Compute_Heuristic_Function(const State *const state, const State *const goal)
{
    float count = 0.0;
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            if(state->Lights[i][j] != goal->Lights[i][j]){
                count++;
            }
        }
    }
    return count;

      /*
      const float SLD[CITY_NUMBER][CITY_NUMBER] =   // CALCULATED ROUGHLY!!!
        {   {  0, 366, 300, 220, 590, 235, 430, 535, 420, 168, 225, 355, 110, 290, 185, 130, 105, 435, 470,  67},  // Arad
            {366,   0, 160, 242, 161, 176,  77, 151, 226, 244, 241, 234, 380, 100, 193, 253, 329,  80, 199, 374},  // Bucharest
			{300, 160,   0, 102, 325, 210, 142, 325, 368, 145, 110, 388, 355, 133, 138, 190, 220, 220, 385, 330},  // Craiova
			{220, 242, 102,   0, 390, 245, 240, 380, 400, 100,  70, 460, 310, 190, 155, 205, 150, 302, 410, 265},  // Drobeta
			{590, 161, 325, 390,   0, 325, 205,  80, 245, 400, 375, 350, 595, 265, 340, 395, 555, 130, 260, 593},  // Eforie
			{235, 176, 210, 245, 325,   0, 200, 251, 180, 175, 185, 135, 220, 102,  85,  95, 255, 195, 200, 227},  // F 
			{430,  77, 142, 240, 205, 200,   0, 213, 297, 245, 280, 285, 410, 125, 225, 285, 330, 120, 230, 520},  // G
			{535, 151, 325, 380,  80, 251, 213,   0, 205, 370, 370, 260, 535, 220, 345, 365, 495,  92, 130, 535},  // H
			{440, 226, 368, 400, 245, 180, 297, 205,   0, 330, 350,  80, 365, 250, 260, 280, 450, 190,  85, 390},  // I
			{168, 244, 145, 100, 400, 175, 245, 370, 330,   0,  66, 290, 240, 140,  95, 135, 100, 285, 360, 205},  // L 
			{225, 241, 110,  70, 375, 185, 280, 370, 350,  66,   0, 305, 300, 140, 120, 175, 130, 280, 370, 260},  // M
			{355, 234, 388, 460, 350, 135, 285, 260,  80, 290, 305,   0, 273, 220, 260, 250, 330, 235, 155, 310},  // N
			{110, 380, 355, 310, 595, 220, 410, 535, 365, 240, 300, 273,   0, 305, 200, 140, 213, 415, 435,  66},  // O
			{290, 100, 133, 190, 265, 102, 125, 220, 250, 140, 140, 220, 305,   0, 115, 150, 230, 140, 185, 297},  // P
			{185, 193, 138, 155, 340,  85, 225, 345, 260,  95, 120, 260, 200, 115,   0,  75, 150, 230, 290, 193},  // R
			{130, 253, 190, 205, 395,  95, 285, 365, 280, 135, 175, 250, 140, 150,  75,   0, 137, 300, 330, 135},  // S
			{105, 329, 220, 150, 555, 255, 330, 495, 450, 100, 130, 330, 213, 230, 150, 137,   0, 380, 455, 155},  // T
			{435,  80, 220, 302, 130, 195, 120,  92, 190, 285, 280, 235, 415, 140, 230, 300, 380,   0, 132, 425},  // U
			{470, 199, 385, 410, 260, 200, 230, 130,  85, 360, 370, 155, 435, 185, 290, 330, 455, 132,   0, 452},  // V
			{ 67, 374, 330, 265, 593, 227, 520, 535, 390, 205, 260, 310,  66, 297, 193, 135, 155, 425, 452,   0}   // Z
		};
	     //    A    B    C    D    E    F    G    H    I    L    M    N    O    P    R    S    T    U    V    Z   
         
        return SLD[state->city][goal->city];
        */   
}

//_______________ Update if your goal state is not determined initially ___________________________________
int Goal_Test(const State *const state, const State *const goal_state)
{
	if(PREDETERMINED_GOAL_STATE)	
		return Compare_States(state, goal_state); 
	else
		return 1;
}

void StateValueChanger(State *state, int i, int j){
   
  state->Lights[i][j] = !state->Lights[i][j];
  if (i > 0) {
    state->Lights[i - 1][j] = !state->Lights[i - 1][j];
  }

  if (i < 3) {
    state->Lights[i + 1][j] = !state->Lights[i + 1][j];
  }

  if (j > 0) {
    state->Lights[i][j - 1] = !state->Lights[i][j - 1];
  }
  if (j < 3) {
    state->Lights[i][j + 1] = !state->Lights[i][j + 1];
  }
}
 State* createGoalState(){

    int rowSize = 4;
    int colSize = 4;
	State *state = (State*)malloc(sizeof(State));
    if(state==NULL)
    	Warning_Memory_Allocation(); 
   
    for(int i = 0; i<rowSize; i++){
        for(int j = 0; j<colSize; j++){
            state->Lights[i][j] = false;
        }
    }
    return state;
 }
// ==================== WRITE YOUR OPTIONAL FUNCTIONS (IF REQUIRED) ==========================
 