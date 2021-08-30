/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  This file is a solution to the Arithmetic Square Challenge
 *
 *        Created:  Thursday 19 August 2021
 *       Compiler:  gcc
 *
 *         Author:  Percy Knox
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Structure Decleration */
typedef struct _arithmetic_square_solutions_ arithmetic_square_t;

struct _arithmetic_square_solutions_ {
    int possible_solution;
    int num_progressions;
    arithmetic_square_t *next;
};

typedef struct _found_difference_ {
    bool found;
    int possible_solution;
} found_difference_t ;

/* Function Prototypes */
// found_difference_t * 
void
find_difference(found_difference_t *found_difference, int x, int y);

arithmetic_square_t *
add_possible_solution(arithmetic_square_t *ps_struct, int new_entry);

void
solve_square(arithmetic_square_t *ps_struct, int case_num, int default_cnt);

// void
// cleanup(arithmetic_square_t *ps_struct);

int main(void)
{
    int num_test_cases = 0;
    scanf("%d", &num_test_cases);

    int arithmetic_square[3][3];
    arithmetic_square_t *possible_solutions = NULL;
    arithmetic_square_t *ps_struct_temp;
    found_difference_t found_difference;
    int default_cnt = 0;

    for(int i = 0; i < num_test_cases; i++) {
        scanf("%d %d %d", &arithmetic_square[0][0], &arithmetic_square[0][1], &arithmetic_square[0][2]);
        scanf("%d %d", &arithmetic_square[1][0], &arithmetic_square[1][2]);
        scanf("%d %d %d", &arithmetic_square[2][0], &arithmetic_square[2][1], &arithmetic_square[2][2]);

        #ifdef DEBUG
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    printf("%d ", arithmetic_square[i][j]);
                }
                printf("\n");
            }
        #endif

        find_difference(&found_difference, arithmetic_square[0][0], arithmetic_square[0][2]);
        #ifdef DEBUG
            printf("find_difference returned: %s with %d\n", found_difference.found ? "true" : "false", found_difference.possible_solution);  
        #endif
        if (found_difference.possible_solution == arithmetic_square[0][1]) {
            // possible_solutions = add_possible_solution(possible_solutions, arithmetic_square[0][1]);
            default_cnt++;
        }
        
        find_difference(&found_difference, arithmetic_square[0][2], arithmetic_square[2][2]);
        #ifdef DEBUG
            printf("find_difference returned: %s with %d\n", found_difference.found ? "true" : "false", found_difference.possible_solution);
        #endif
        if (found_difference.possible_solution == arithmetic_square[1][2]){
            // possible_solutions = add_possible_solution(possible_solutions, arithmetic_square[1][2]);
            default_cnt++;
        }
            
        find_difference(&found_difference, arithmetic_square[2][0], arithmetic_square[2][2]);
        #ifdef DEBUG
            printf("find_difference returned: %s with %d\n", found_difference.found ? "true" : "false", found_difference.possible_solution);
        #endif
        if (found_difference.possible_solution == arithmetic_square[2][1]) {
            // possible_solutions = add_possible_solution(possible_solutions, arithmetic_square[2][1]);
            default_cnt++;
        }
        
        find_difference(&found_difference, arithmetic_square[0][0], arithmetic_square[2][0]);
        #ifdef DEBUG
            printf("find_difference returned: %s with %d\n", found_difference.found ? "true" : "false", found_difference.possible_solution);
        #endif
        if (found_difference.possible_solution == arithmetic_square[1][0]) {
            // possible_solutions = add_possible_solution(possible_solutions, arithmetic_square[1][0]);
            default_cnt++;
        }

        /* Looking for best center piece */
        #ifdef DEBUG
            printf("\nFinding the difference between %d at [0][0] and %d at [2][2]\n", arithmetic_square[0][0], arithmetic_square[2][2]);  
        #endif
        find_difference(&found_difference, arithmetic_square[0][0], arithmetic_square[2][2]);
        #ifdef DEBUG
            printf("find_difference returned: %s with %d\n", found_difference.found ? "true" : "false", found_difference.possible_solution);
        #endif
        if (found_difference.found == true) 
            possible_solutions = add_possible_solution(possible_solutions, found_difference.possible_solution);

        #ifdef DEBUG
            printf("\nFinding the difference between %d at [0][1] and %d at [2][1]\n", arithmetic_square[0][1], arithmetic_square[2][1]);  
        #endif
        find_difference(&found_difference, arithmetic_square[0][1], arithmetic_square[2][1]);
        #ifdef DEBUG
            printf("find_difference returned: %s with %d\n", found_difference.found ? "true" : "false", found_difference.possible_solution);
        #endif
        if (found_difference.found == true)
            possible_solutions = add_possible_solution(possible_solutions, found_difference.possible_solution);

        #ifdef DEBUG
            printf("\nFinding the difference between %d at [0][2] and %d at [2][0]\n", arithmetic_square[0][2], arithmetic_square[2][0]);  
        #endif
        find_difference(&found_difference, arithmetic_square[0][2], arithmetic_square[2][0]);
        #ifdef DEBUG
            printf("find_difference returned: %s with %d\n", found_difference.found ? "true" : "false", found_difference.possible_solution);
        #endif
        if (found_difference.found == true)
            possible_solutions = add_possible_solution(possible_solutions, found_difference.possible_solution);

        #ifdef DEBUG
            printf("\nFinding the difference between %d at [1][2] and %d at [1][0]\n", arithmetic_square[1][2], arithmetic_square[1][0]);  
        #endif
        find_difference(&found_difference, arithmetic_square[1][2], arithmetic_square[1][0]);
        #ifdef DEBUG
            printf("find_difference returned: %s with %d\n", found_difference.found ? "true" : "false", found_difference.possible_solution);
        #endif
        if (found_difference.found == true)
            possible_solutions = add_possible_solution(possible_solutions, found_difference.possible_solution);
        
        solve_square(possible_solutions, i, default_cnt);

        /* Cleanup Linked List and count */
        default_cnt = 0;

        ps_struct_temp = possible_solutions;
        while(possible_solutions != NULL) {
            possible_solutions = possible_solutions->next;
            free(ps_struct_temp);
            ps_struct_temp = possible_solutions;
        }
    }


    return EXIT_SUCCESS;
}

void find_difference(found_difference_t *fdiff_struct, int x, int y)
{
    if(x == y){
        fdiff_struct->found = true;
        fdiff_struct->possible_solution = x;
        return;
    }

    if(x > y){
        #ifdef DEBUG
            printf("The difference of (%d - %d): %d\n", x, y, x-y);  
        #endif
        if(((x - y) % 2) == 0) {
            fdiff_struct->found = true;
            fdiff_struct->possible_solution = x - ((x - y) / 2);
            return;
        } else {
            fdiff_struct->found = false;
            fdiff_struct->possible_solution = 0;
            return;
        }
    }

    #ifdef DEBUG
        printf("The difference of (%d - %d): %d\n", y, x, y-x);  
    #endif
    if(((y - x) % 2) == 0) {
        fdiff_struct->found = true;
        fdiff_struct->possible_solution = y - ((y - x) / 2);
        return;
    } else {
        fdiff_struct->found = false;
        fdiff_struct->possible_solution = 0;
        return;
    }

}

arithmetic_square_t *add_possible_solution(arithmetic_square_t *ps_struct, int new_entry)
{
    #ifdef DEBUG
        printf("Adding Possible New Entry: %d\n", new_entry);
    #endif

    if(ps_struct == NULL) {
        ps_struct = (arithmetic_square_t *) malloc(sizeof(arithmetic_square_t) * 1);
        ps_struct->possible_solution = new_entry;
        ps_struct->num_progressions = 1;
        ps_struct->next = NULL;

        return ps_struct;
    } 
    
    arithmetic_square_t *ps_struct_temp = ps_struct;
    arithmetic_square_t *ps_struct_temp_prev = NULL;

    while(ps_struct_temp != NULL) {
        if(new_entry == ps_struct_temp->possible_solution) {
            // Just increment the num_progressions and return
            ps_struct_temp->num_progressions++;
            #ifdef DEBUG
                printf("Updated num_progressions for entry (%d) to %d\n", new_entry, ps_struct_temp->num_progressions);  
            #endif
            return ps_struct;
        }

        ps_struct_temp_prev = ps_struct_temp; 
        ps_struct_temp = ps_struct_temp->next;
    }

    ps_struct_temp = (arithmetic_square_t *) malloc(sizeof(arithmetic_square_t) * 1);
    ps_struct_temp->possible_solution = new_entry;
    ps_struct_temp->num_progressions = 1;
    ps_struct_temp->next = NULL;

    ps_struct_temp_prev->next = ps_struct_temp;

    #ifdef DEBUG
        printf("Updated Possible Solution.\n");
        printf("Current Possible Solutions and their number of progressions:\n");

        arithmetic_square_t *temp = ps_struct;

        if(temp == NULL) {
            printf("Currently Empty.\n");
        } else {
            while(temp != NULL) {
                printf("Possible Solution: %d\t", temp->possible_solution);
                printf("Number of Progressions: %d\n", temp->num_progressions);

                temp = temp->next;
            }
        }
        printf("\n");
    #endif
    
    return ps_struct;
}

void solve_square(arithmetic_square_t *ps_struct, int case_num, int default_cnt)
{
    arithmetic_square_t *ps_struct_temp = ps_struct;

    int max_progressions = 0;

    while(ps_struct_temp != NULL) {
        if(ps_struct_temp->num_progressions > max_progressions) {
            max_progressions = ps_struct_temp->num_progressions;
        }

        ps_struct_temp = ps_struct_temp->next;
    }

    printf("Case #%d: %d\n", (case_num+1), (max_progressions + default_cnt));
}