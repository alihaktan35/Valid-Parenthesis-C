// Ali Haktan SIGIN - 21070001004

// NULL means '\0' (works fine with my IDE)

#include <stdio.h>
#include "linkedstack.h"

/**
* @brief Validates the arrangement of parenthesis withing a given string.
* @param str The string which is going to be validated.
* @return 1: Parenthesis arrangement is valid.
* @return 0: Parenthesis arrangement is not valid.
*/
int is_parentheses_valid(char* str) {
    /* TODO: Implement the valid parenthesis checking here. */

    LINKED_STACK stack = linked_stack_init();
    for (int i = 0; str[i] != NULL ; ++i)
    {
        // If there is an opening parenthesis in the string, push it to the stack.
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            linked_stack_push(stack, (void *) str[i]); // Char to Void casting
        }

        if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            // If string has a closing par. but the stack is empty, the result must be 0. (NOT balanced)
            if (linked_stack_is_empty(stack))
            {
                return 0;
            }

            // Controls for parenthesis if they match or not.
            if(linked_stack_top(stack) == '(' && str[i] == ')')
            {
                linked_stack_pop(stack);
            }

            if(linked_stack_top(stack) == '{' && str[i] == '}')
            {
                linked_stack_pop(stack);
            }

            if(linked_stack_top(stack) == '[' && str[i] == ']')
            {
                linked_stack_pop(stack);
            }
        }
    }
    // In the end, if the stack is empty, it means that all parenthesis are balanced. (return 1)
    return linked_stack_is_empty(stack);
}

// Do not change the test function.
void test_is_parenthesis_valid(char* str, int result) {
    printf("Test Case: %s\nResult must be: %d -> Result: %d\n\n", str, result, is_parentheses_valid(str));
}


int main() {
    // You can add more test cases.
    test_is_parenthesis_valid("while( i < 10 ){ // Do something; i++ }", 1);
    test_is_parenthesis_valid("2()23-2()24 C()MP2213 - }ata Structures", 0);
    test_is_parenthesis_valid("{[[/(/)/&/(&/)&]]}", 1);
    test_is_parenthesis_valid("(}", 0);
    test_is_parenthesis_valid("abcd", 1); // If there are no parenthesis at all, result must be 1. (balanced)
    return 0;
}