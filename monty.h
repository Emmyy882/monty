#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE 

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

extern int sq_flag;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);

char *parse_line(char *line);

instruct_func get_op_func(char *str);

void read_file(char *filename, stack_t **stack);

void _pall(stack_t **stack, unsigned int line_num);
void _swap(stack_t **stack, unsigned int line_num);
void _nop(stack_t **stack, unsigned int line_num);
void _pchar(stack_t **stack, unsigned int line_num);
void _pint(stack_t **stack, unsigned int line_num);
void _push(stack_t **stack, unsigned int line_num);
void _pop(stack_t **stack, unsigned int line_num);
void _add(stack_t **stack, unsigned int line_num);
void _sub(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_num);
void _div(stack_t **stack, unsigned int line_num);

void _pstr(stack_t **stack, unsigned int line_num);

void _mod(stack_t **stack, unsigned int line_num);

void _rotl(stack_t **stack, unsigned int line_num);

void _rotr(stack_t **stack, unsigned int line_num);

void _queue(stack_t **stack, unsigned int line_num);

void _stack(stack_t **stack, unsigned int line_num);

stack_t *add_dnodeint_end(stack_t **head, const int n);

stack_t *add_dnodeint(stack_t **head, const int n);

void free_dlistint(stack_t *head);

int delete_dnodeint_at_index(stack_t **head, unsigned int index);

void error_exit(stack_t **stack);

int isnumber(char *str);

#endif
