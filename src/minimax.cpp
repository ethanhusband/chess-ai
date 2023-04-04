#include "minimax.h"
#include <limits.h>

#define CUTOFF_DEPTH 7

Node *minimax(Root root, Evalfunc eval)
{
    // We basically want to decide which move we should choose of the options, depending on whether we are MIN or MAX
    generateChildren(root);

    float best_eval = 0;
    int best_move = -1;
    // Start the best_eval in the loss state for whoever the turn is for - so we can use max() and min() functions
    if (root->turn)
    {
        best_eval = INT_MIN;
    }
    else
    {
        best_eval = INT_MAX;
    }

    for (int i = 0; i < root->n; i++)
    {

        float move_score = score_root_move(root, i, eval);
        // Make this move the choice if it is highest for MAX, or lowest for MIN
        if ((root->turn && move_score > best_eval) || (!root->turn && move_score < best_eval))
        {
            best_move = i;
            best_eval = move_score;
        }
    }
}

float score_root_move(Root root, int childindex, Evalfunc eval)
{
    // We want to recursively generate the tree for one of the move options at the root, as to derive it's score

    Node *root_option = root->children[childindex];
    if (root->turn)
    {
        // It is the turn of MAX - so every option must be a MIN node and be scored as such
        float move_score = score_min_node(state, move_board, 1.0f);
    }
    else
    {
        // It is the turn of MIN - every option is a MAX node
        float move_score = score_max_node()
    }

    return move_score;
}

static float score_max_node(Node *node, int depth, Evalfunc eval)
{
    if (depth == CUTOFF_DEPTH)
        return eval(*node);
    // Get the node score for a maximising node by propagating the maximal child node
    float highest_utility = 0.0f;
    state.curdepth++;
    for (int move = 0; move < MOVE_DIRECTIONS; ++move)
    {
        state.moves_evaled++;
        board_t newboard = play_move(move, board);

        if (board != newboard)
        {
            highest_utility = std::max(highest_utility, score_chance_node(state, newboard, cprob));
        }
    }
    state.curdepth--;
    return highest_utility;
}

Node *generateChildren(Node *node)
{
    // Identify each piece in the board which is that of the current turn
    // Generate moves for that piece via a map which returns a set of functions for a given piece
}
