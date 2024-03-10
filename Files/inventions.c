#include "push_swap.h"

void sort_node_three(Node_Stack **stack_a, Node_Stack **stack_b)
{
    Node_Stack *current;
    if (*stack_a == NULL)
        return;
    while (stacksize(stack_a))   
    {
        current = *stack_a;

        update_index(stack_b);
        update_index(stack_a);
        get_node_cost(stack_a, stack_b, 'a');

        while(current->index != catch_cost(stack_a))
            current=current->next;

        //printf("Number: %ld, CMedian: %d, CIndex: %d, Target: %d, TMedian: %d, TIndex: %d, BHead:%ld, Cost: %d,  \n", current->number, current->median, current->index, current->target, target->median, target->index, target->number, current->cost);
        if(!current->median && !current->target_node->median)
        {
           while(current->index > 0 && current->target_node->index > 0)
            {
                //printf("I'm here CIndex: %d,TIndex: %d,CNumber: %ld,TNumber: %ld,CTarget: %d\n", current->index, current->target_node->index, current->number, current->target_node->number, current->target);
                rr(stack_a, stack_b);
            }
        }
        if(current->median && current->target_node->median)
        {
            while(current->index > 0 && current->target_node->index > 0)
            {
                //printf("I'm here CIndex: %d,TIndex: %d,CNumber: %ld,TNumber: %ld,CTarget: %d\n", current->index, current->target_node->index, current->number, current->target_node->number, current->target);
                rrr(stack_a, stack_b);
            }
        }
        //print_info(stack_a);
        //print_info(stack_b);
        get_node_push(stack_a, &current, 'a');
        get_node_push(stack_b, &current->target_node, 'b');
        pb(stack_a, stack_b);
    }
}

void get_node_cost(Node_Stack **stack_a, Node_Stack **stack_b, char stack)
{
    Node_Stack *current;
    int size;
    int tsize;
    if (stack == 'a')
    {
        current = *stack_a;
        size = stacksize(stack_a);
        tsize = stacksize(stack_b);
        //printf("Calculating costs for stack A:\n");
    }
    else
    {
        current = *stack_b;
        size = stacksize(stack_b);
        tsize = stacksize(stack_a);
       //printf("Calculating costs for stack B:\n");
    }

    while (current != NULL)
    {
        if (stack == 'a')
            current->target_node = get_node_b(stack_b, current->number);
        else
            current->target_node = get_node_a(stack_a, current->number);

        if (current->target_node != NULL)
        {
            current->target = current->target_node->number;
            current->cost = get_more_moves(current->index, current->median, current->target_node->index, current->target_node->median, size, tsize);

/*                 printf("Node Cost for Number: %ld, Index: %d, Target: %ld - %d with cost %d\n", 
                current->number, current->index, current->target_node->number, current->target, current->cost); */
        }
       else
        {
            printf("Warning: Target node not found for Number: %ld\n", current->number);
            // Handle the case when the target node is not found (e.g., set default values)
        }

        current = current->next;
    }

    //printf("Costs Updated\n");
}


Node_Stack* get_node_b(Node_Stack **stack_b, int number)
{
    Node_Stack *top;
    Node_Stack *target_node;
    int target = INT_MIN;
    target_node = NULL;

    top = *stack_b;
    while (top)
    {
        if (top->number < number && top->number > target)
        {
            target_node = top;
            target = top->number;
        }
        top = top->next;
    }

    if (target_node == NULL)
        target_node = get_biggest_node(stack_b);

    return target_node;
}

Node_Stack* get_node_a(Node_Stack **stack_a, int number)
{
    Node_Stack *top;
    Node_Stack *target_node;
    int target = INT_MAX;
    target_node = NULL;

    top = *stack_a;
    while (top)
    {
        if (top->number > number && top->number < target)
        {
            target_node = top;
            target = top->number;
        }
        top = top->next;
    }

    if (target_node == NULL)
        target_node = get_lowest_node(stack_a);

    return target_node;
}

Node_Stack* get_lowest_node(Node_Stack **stack)
{
    Node_Stack *current;
    Node_Stack *lowest_node;
    int lowest = INT_MAX;
    lowest_node = NULL;

    current = *stack;
    while (current)
    {
        if (current->number < lowest)
        {
            lowest = current->number;
            lowest_node = current;
        }
        current = current->next;
    }

    return lowest_node;
}

Node_Stack* get_biggest_node(Node_Stack **stack)
{
    Node_Stack *current;
    Node_Stack *biggest_node;
    int biggest = INT_MIN;
    biggest_node = NULL;

    current = *stack;
    while (current)
    {
        if (current->number > biggest)
        {
            biggest = current->number;
            biggest_node = current;
        }
        current = current->next;
    }

    return biggest_node;
}


int get_more_moves(int index, bool median, int target_index, bool tmedian, int size_a, int size_b)
{
if(median)
        index = size_a - 1 - index;
if(tmedian)
        target_index = size_b - 1 - target_index;
//printf("Index: %d, Median: %d, Target Index: %d, Target Median: %d, Size A: %d, Size B: %d\n", index, median, target_index, tmedian, size_a, size_b);
if((median && tmedian) || (!median && !tmedian))
    {
        if(index > target_index)
            return(index);
        else
            return(target_index);
    }
else
        return(index + target_index);
}
    
void get_node_push(Node_Stack **stack, Node_Stack **target_node, char stack_name)
{
    Node_Stack *current;
    Node_Stack *target;
    int debug = 0;
    current = *stack;
    target = *target_node;
    
    while(current != target)
    {
        //printf("debug: %d, %ld, %ld, %d, %c\n", current->index, current->number, target->number, target->index, stack_name);
        if(stack_name == 'a')
        {
            if(!target->median)
                ra(stack);
            else
                rra(stack);
        }
        if(stack_name == 'b')
        {   
            if(!target->median)
                rb(stack);
            else
                rrb(stack);
         }
         debug++;
         current = *stack;
         /* if(debug > 20)
         {
            free_stack(stack);
            exit(0);
         } */
    }
}


void    return_to_node(Node_Stack **stack_a, Node_Stack **stack_b)
{
    Node_Stack *current;
    while (stacksize(stack_b) > 0)
    {
        current = *stack_b;
        
        update_index(stack_b);
        update_index(stack_a);
        get_node_cost(stack_a, stack_b, 'b');
        
        while(current->index != catch_cost(stack_b))
            current=current->next;

        //printf("Number: %ld, CMedian: %d, CIndex: %d, Target: %d, TMedian: %d, TIndex: %d, BHead:%ld, Cost: %d,  \n", current->number, current->median, current->index, current->target, target->median, target->index, target->number, current->cost);
        if(!current->median && !current->target_node->median)
        {
           while(current->index > 0 && current->target_node->index > 0)
            {
                //printf("I'm here CIndex: %d,TIndex: %d,CNumber: %ld,TNumber: %ld,CTarget: %d\n", current->index, current->target_node->index, current->number, current->target_node->number, current->target);
                rr(stack_a, stack_b);
            }
        }
        else if(current->median && current->target_node->median)
        {
            while(current->index > 0 && current->target_node->index > 0)
            {
                //printf("I'm here CIndex: %d,TIndex: %d,CNumber: %ld,TNumber: %ld,CTarget: %d\n", current->index, current->target_node->index, current->number, current->target_node->number, current->target);
                rrr(stack_a, stack_b);
            }
        }
        //print_info(stack_a);
        //print_info(stack_b);
        get_node_push(stack_b, &current, 'b');
        get_node_push(stack_a, &current->target_node, 'a');
        pa(stack_b, stack_a);
    }
}

void get_it_together(Node_Stack **stack)
{
    Node_Stack *min;

    if (*stack == NULL || stack_sorted(*stack))
        return;

    min = get_lowest_node(stack);

    if (min == NULL)
        return;
    while (!stack_sorted(*stack) && *stack != min)
    {
        if (!min->median)
            ra(stack);
        else
            rra(stack);
    }
}
