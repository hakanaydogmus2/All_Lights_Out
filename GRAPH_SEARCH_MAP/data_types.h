#include<stdbool.h>
#ifndef DATA_TYPES_H
#define DATA_TYPES_H

// ==================== WRITE YOUR OPTIONAL DATA TYPES IF YOU NEED =============

#define GRID_ROWS 4  // Fixed grid size (4 rows)
#define GRID_COLS 4  // Fixed grid size (4 columns)

typedef bool Grid[GRID_ROWS][GRID_COLS];


// ====== WRITE YOUR COMPULSORY (BUT SPECIFIC TO THE PROBLEM) DATA TYPES =======


enum ACTIONS // All possible actions
{
    
    
    Toggle_0_0,
    Toggle_0_1,
    Toggle_0_2,
    Toggle_0_3,
    Toggle_1_0,
    Toggle_1_1,
    Toggle_1_2,
    Toggle_1_3,
    Toggle_2_0,
    Toggle_2_1,
    Toggle_2_2,
    Toggle_2_3,
    Toggle_3_0,
    Toggle_3_1,
    Toggle_3_2,
    Toggle_3_3
    
    
};

typedef struct State  
{
    Grid Lights; // The state of the grid
    float h_n;   // Heuristic function
      
}State;

// ================== YOU DO NOT NEED TO CHANGE THIS PART ======================

enum METHODS
{
	BreastFirstSearch = 1,   UniformCostSearch = 2,        DepthFirstSearch = 3,    
	DepthLimitedSearch= 4,   IterativeDeepeningSearch = 5, GreedySearch = 6,
    AStarSearch = 7, GeneralizedAStarSearch = 8  
};

// This struct is used to determine a new state and action in transition model
typedef struct Transition_Model
{
    State new_state;
    float step_cost;
}Transition_Model;

typedef struct Node
{
    State state;
    float path_cost;
    enum ACTIONS action; //The action applied to the parent to generate this node
    struct Node *parent;
    int Number_of_Child; // required for depth-first search algorithms
}Node;

typedef struct Queue  // Used for frontier
{
    Node *node;
    struct Queue *next;
}Queue;



#endif
