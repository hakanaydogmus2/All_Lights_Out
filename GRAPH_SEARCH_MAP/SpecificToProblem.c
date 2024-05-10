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
#include <stdbool.h>


//______________________________________________________________________________
State* Create_State()
{
    srand(time(NULL));
	State *state = (State*)malloc(sizeof(State));
    if(state==NULL)
    	Warning_Memory_Allocation(); 
    
    int rowSize = 4;
    int colSize = 4;

    bool lights[4][4] = {{1, 1, 1, 1},
                        {1, 0, 0, 1},
                        {0, 0, 1, 0},
                        {0, 1, 1, 1}};
    
    for(int i = 0; i<rowSize; i++){
        for(int j = 0; j<colSize; j++){
            //state->Lights[i][j] = rand() % 2;
            //state->Lights[i][j] = false;
            state->Lights[i][j] = lights[i][j];
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
    State parState = *parent_state;
	ApplyAction(action, &temp_state);
    new_state = temp_state; 
    //new_state = temp_state;

    //trans_model->new_state = new_state;
    //trans_model->step_cost = 1; 
    
    
    int pathCost = CountActiveLights(&temp_state) - CountActiveLights(&parState);
    trans_model->step_cost = pathCost; 
    trans_model->new_state = new_state;
    return 1;
    
    //new_state = temp_state;
	     //    A    B    C    D    E    F    G    H    I    L    M    N    O    P    R    S    T    U    V    Z       
	           
         /*if(PATH_COSTS[parent_state->Lights[action]<=0) 
              return FALSE;
         else{
              new_state.city = action;
              trans_model->new_state = new_state;
              trans_model->step_cost = PATH_COSTS[parent_state->city][action]; 
         }     
         return TRUE; */
    
    //trans_model->step_cost = 1;

    

                                                     
}

//______________________________________________________________________________
int Compute_Heuristic_Function(const State *const state, const State *const goal)
{
    int state_h_f = CountPassiveLights(state);
    int goal_hf = CountPassiveLights(goal);
    return goal_hf- state_h_f;
   
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
    printf("Goal State: \n");
    Print_State(state);
    return state;
 }

 int CountPassiveLights(const State *const state){
     int count = 0;
     int rowSize = 4;
     int colSize = 4;
     
     for(int i = 0; i<rowSize; i++){
        for(int j = 0; j<colSize; j++){
            if(state->Lights[i][j] == 0){
                count++;
            }
        }
    }
    return count;
 }

 int CountActiveLights(const State *const state){
     int count = 0;
     int rowSize = 4;
     int colSize = 4;
     
     for(int i = 0; i<rowSize; i++){
        for(int j = 0; j<colSize; j++){
            if(state->Lights[i][j] == 1){
                count++;
            }
        }
    }
    return count;
 }
// ==================== WRITE YOUR OPTIONAL FUNCTIONS (IF REQUIRED) ==========================
 