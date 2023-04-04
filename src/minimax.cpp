#include "minimax.h"
#include "eval.h"
#include "board.h"
#include <limits.h>
#include <algorithm>

#define CUTOFF_DEPTH 7

using namespace std;

Node *minimax(Root root)
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

        float move_score = alphabeta(root, i);
        // Make this move the choice if it is highest for MAX, or lowest for MIN
        if ((root->turn && move_score > best_eval) || (!root->turn && move_score < best_eval))
        {
            best_move = i;
            best_eval = move_score;
        }
    }
}

float alphabeta(Root root, int depth)
{
    // Decide whether to cutoff or expand
    if (depth = 0 || depth == CUTOFF_DEPTH)
    {
        return eval(*root);
    }
    else
    {
        generateChildren(root);
    }

    if (root->turn)
    {
        float value = INT_MIN;
        for (int i = 0; i < root->n; i++)
        {
            value = max(value, alphabeta(root->children[i], depth + 1));
            if (value > root->data.beta)
            {
                break; // Beta cutoff
            }
            root->data.alpha = max(root->data.alpha, value);
        }
        return value;
    }
    else
    {
        float value = INT_MAX;
        for (int i = 0; i < root->n; i++)
        {
            value = min(value, alphabeta(root->children[i], depth + 1));
            if (value > root->data.alpha)
            {
                break; // Alpha cutoff
            }
            root->data.beta = min(root->data.beta, value);
        }
        return value;
    }
}
